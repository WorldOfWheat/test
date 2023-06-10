// Importing the required namespaces
using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Digests;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Crypto.Prng;
using System;
using System.Diagnostics;
using System.IO;

namespace WinFormsApp1
{
    // Class representing an encryption package
    class EncryptionPackage
    {
        // Private fields
        private readonly IStreamCipher streamCipher = new ChaChaEngine();
        private readonly CryptoApiRandomGenerator randomGenerator = new CryptoApiRandomGenerator();

        // Class representing the header data
        private class HeaderData
        {
            public byte[] KeyVerifySalt = new byte[16];
            public byte[] KeyVerifyHash = new byte[32];
            public byte[] KeyDerivationSalt = new byte[16];
            public byte[] ProtectKey = new byte[32];
            public byte[] FileEncryptKey = new byte[32];

            // Override the ToString method to provide a string representation of the header data
            public override string ToString()
            {
                return
                    $"KeyVerifySalt: {Convert.ToBase64String(KeyVerifySalt)}\n" +
                    $"KeyVerifyHash: {Convert.ToBase64String(KeyVerifyHash)}\n" +
                    $"KeyDerivationSalt: {Convert.ToBase64String(KeyDerivationSalt)}\n" +
                    $"ProtectKey: {Convert.ToBase64String(ProtectKey)}\n" +
                    $"FileEncryptKey: {Convert.ToBase64String(FileEncryptKey)}\n";
            }
        }

        private readonly byte[] inputKey;

        // Constructor for the EncryptionPackage class
        public EncryptionPackage(byte[] inputKey)
        {
            // Validate and initialize the input key
            this.inputKey = inputKey ?? throw new ArgumentNullException(nameof(inputKey));
        }

        // Method to decrypt a file
        public void DecryptFile(string originalPath)
        {
            // Check if the input key is empty
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("Input key cannot be empty.", nameof(inputKey));
            }

            // Get the decrypt path for the file
            string decryptPath = GetDecryptPath(originalPath);

            HeaderData headerData;
            using (FileStream fileStream = File.OpenRead(originalPath))
            using (BinaryReader binaryReader = new BinaryReader(fileStream))
            {
                // Load the header data from the file
                headerData = LoadHeaderData(binaryReader.ReadBytes(128));
            }

            // Verify the input key
            if (!KeyVerify(inputKey, headerData.KeyVerifySalt, headerData.KeyVerifyHash))
            {
                throw new Exception("Input key is wrong!");
            }

            // Derive the protection key and decrypt the file encryption key
            byte[] protectKey = KeyDerivation(inputKey, headerData.KeyDerivationSalt);
            byte[] fileEncryptKey = DecryptBytes(headerData.FileEncryptKey, protectKey);

            // Initialize the stream cipher and decrypt the main data
            streamCipher.Init(false, new ParametersWithIV(new KeyParameter(fileEncryptKey), new byte[8]));
            DecryptMainDataAndWrite(originalPath, decryptPath);
        }

        // Method to encrypt a file
        public void EncryptFile(string originalPath)
        {
            // Check if the input key is empty
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("Input key cannot be empty.", nameof(inputKey));
            }

            // Get the encrypt path for the file
            string encryptFilePath = GetEncryptPath(originalPath);

            // Create the header data
            HeaderData headerData = new HeaderData();
            randomGenerator.NextBytes(headerData.KeyVerifySalt);
            randomGenerator.NextBytes(headerData.KeyDerivationSalt);
            headerData.ProtectKey = KeyDerivation(inputKey, headerData.KeyDerivationSalt);
            headerData.KeyVerifyHash = KeyDerivation(inputKey, headerData.KeyVerifySalt);
            randomGenerator.NextBytes(headerData.FileEncryptKey);

            // Create the header and write it to the file
            byte[] writtenHead = CreateHeader(headerData);
            WriteHeader(writtenHead, encryptFilePath);

