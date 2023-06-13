// Importing the required namespaces
using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Digests;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Security;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

public enum EncryptionAlgorithms
{
    AES,
    Twofish,
    Blowfish,
    Camellia,
    ChaCha20,
    TripleDES,
};

public class EncryptionParameters
{
    public EncryptionAlgorithms EncryptionAlgorithm { get; set; }
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
class EncryptionService : IEncryptionService
{
    private readonly SecureRandom randomGenerator = new SecureRandom();
    private Dictionary<EncryptionAlgorithms, string> encryptionAlgorithmMap;
    private IBufferedCipher cipher;
    private EncryptionParameters encryptionParameters;

    private class HeaderData
    {
        public HeaderData(int keyBits)
        {
            if (keyBits != 128 && keyBits != 256)
            {
                throw new ArgumentException(nameof(keyBits));
            }

            this.KeyVerifySalt = new byte[16];
            this.KeyVerifyHash = new byte[keyBits / 8];
            this.KeyDerivationSalt = new byte[16];
            this.ProtectKey = new byte[keyBits / 8];
            this.FileEncryptKey = new byte[keyBits / 8];
        }
        public byte[] KeyVerifySalt;
        public byte[] KeyVerifyHash;
        public byte[] KeyDerivationSalt;
        public byte[] ProtectKey;
        public byte[] FileEncryptKey;

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

    public EncryptionService(EncryptionParameters encryptionParameters)
    {
        EncryptionParametersCheck(encryptionParameters);
        this.encryptionParameters = encryptionParameters;
        encryptionAlgorithmMap = new Dictionary<EncryptionAlgorithms, string>()
        {
            { EncryptionAlgorithms.AES, "AES" },
            { EncryptionAlgorithms.Blowfish, "Blowfish" },
            { EncryptionAlgorithms.Camellia, "Camellia" },
            { EncryptionAlgorithms.ChaCha20, "ChaCha20" },
            { EncryptionAlgorithms.TripleDES, "DESede" },
            { EncryptionAlgorithms.Twofish, "Twofish" }
        };
    }

    // Method to decrypt a file
    void DecryptFile(string originalPath)
    {
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
        if (!KeyVerify(detail.InputKey, headerData.KeyVerifySalt, headerData.KeyVerifyHash))
        {
            throw new Exception("Input key is wrong!");
        }

        // Derive the protection key and decrypt the file encryption key
        byte[] protectKey = KeyDerivation(detail.InputKey, headerData.KeyDerivationSalt);
        byte[] fileEncryptKey = DecryptBytes(headerData.FileEncryptKey, protectKey);

        // Initialize the stream cipher and decrypt the main data
        streamCipher.Init(false, new ParametersWithIV(new KeyParameter(fileEncryptKey), new byte[8]));
        DecryptMainDataAndWrite(originalPath, decryptPath);

        if (detail.DeleteOriginalFile)
        {
            File.Delete(originalPath);
            // DirectoryPathSwitch(ref originalPath, ref decryptPath);
            string newPath = Path.Combine(Path.GetDirectoryName(originalPath), Path.GetFileName(decryptPath));
            File.Copy(decryptPath, newPath);
            File.Delete(decryptPath);
        }
    }

    // Method to encrypt a file
    void EncryptFile(PathParameters pathParameters)
    {
        PathParametersCheck(pathParameters);

        string encryptFilePath = GetEncryptPath(pathParameters.Path);

        // Create the header data
        HeaderData headerData = new HeaderData(encryptionParameters.KeyLength);
        randomGenerator.NextBytes(headerData.KeyVerifySalt);
        randomGenerator.NextBytes(headerData.KeyDerivationSalt);
        headerData.ProtectKey = KeyDerivation(encryptionParameters.Key, headerData.KeyDerivationSalt);
        headerData.KeyVerifyHash = KeyDerivation(encryptionParameters.Key, headerData.KeyVerifySalt);
        randomGenerator.NextBytes(headerData.FileEncryptKey);

        // Create the header and write it to the file
        byte[] writtenHead = CreateHeader(headerData);
        WriteHeader(writtenHead, encryptFilePath);

        cipher.Init(true, new ParametersWithIV(new KeyParameter(headerData.FileEncryptKey), new byte[8]));
        EncryptMainDataAndWrite(pathParameters.Path, encryptFilePath);

        if (pathParameters.IfDeleteOriginalPath)
        {
            File.Delete(pathParameters.Path);
            string newPath = Path.Combine(Path.GetDirectoryName(pathParameters.Path), Path.GetFileName(encryptFilePath));
            File.Copy(encryptFilePath, newPath);
            File.Delete(encryptFilePath);
        }
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
        if (fileName.StartsWith("ENC_"))
        {
            fileName = fileName.Substring(4);
        }
        string directoryPath = Path.GetDirectoryName(encryptPath);
        string decryptFileName = "DEC_" + fileName;

        return Path.Combine
        (
            detail.DeleteOriginalFile ? Path.GetTempPath() : directoryPath, 
            detail.UsePrefix ? decryptFileName : fileName
        );
    }

    // Method to get the encryption path for an original file
    private string GetEncryptPath(string originalPath)
    {
        if (originalPath == null || originalPath.Length == 0)
        {
            throw new ArgumentNullException(nameof(originalPath));
        }

        string fileName = Path.GetFileName(originalPath);
        if (fileName.StartsWith("DEC_"))
        {
            fileName = fileName.Substring(4);
        }
        string directoryPath = Path.GetDirectoryName(originalPath);
        string encryptFileName = "ENC_" + fileName;
        return Path.Combine
        (
            detail.DeleteOriginalFile ? Path.GetTempPath() : directoryPath,
            detail.UsePrefix ? encryptFileName : fileName
        );
    }

    // Method for key derivation
    private byte[] KeyDerivation(byte[] key, byte[] salt)
    {
        if (key == null)
        {
            throw new ArgumentNullException(nameof(key));
        }
        Pkcs5S2ParametersGenerator generator = new Pkcs5S2ParametersGenerator();
        generator.Init(key, salt, 10000); 
        KeyParameter derivedKey = (KeyParameter) generator.GenerateDerivedMacParameters(detail.KeyBits);

        return derivedKey.GetKey();
    }

    // Method to verify the input key
    private bool KeyVerify(byte[] key, byte[] salt, byte[] hash)
    {
        byte[] calculatedHash = KeyDerivation(key, salt);
        if (calculatedHash.Length != hash.Length)
        {
            return false;
        }
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
            HeaderData headerData = new HeaderData(detail.KeyBits);

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

    private void EncryptionParametersCheck(EncryptionParameters parameters)
    {
        if (parameters.Key == null || parameters.Key.Length == 0)
        {
            throw new ArgumentNullException(nameof(parameters.Key));
        }
        if (parameters.KeyLength != (short) 128 && parameters.KeyLength != (short) 256)
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
        if (string.IsNullOrEmpty(parameters.FileName))
        {
            throw new ArgumentNullException(nameof(parameters.FileName));
        }
    }

    private void SetEncryptionAlgorithm(EncryptionAlgorithms encryptionAlgorithm)
    {
        cipher = CipherUtilities.GetCipher(encryptionAlgorithmMap[encryptionAlgorithm]);
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
