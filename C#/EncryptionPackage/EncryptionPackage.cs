// Importing the required namespaces
using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Security;
using System.Diagnostics;

namespace EncryptionPackage
{
    public enum EncryptionAlgorithms
    {
        AES,
        ChaCha20,
        Camellia,
        Twofish,
        Blowfish,
        TripleDES,
    };

    public class EncryptionAlgorithmsDetails
    {
        public EncryptionAlgorithmsDetails(string Name, byte BlockSize, short MaxKeyLength, byte IV_Length)
        {
            this.Name = Name;
            this.BlockSize = BlockSize;
            this.MaxKeyLength = MaxKeyLength;
            this.IV_Length = IV_Length;
        }

        public string Name { get; }
        public byte BlockSize { get; }
        public short MaxKeyLength { get; }
        public byte IV_Length { get; }
    }

    public class EncryptionParameters
    {
        public EncryptionAlgorithms EncryptionAlgorithm { get; set; }
        public bool IfEncrypt { get; set; }
        public byte[] Key { get; set; }
        public short KeyLength { get; set; }
        public byte[] ExtraEntropy { get; set; }
    }

    public class PathParameters
    {
        public string Path { get; set; }
        public bool IfUsePrefix { get; set; }
        public bool IfDeleteOriginalPath { get; set; }
    }

    public interface IEncryptionService
    {
        void EncryptFile(PathParameters pathParameters);
        void DecryptFile(PathParameters pathParameters);
    }

    // Class representing an encryption package
    public class EncryptionService : IEncryptionService
    {
        private readonly SecureRandom randomGenerator = new SecureRandom();
        private Dictionary<EncryptionAlgorithms, EncryptionAlgorithmsDetails> encryptionAlgorithmMap;
        private IBufferedCipher cipher;
        private EncryptionParameters encryptionParameters;

        private class HeaderData
        {
            public byte EncryptionAlgorithm;
            public bool FileEncryptionKeyLength; // false = 128, true = 256
            public byte[] KeyVerifySalt = new byte[32];
            public byte[] KeyDerivationSalt = new byte[32];
            public byte[] KeyVerifyHash = new byte[32];
            public byte[] IV = new byte[8];
            public byte[] EncryptedFileEncryptionKey;

            // Override the ToString method to provide a string representation of the header data
            public override string ToString()
            {
                return
                    $"KeyVerifySalt: {Convert.ToBase64String(KeyVerifySalt)}\n" +
                    $"KeyVerifyHash: {Convert.ToBase64String(KeyVerifyHash)}\n" +
                    $"KeyDerivationSalt: {Convert.ToBase64String(KeyDerivationSalt)}\n" +
                    $"IV: {Convert.ToBase64String(IV)}\n" +
                    $"EncryptedFileEncryptionKey: {Convert.ToBase64String(EncryptedFileEncryptionKey)}\n";
            }
        }

        public EncryptionService(EncryptionParameters encryptionParameters)
        {
            this.encryptionParameters = encryptionParameters;
            encryptionAlgorithmMap = new Dictionary<EncryptionAlgorithms, EncryptionAlgorithmsDetails>()
            {
                [EncryptionAlgorithms.AES] = new EncryptionAlgorithmsDetails("AES/CFB/PKCS7Padding", 128, 256, 128),
                [EncryptionAlgorithms.ChaCha20] = new EncryptionAlgorithmsDetails("ChaCha20", 1, 256, 96),
                [EncryptionAlgorithms.Camellia] = new EncryptionAlgorithmsDetails("Camellia/CFB/PKCS7Padding", 128, 256, 128),
                [EncryptionAlgorithms.Twofish] = new EncryptionAlgorithmsDetails("Twofish/CFB/PKCS7Padding", 128, 256, 128),
                [EncryptionAlgorithms.Blowfish] = new EncryptionAlgorithmsDetails("Blowfish/CFB/PKCS7Padding", 128, 256, 64),
                [EncryptionAlgorithms.TripleDES] = new EncryptionAlgorithmsDetails("DESede/CFB/PKCS7Padding", 64, 192, 64),
            };
            randomGenerator.SetSeed(encryptionParameters.ExtraEntropy);
            EncryptionParametersCheck(encryptionParameters);
        }

