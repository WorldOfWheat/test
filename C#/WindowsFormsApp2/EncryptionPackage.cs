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
    ChaCha20,
    Camellia,
    Twofish,
    Blowfish,
    TripleDES,
};

public class EncryptionAlgorithmsDetails
{
    public EncryptionAlgorithmsDetails(string Name, byte BlockSize)
    {
        this.Name = Name;
        this.BlockSize = BlockSize;
    }

    public string Name { get; }
    public byte BlockSize { get; }
}

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
    private Dictionary<EncryptionAlgorithms, EncryptionAlgorithmsDetails> encryptionAlgorithmMap;
    private IBufferedCipher cipher;
    private EncryptionParameters encryptionParameters;

    private class HeaderData
    {
        public byte EncryptionAlgorithm;
        public bool FileEncryptionKeyLength; // false = 128, true = 256
        public readonly byte[] KeyVerifySalt = new byte[32];
        public readonly byte[] KeyDerivationSalt = new byte[32];
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
                $"EncryptedFileEncryptionKey: {Convert.ToBase64String(EncryptedFileEncryptionKey)}\n" +
                $"EncryptedFileEncryptionIV: {Convert.ToBase64String(EncryptedFileEncryptionIV)}\n";
        }
    }

    public EncryptionService(EncryptionParameters encryptionParameters)
    {
        EncryptionParametersCheck(encryptionParameters);
        this.encryptionParameters = encryptionParameters;
        encryptionAlgorithmMap = new Dictionary<EncryptionAlgorithms, EncryptionAlgorithmsDetails>()
        {
            { EncryptionAlgorithms.AES, new EncryptionAlgorithmsDetails("AES/CFB/PKCS7Padding", 128) },
            { EncryptionAlgorithms.ChaCha20, new EncryptionAlgorithmsDetails("ChaCha20", 1) },
            { EncryptionAlgorithms.Camellia, new EncryptionAlgorithmsDetails("Camellia/CFB/PKCS7Padding", 128) },
            { EncryptionAlgorithms.Twofish, new EncryptionAlgorithmsDetails("Twofish/CFB/PKCS7Padding", 128) }
            { EncryptionAlgorithms.Blowfish, new EncryptionAlgorithmsDetails("Blowfish/CFB/PKCS7Padding", 128) },
            { EncryptionAlgorithms.TripleDES, new EncryptionAlgorithmsDetails("DESede/CFB/PKCS7Padding", 64) },
        };
    }

    // Method to decrypt a file
    void DecryptFile(PathParameters parameters)
    {
        PathParametersCheck(parameters);

        string decryptionPath = GetDecryptionPath(parameters);

        HeaderData headerData;

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

    private byte[] DecryptBytes(byte[] cipherText, byte[] key)
    {
        // Initialize the stream cipher and decrypt the bytes
        streamCipher.Init(false, new ParametersWithIV(new KeyParameter(key), new byte[8]));
        byte[] plainText = new byte[cipherText.Length];
        streamCipher.ProcessBytes(cipherText, 0, cipherText.Length, plainText, 0);
        return plainText;
    }

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

    // Method to encrypt a file
    void EncryptFile(PathParameters pathParameters)
    {
        PathParametersCheck(pathParameters);

        string encryptionFilePath = GetEncryptionPath(pathParameters);

        byte[] fileEncryptionKey = null;
        byte[] fileEncryptionIV = null;
        HeaderData headerData = GenerateHeaderData(ref fileEncryptionKey, ref fileEncryptionIV);
        byte[] writtenHeader = CreateWrittenHeader(headerData);
        WriteHeader(writtenHeader, encryptionFilePath);

        cipher.Init(true, new ParametersWithIV(new KeyParameter(fileEncryptionKey), fileEncryptionIV));
        EncryptMainDataAndWrite(pathParameters.Path, encryptionFilePath);

        if (pathParameters.IfDeleteOriginalPath)
        {
            File.Delete(pathParameters.Path);
            string newPath = Path.Combine(Path.GetDirectoryName(pathParameters.Path), Path.GetFileName(encryptionFilePath));
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
        // Initialize the stream cipher and encrypt the bytes
        cipher.Init(true, new ParametersWithIV(new KeyParameter(key), iv));
        byte[] cipherText = new byte[plainText.Length];
        cipher.DoFinal(plainText, 0, plainText.Length, cipherText, 0);
        return cipherText;
    }

    private void EncryptMainDataAndWrite(string originalPath, string encryptPath)
    {
        using (FileStream originalFileStream = File.OpenRead(originalPath))
        using (BinaryReader binaryReader = new BinaryReader(originalFileStream))
        using (FileStream encryptFileStream = File.OpenWrite(encryptPath))
        using (BinaryWriter binaryWriter = new BinaryWriter(encryptFileStream))
        {
            encryptFileStream.Seek(129, SeekOrigin.Begin);

            byte[] buffer = new byte[encryptionAlgorithmMap[encryptionParameters.EncryptionAlgorithm].BlockSize];
            int bytesRead;
            while ((bytesRead = binaryReader.Read(buffer, 0, buffer.Length)) > 0)
            {
                byte[] cipherText = new byte[buffer.Length];
                cipher.ProcessBytes(buffer, 0, bytesRead, cipherText, 0);
                binaryWriter.Write(cipherText);
            }
            binaryWriter.Flush();
        }
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
            binaryWriter.Write(headerData.KeyVerifySalt);

            binaryWriter.Write((byte)headerData.KeyDerivationSalt.Length);
            binaryWriter.Write(headerData.KeyDerivationSalt);

            // hash
            binaryWriter.Write((byte)headerData.KeyVerifyHash.Length);
            binaryWriter.Write(headerData.KeyVerifyHash);

            //iv
            binaryWriter.Write((byte) headerData.IV.Length);
            binaryWriter.Write(headerData.IV);

            // encryption key 
            binaryWriter.Write((byte)headerData.EncryptedFileEncryptionKey.Length);
            binaryWriter.Write(headerData.EncryptedFileEncryptionKey);


            binaryWriter.Flush();

            return memoryStream.ToArray();
        }
    }

    private HeaderData GenerateHeaderData(ref byte[] fileEncryptionKey, ref byte[] IV)
    {
        HeaderData headerData = new HeaderData();
        // encryption algorithm
        headerData.EncryptionAlgorithm = ((byte) encryptionParameters.EncryptionAlgorithm);
        // file encryption key length
        headerData.FileEncryptionKeyLength = encryptionParameters.KeyLength == 256;
        // salt
        randomGenerator.NextBytes(headerData.KeyVerifySalt); // 32 bytes
        randomGenerator.NextBytes(headerData.KeyDerivationSalt); // 32 bytes
        // verify hash
        headerData.KeyVerifyHash = KeyDerivation(encryptionParameters.Key, headerData.KeyVerifySalt, 256);
        // protection key
        byte[] protectionKey = KeyDerivation(encryptionParameters.Key, headerData.KeyDerivationSalt, 256);
        // iv
        randomGenerator.NextBytes(IV); // 8 bytes
        headerData.IV = IV;
        // file encryption key 
        // key
        fileEncryptionKey = new byte[encryptionParameters.KeyLength / 8];
        randomGenerator.NextBytes(fileEncryptionKey);
        headerData.EncryptedFileEncryptionKey = EncryptBytes(fileEncryptionKey, protectionKey, IV);

        return headerData;
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
        KeyParameter derivedKey = (KeyParameter) generator.GenerateDerivedMacParameters(KeyLength);

        return derivedKey.GetKey();
    }

    // Method to verify the input key
    private bool KeyVerify(byte[] key, byte[] salt, byte[] hash)
    {
        byte[] calculatedHash = KeyDerivation(key, salt, 256);
        for (int i = 0; i < hash.Length; i++)
        {
            if (hash[i] != calculatedHash[i])
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
        if (string.IsNullOrEmpty(parameters.Path))
        {
            throw new ArgumentNullException(nameof(parameters.Path));
        }
    }

    // Method to write the header data to a file
    private void WriteHeader(byte[] headerBytes, string filePath)
    {
        using (FileStream fileStream = File.OpenWrite(filePath))
        using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
        {
            binaryWriter.Write(headerBytes);
            binaryWriter.Flush();
        }
    }

}