            // Initialize the stream cipher and encrypt the main data
            streamCipher.Init(true, new ParametersWithIV(new KeyParameter(headerData.FileEncryptKey), new byte[8]));
            EncryptMainDataAndWrite(originalPath, encryptFilePath);
        }

        // Method to create the header data
        private byte[] CreateHeader(HeaderData headerData)
        {
            using (MemoryStream memoryStream = new MemoryStream())
            using (BinaryWriter binaryWriter = new BinaryWriter(memoryStream))
            {
                // Write the header data to the memory stream
                binaryWriter.Write((byte)headerData.KeyVerifySalt.Length);
                binaryWriter.Write(headerData.KeyVerifySalt);

                binaryWriter.Write((byte)headerData.KeyVerifyHash.Length);
                binaryWriter.Write(headerData.KeyVerifyHash);

                binaryWriter.Write((byte)headerData.KeyDerivationSalt.Length);
                binaryWriter.Write(headerData.KeyDerivationSalt);

                byte[] encryptedFileEncryptKey = EncryptBytes(headerData.FileEncryptKey, headerData.ProtectKey);
                binaryWriter.Write((byte)encryptedFileEncryptKey.Length);
                binaryWriter.Write(encryptedFileEncryptKey);

                binaryWriter.Flush();

                return memoryStream.ToArray();
            }
        }

        // Method to decrypt bytes
        private byte[] DecryptBytes(byte[] cipherText, byte[] key)
        {
            // Initialize the stream cipher and decrypt the bytes
            streamCipher.Init(false, new ParametersWithIV(new KeyParameter(key), new byte[8]));
            byte[] plainText = new byte[cipherText.Length];
            streamCipher.ProcessBytes(cipherText, 0, cipherText.Length, plainText, 0);
            return plainText;
        }

        // Method to decrypt the main data and write it to a file
        private void DecryptMainDataAndWrite(string originalPath, string decryptPath)
        {
            using (FileStream originalFileStream = File.OpenRead(originalPath))
            using (BinaryReader binaryReader = new BinaryReader(originalFileStream))
            using (FileStream decryptFileStream = File.OpenWrite(decryptPath))
            using (BinaryWriter binaryWriter = new BinaryWriter(decryptFileStream))
            {
                originalFileStream.Seek(129, SeekOrigin.Begin);

                byte[] buffer = new byte[16];
                int bytesRead;
                while ((bytesRead = binaryReader.Read(buffer, 0, buffer.Length)) > 0)
                {
                    byte[] plainText = new byte[buffer.Length];
                    streamCipher.ProcessBytes(buffer, 0, bytesRead, plainText, 0);
                    binaryWriter.Write(plainText);
                }
                binaryWriter.Flush();
            }
        }

        // Method to encrypt bytes
        private byte[] EncryptBytes(byte[] plainText, byte[] key)
        {
            // Initialize the stream cipher and encrypt the bytes
            streamCipher.Init(true, new ParametersWithIV(new KeyParameter(key), new byte[8]));
            byte[] cipherText = new byte[plainText.Length];
            streamCipher.ProcessBytes(plainText, 0, plainText.Length, cipherText, 0);
            return cipherText;
        }

        // Method to encrypt the main data and write it to a file
        private void EncryptMainDataAndWrite(string originalPath, string encryptPath)
        {
            using (FileStream originalFileStream = File.OpenRead(originalPath))
            using (BinaryReader binaryReader = new BinaryReader(originalFileStream))
            using (FileStream encryptFileStream = File.OpenWrite(encryptPath))
            using (BinaryWriter binaryWriter = new BinaryWriter(encryptFileStream))
            {
                encryptFileStream.Seek(129, SeekOrigin.Begin);

                byte[] buffer = new byte[16];
                int bytesRead;
                while ((bytesRead = binaryReader.Read(buffer, 0, buffer.Length)) > 0)
                {
                    byte[] cipherText = new byte[buffer.Length];
                    streamCipher.ProcessBytes(buffer, 0, bytesRead, cipherText, 0);
                    binaryWriter.Write(cipherText);
                }
                binaryWriter.Flush();
            }
        }

        // Method to get the decryption path for an encrypted file
        private string GetDecryptPath(string encryptPath)
        {
            if (encryptPath == null || encryptPath.Length == 0)
            {
                throw new ArgumentNullException(nameof(encryptPath));
            }
            string fileName = Path.GetFileName(encryptPath);
            string directoryPath = Path.GetDirectoryName(encryptPath);
            if (fileName.StartsWith("ENC_"))
            {
                fileName = fileName.Substring(4);
            }
            string decryptFileName = "DEC_" + fileName;

            return Path.Combine(directoryPath, decryptFileName);
        }

        // Method to get the encryption path for an original file
        private string GetEncryptPath(string originalPath)
        {
            if (originalPath == null || originalPath.Length == 0)
            {
                throw new ArgumentNullException(nameof(originalPath));
            }
            string fileName = Path.GetFileName(originalPath);
            string directoryPath = Path.GetDirectoryName(originalPath);
            string encryptFileName = "ENC_" + fileName;
            return Path.Combine(directoryPath, encryptFileName);
        }

        // Method for key derivation
        private byte[] KeyDerivation(byte[] key, byte[] salt)
        {
            if (key == null)
            {
                throw new ArgumentNullException(nameof(key));
            }

            // Generate a BCrypt hash of the key with the salt
            byte[] bcryptHash = BCrypt.Generate(key, salt, 10);
            byte[] sha256Hash = new byte[32];
            Sha256Digest sha256 = new Sha256Digest();
            sha256.BlockUpdate(bcryptHash, 0, bcryptHash.Length);
            sha256.DoFinal(sha256Hash, 0);

            return sha256Hash;
        }

        // Method to verify the input key
        private bool KeyVerify(byte[] key, byte[] salt, byte[] hash)
        {
            byte[] calculatedHash = KeyDerivation(key, salt);
            for (int i = 0; i < hash.Length; i++)
            {
                byte xorBuffer = (byte)(hash[i] ^ calculatedHash[i]);
                if (xorBuffer != 0)
                {
                    return false;
                }
            }
            return true;
        }

        // Method to load the header data from a byte array
        private HeaderData LoadHeaderData(byte[] headerBytes)
        {
            using (MemoryStream memoryStream = new MemoryStream(headerBytes))
            using (BinaryReader binaryReader = new BinaryReader(memoryStream))
            {
                HeaderData headerData = new HeaderData();

                int saltLength = binaryReader.ReadByte();
                headerData.KeyVerifySalt = binaryReader.ReadBytes(saltLength);

                int hashLength = binaryReader.ReadByte();
                headerData.KeyVerifyHash = binaryReader.ReadBytes(hashLength);

                int derivationSaltLength = binaryReader.ReadByte();
                headerData.KeyDerivationSalt = binaryReader.ReadBytes(derivationSaltLength);

                int fileEncryptKeyLength = binaryReader.ReadByte();
                headerData.FileEncryptKey = binaryReader.ReadBytes(fileEncryptKeyLength);

                return headerData;
            }
        }

        // Method to write the header data to a file
        private void WriteHeader(byte[] headerBytes, string filePath)
        {
            using (FileStream fileStream = File.OpenWrite(filePath))
            using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
            {
                fileStream.Seek(0, SeekOrigin.Begin);
                binaryWriter.Write(headerBytes);
                binaryWriter.Flush();
            }
        }
    }
}