        private void EncryptionParametersCheck(EncryptionParameters parameters)
        {
            if (encryptionAlgorithmMap.ContainsKey(parameters.EncryptionAlgorithm) == false && parameters.IfEncrypt)
            {
                throw new ArgumentException("Encryption algorithm not specified.");
            }
            if (parameters.Key == null || parameters.Key.Length == 0)
            {
                throw new ArgumentNullException(nameof(parameters.Key));
            }
            if (parameters.KeyLength != (short)128 && parameters.KeyLength != (short)256)
            {
                throw new ArgumentException("Invalid key length", nameof(parameters.Key));
            }
        }

        private void PathParametersCheck(PathParameters parameters)
        {
            if (parameters == null)
            {
                throw new ArgumentNullException(nameof(parameters));
            }
            if (string.IsNullOrEmpty(parameters.Path))
            {
                throw new ArgumentNullException(nameof(parameters.Path));
            }
        }

        void IEncryptionService.EncryptFile(PathParameters parameters)
        {
            PathParametersCheck(parameters);
            cipher = CipherUtilities.GetCipher(encryptionAlgorithmMap[encryptionParameters.EncryptionAlgorithm].Name);

            string encryptionFilePath = GetEncryptionPath(parameters);

            byte[] fileEncryptionKey = null;
            byte[] fileEncryptionIV = null;
            HeaderData headerData = GenerateHeaderData(ref fileEncryptionKey, ref fileEncryptionIV);
            byte[] writtenHeader = CreateWrittenHeader(headerData);
            WriteHeader(writtenHeader, encryptionFilePath);

            Debug.WriteLine($"File Encryption Key: {Convert.ToBase64String(fileEncryptionKey)} {fileEncryptionKey.Length} bytes");

            cipher.Init(true, new ParametersWithIV(new KeyParameter(fileEncryptionKey), fileEncryptionIV));
            EncryptMainDataAndWrite(parameters.Path, encryptionFilePath);

            if (parameters.IfDeleteOriginalPath)
            {
                File.Delete(parameters.Path);
                string newPath = Path.Combine(Path.GetDirectoryName(parameters.Path), Path.GetFileName(encryptionFilePath));
                File.Copy(encryptionFilePath, newPath);
                File.Delete(encryptionFilePath);
            }
        }

        private string GetEncryptionPath(PathParameters parameters)
        {
            string fileName = Path.GetFileName(parameters.Path);
            if (fileName.StartsWith("DEC_"))
            {
                fileName = fileName.Substring(4);
            }
            string directoryPath = Path.GetDirectoryName(parameters.Path);
            string encryptFileName = "ENC_" + fileName;
            return Path.Combine
            (
                parameters.IfDeleteOriginalPath ? Path.GetTempPath() : directoryPath,
                parameters.IfUsePrefix ? encryptFileName : fileName
            );
        }

        private byte[] EncryptBytes(byte[] plainText, byte[] key, byte[] iv)
        {
            KeyParameter keyParameter = new KeyParameter(key);
            ParametersWithIV parametersWithIV = new ParametersWithIV(keyParameter, iv);
            cipher.Init(true, parametersWithIV);
            byte[] cipherText = new byte[cipher.GetOutputSize(plainText.Length)];
            cipher.DoFinal(plainText, 0, plainText.Length, cipherText, 0);
            return cipherText;
        }

        private void EncryptMainDataAndWrite(string originalPath, string encryptPath)
        {
            // Debug.WriteLine($"{originalPath}\n{encryptPath}");
            using (FileStream originalFileStream = File.OpenRead(originalPath))
            using (BinaryReader binaryReader = new BinaryReader(originalFileStream))
            using (FileStream encryptFileStream = File.OpenWrite(encryptPath))
            using (BinaryWriter binaryWriter = new BinaryWriter(encryptFileStream))
            {
                encryptFileStream.Seek(256 + 1, SeekOrigin.Begin);

                byte[] buffer = new byte[1024];
                int bytesRead;
                while ((bytesRead = binaryReader.Read(buffer, 0, buffer.Length)) > 0)
                {
                    byte[] cipherText = cipher.ProcessBytes(buffer, 0, buffer.Length);
                    binaryWriter.Write(cipherText);
                }
                binaryWriter.Flush();
            }
        }

        private HeaderData GenerateHeaderData(ref byte[] fileEncryptionKey, ref byte[] IV)
        {
            HeaderData headerData = new HeaderData();
            // encryption algorithm
            headerData.EncryptionAlgorithm = ((byte)encryptionParameters.EncryptionAlgorithm);
            // file encryption key length
            headerData.FileEncryptionKeyLength = encryptionParameters.KeyLength == 256;
            // salt
            randomGenerator.NextBytes(headerData.KeyVerifySalt); // 32 bytes
            randomGenerator.NextBytes(headerData.KeyDerivationSalt); // 32 bytes
            // verify hash
            headerData.KeyVerifyHash = KeyDerivation(encryptionParameters.Key, headerData.KeyVerifySalt, 256);
            // protection key
            EncryptionAlgorithmsDetails encryptionAlgorithmsDetails = encryptionAlgorithmMap[encryptionParameters.EncryptionAlgorithm];
            byte[] protectionKey = KeyDerivation(encryptionParameters.Key, headerData.KeyDerivationSalt, encryptionAlgorithmsDetails.MaxKeyLength);
            // Debug.WriteLine($"Protection Key: {Convert.ToBase64String(protectionKey)}");
            // IV
            IV = new byte[encryptionAlgorithmsDetails.IV_Length >> 3];
            randomGenerator.NextBytes(IV);
            headerData.IV = IV;
            // file encryption key
            if (encryptionParameters.KeyLength == 128)
            {
                fileEncryptionKey = new byte[16];
            }
            else
            {
                fileEncryptionKey = new byte[encryptionAlgorithmsDetails.MaxKeyLength >> 3];
            }
            randomGenerator.NextBytes(fileEncryptionKey);

            headerData.EncryptedFileEncryptionKey = EncryptBytes(fileEncryptionKey, protectionKey, IV);

            return headerData;
        }

        // Method to create the header data
        private byte[] CreateWrittenHeader(HeaderData headerData)
        {
            using (MemoryStream memoryStream = new MemoryStream())
            using (BinaryWriter binaryWriter = new BinaryWriter(memoryStream))
            {
                // encryption algorithm
                binaryWriter.Write(headerData.EncryptionAlgorithm);
                // file encryption key length
                binaryWriter.Write(headerData.FileEncryptionKeyLength);
                // salt
                binaryWriter.Write((byte)headerData.KeyVerifySalt.Length);
                // Debug.WriteLine((byte) headerData.KeyVerifySalt.Length);
                binaryWriter.Write(headerData.KeyVerifySalt);

                binaryWriter.Write((byte)headerData.KeyDerivationSalt.Length);
                // Debug.WriteLine((byte) headerData.KeyDerivationSalt.Length);
                binaryWriter.Write(headerData.KeyDerivationSalt);
                // hash
                binaryWriter.Write((byte)headerData.KeyVerifyHash.Length);
                // Debug.WriteLine((byte) headerData.KeyVerifyHash.Length);
                binaryWriter.Write(headerData.KeyVerifyHash);
                //iv
                binaryWriter.Write((byte)headerData.IV.Length);
                // Debug.WriteLine((byte) headerData.IV.Length);
                binaryWriter.Write(headerData.IV);
                // encryption key 
                binaryWriter.Write((byte)headerData.EncryptedFileEncryptionKey.Length);
                // Debug.WriteLine((byte) headerData.EncryptedFileEncryptionKey.Length);
                binaryWriter.Write(headerData.EncryptedFileEncryptionKey);

                binaryWriter.Flush();
                // Debug.WriteLine("");

                return memoryStream.ToArray();
            }
        }

        private void WriteHeader(byte[] headerBytes, string encryptionFilePath)
        {
            using (FileStream fileStream = File.OpenWrite(encryptionFilePath))
            using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
            {
                binaryWriter.Write(headerBytes);
                Debug.WriteLine($"Header Padding: {256 - headerBytes.Length}");
                binaryWriter.Write(new byte[256 - headerBytes.Length]);
                binaryWriter.Flush();
            }
        }

        void IEncryptionService.DecryptFile(PathParameters parameters)
        {
            PathParametersCheck(parameters);
            byte[] readHeader = ReadHeader(parameters.Path);
            HeaderData headerData = LoadHeaderData(readHeader);
            // Verify the input key
            if (!KeyVerify(headerData))
            {
                throw new Exception("Input key is wrong!");
            }

            EncryptionAlgorithmsDetails encryptionAlgorithmsDetails = encryptionAlgorithmMap[(EncryptionAlgorithms) headerData.EncryptionAlgorithm];
            cipher = CipherUtilities.GetCipher(encryptionAlgorithmsDetails.Name);

            string decryptionPath = GetDecryptionPath(parameters);

            // Derive the protection key and decrypt the file encryption key
            byte[] protectionKey = KeyDerivation(encryptionParameters.Key, headerData.KeyDerivationSalt, encryptionAlgorithmsDetails.MaxKeyLength);
            // Debug.WriteLine($"Protection Key: {Convert.ToBase64String(protectionKey)}");

            byte[] fileEncryptionKey = DecryptBytes(headerData.EncryptedFileEncryptionKey, protectionKey, headerData.IV);
            if (!headerData.FileEncryptionKeyLength)
            {
                fileEncryptionKey = fileEncryptionKey.Take(16).ToArray();
            }
            else
            {
                fileEncryptionKey = fileEncryptionKey.Take(encryptionAlgorithmsDetails.MaxKeyLength >> 3).ToArray();
            }

            Debug.WriteLine($"File Encryption Key: {Convert.ToBase64String(fileEncryptionKey)} {fileEncryptionKey.Length} bytes");

            // Initialize the stream cipher and decrypt the main data
            cipher.Init(false, new ParametersWithIV(new KeyParameter(fileEncryptionKey), headerData.IV));
            DecryptMainDataAndWrite(parameters.Path, decryptionPath);

            if (parameters.IfDeleteOriginalPath)
            {
                File.Delete(parameters.Path);
                string newPath = Path.Combine(Path.GetDirectoryName(parameters.Path), Path.GetFileName(decryptionPath));
                File.Copy(decryptionPath, newPath);
                File.Delete(decryptionPath);
            }
        }

        private string GetDecryptionPath(PathParameters pathParameters)
        {
            string fileName = Path.GetFileName(pathParameters.Path);
            if (fileName.StartsWith("ENC_"))
            {
                fileName = fileName.Substring(4);
            }
            string directoryPath = Path.GetDirectoryName(pathParameters.Path);
            string decryptFileName = "DEC_" + fileName;

            return Path.Combine
            (
                pathParameters.IfDeleteOriginalPath ? Path.GetTempPath() : directoryPath,
                pathParameters.IfUsePrefix ? decryptFileName : fileName
            );
        }

        private byte[] DecryptBytes(byte[] cipherText, byte[] key, byte[] iv)
        {
            KeyParameter keyParameter = new KeyParameter(key);
            ParametersWithIV parametersWithIV = new ParametersWithIV(keyParameter, iv);
            cipher.Init(false, parametersWithIV);
            byte[] plainText = new byte[cipher.GetOutputSize(cipherText.Length)];
            cipher.DoFinal(cipherText, 0, cipherText.Length, plainText, 0);
            return plainText;
        }

        private void DecryptMainDataAndWrite(string originalPath, string decryptPath)
        {
            using (FileStream originalFileStream = File.OpenRead(originalPath))
            using (BinaryReader binaryReader = new BinaryReader(originalFileStream))
            using (FileStream decryptFileStream = File.OpenWrite(decryptPath))
            using (BinaryWriter binaryWriter = new BinaryWriter(decryptFileStream))
            {
                originalFileStream.Seek(256 + 1, SeekOrigin.Begin);

                byte[] buffer = new byte[1024];
                int bytesRead;
                while ((bytesRead = binaryReader.Read(buffer, 0, buffer.Length)) > 0)
                {
                    byte[] plainText = cipher.ProcessBytes(buffer, 0, buffer.Length);
                    binaryWriter.Write(plainText);
                }
                binaryWriter.Flush();
            }
        }

        private byte[] ReadHeader(string decryptionFilePath)
        {
            using (FileStream fileStream = File.OpenRead(decryptionFilePath))
            using (BinaryReader binaryReader = new BinaryReader(fileStream))
            {
                return binaryReader.ReadBytes(256);
            }
        }

        private HeaderData LoadHeaderData(byte[] headerBytes)
        {
            using (MemoryStream memoryStream = new MemoryStream(headerBytes))
            using (BinaryReader binaryReader = new BinaryReader(memoryStream))
            {
                HeaderData headerData = new HeaderData();

                // encryption algorithm
                headerData.EncryptionAlgorithm = binaryReader.ReadByte();
                // file encryption key length
                headerData.FileEncryptionKeyLength = binaryReader.ReadBoolean();
                // salt
                byte byteRead = binaryReader.ReadByte();
                // Debug.WriteLine(byteRead);
                headerData.KeyVerifySalt = binaryReader.ReadBytes(byteRead);
                byteRead = binaryReader.ReadByte();
                // Debug.WriteLine(byteRead);
                headerData.KeyDerivationSalt = binaryReader.ReadBytes(byteRead);
                // hash
                byteRead = binaryReader.ReadByte();
                // Debug.WriteLine(byteRead);
                headerData.KeyVerifyHash = binaryReader.ReadBytes(byteRead);
                // iv
                byteRead = binaryReader.ReadByte();
                // Debug.WriteLine(byteRead);
                headerData.IV = binaryReader.ReadBytes(byteRead);
                // encrypted file encryption key
                byteRead = binaryReader.ReadByte();
                // Debug.WriteLine(byteRead);
                headerData.EncryptedFileEncryptionKey = binaryReader.ReadBytes(byteRead);

                return headerData;
            }
        }

        // Method to get the decryption path for an encrypted file
        private byte[] KeyDerivation(byte[] key, byte[] salt, short KeyLength)
        {
            if (key == null)
            {
                throw new ArgumentNullException(nameof(key));
            }
            Pkcs5S2ParametersGenerator generator = new Pkcs5S2ParametersGenerator();
            generator.Init(key, salt, 10000);
            KeyParameter derivedKey = (KeyParameter)generator.GenerateDerivedMacParameters(KeyLength);

            return derivedKey.GetKey();
        }

        // Method to verify the input key
        private bool KeyVerify(HeaderData headerData)
        {
            byte[] calculatedHash = KeyDerivation(encryptionParameters.Key, headerData.KeyVerifySalt, 256);
            for (int i = 0; i < calculatedHash.Length; i++)
            {
                if (headerData.KeyVerifyHash[i] != calculatedHash[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}
