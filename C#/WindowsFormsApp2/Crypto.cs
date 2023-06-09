using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Digests;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Modes;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Crypto.Prng;
using System;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace WinFormsApp1
{
    class EncryptPack
    {
        private readonly IStreamCipher cipher = new ChaChaEngine();
        private readonly CryptoApiRandomGenerator rng = new CryptoApiRandomGenerator();

        private class HeaderData
        {
            public byte[] keyVerifySalt = new byte[16];
            public byte[] keyVerifyHash = new byte[32];
            public byte[] keyDerivationSalt = new byte[16];
            public byte[] protectKey = new byte[32];
            public byte[] fileEncryptKey = new byte[32];

            public override string ToString()
            {
                return
                    $"KeyVerifySalt: {Convert.ToBase64String(keyVerifySalt)}\n" +
                    $"KeyVerifyHash: {Convert.ToBase64String(keyVerifyHash)}\n" +
                    $"KeyDerivationSalt: {Convert.ToBase64String(keyDerivationSalt)}\n" +
                    $"ProtectKey: {Convert.ToBase64String(protectKey)}\n" +
                    $"FileEncryptKey: {Convert.ToBase64String(fileEncryptKey)}\n";
            }
        }

        private readonly byte[] inputKey;

        public EncryptPack(byte[] inputKey)
        {
            // if inputKey is not null then this.inputKey = key
            // if inputKey is null then throw new...
            this.inputKey = inputKey ?? throw new ArgumentNullException(nameof(inputKey));
        }
        
        public void DecryptFile(string originalPath)
        {
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("Input key cannot be empty.", nameof(inputKey));
            }

            string decryptPath = GetDecryptPath(originalPath);

            HeaderData headerData;
            using (FileStream fs = File.OpenRead(originalPath))
            using (BinaryReader br = new BinaryReader(fs))
            {
                headerData = LoadHeaderData(br.ReadBytes(128));
            }

            Console.WriteLine(headerData.ToString());

            if (!KeyVerify(inputKey, headerData.keyVerifySalt, headerData.keyVerifyHash))
            {
                throw new Exception("Input key is wrong!");
            }

            byte[] protectKey = KeyDerivation(inputKey, headerData.keyDerivationSalt);
            byte[] fileEncryptKey = DecryptBytes(headerData.fileEncryptKey, protectKey);

            cipher.Init(false, new ParametersWithIV(new KeyParameter(fileEncryptKey), new byte[8]));
            DecryptMainDataAndWrite(originalPath, decryptPath);
        }

        public void EncryptFile(string originalPath)
        {
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("Input key cannot be empty.", nameof(inputKey));
            }

            string encryptFilePath = GetEncryptPath(originalPath);

            HeaderData headerData = new HeaderData();
            rng.NextBytes(headerData.keyVerifySalt);
            rng.NextBytes(headerData.keyDerivationSalt);
            headerData.protectKey = KeyDerivation(inputKey, headerData.keyDerivationSalt);
            headerData.keyVerifyHash = KeyDerivation(inputKey, headerData.keyVerifySalt);
            rng.NextBytes(headerData.fileEncryptKey);

            Console.Write(headerData.ToString() + '\n');

            byte[] writtenHead = CreateHeader(headerData);
            WriteHeader(writtenHead, encryptFilePath);

            cipher.Init(true, new ParametersWithIV(new KeyParameter(headerData.fileEncryptKey), new byte[8]));
            EncryptMainDataAndWrite(originalPath, encryptFilePath);
        }

        private byte[] CreateHeader(HeaderData headerData)
        {
            using (MemoryStream ms = new MemoryStream())
            using (BinaryWriter bw = new BinaryWriter(ms))
            {
                // key verify salt
                bw.Write((byte)headerData.keyVerifySalt.Length);
                bw.Write(headerData.keyVerifySalt);
                // key verify hash
                bw.Write((byte)headerData.keyVerifyHash.Length);
                bw.Write(headerData.keyVerifyHash);
                // key derivation salt 
                bw.Write((byte) headerData.keyDerivationSalt.Length);
                bw.Write(headerData.keyDerivationSalt);
                // encrypted file encrypt key
                byte[] encryptedFileEncryptKey = EncryptBytes(headerData.fileEncryptKey, headerData.protectKey);
                bw.Write((byte) encryptedFileEncryptKey.Length);
                bw.Write(encryptedFileEncryptKey);

                bw.Flush();

                return ms.ToArray();
            }
        }

        private byte[] DecryptBytes(byte[] cipherText, byte[] key)
        {
            cipher.Init(false, new ParametersWithIV(new KeyParameter(key), new byte[8]));
            byte[] plainText = new byte[cipherText.Length];
            cipher.ProcessBytes(cipherText, 0, cipherText.Length, plainText, 0);
            return plainText;
        }

        private void DecryptMainDataAndWrite(string originalPath, string decryptPath)
        {
            using (FileStream fsOriginalPath = File.OpenRead(originalPath))
            using (BinaryReader br = new BinaryReader(fsOriginalPath))
            using (FileStream fsDecryptPath = File.OpenWrite(decryptPath))
            using (BinaryWriter bw = new BinaryWriter(fsDecryptPath))
            {
                fsOriginalPath.Seek(129, SeekOrigin.Begin);

                byte[] buffer = new byte[16];
                int bytesRead;
                while ((bytesRead = br.Read(buffer, 0, buffer.Length)) > 0)
                {
                    byte[] plainText = new byte[buffer.Length];
                    cipher.ProcessBytes(buffer, 0, bytesRead, plainText, 0);
                    bw.Write(plainText);
                }
                bw.Flush();
            }
        }

        private byte[] EncryptBytes(byte[] plainText, byte[] key)
        {
            cipher.Init(true, new ParametersWithIV(new KeyParameter(key), new byte[8]));
            byte[] cipherText = new byte[plainText.Length];
            cipher.ProcessBytes(plainText, 0, plainText.Length, cipherText, 0);
            return cipherText;
        }

        private void EncryptMainDataAndWrite(string originalPath, string encryptPath)
        {
            using (FileStream fsOriginalPath = File.OpenRead(originalPath))
            using (BinaryReader br = new BinaryReader(fsOriginalPath))
            using (FileStream fsEncryptPath = File.OpenWrite(encryptPath))
            using (BinaryWriter bw = new BinaryWriter(fsEncryptPath))
            {
                fsEncryptPath.Seek(129, SeekOrigin.Begin);

                byte[] buffer = new byte[16];
                int bytesRead;
                while ((bytesRead = br.Read(buffer, 0, buffer.Length)) > 0)
                {
                    byte[] cipherText = new byte[buffer.Length];
                    cipher.ProcessBytes(buffer, 0, bytesRead, cipherText, 0);
                    bw.Write(cipherText);
                }
                bw.Flush();
            }
        }

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

        private byte[] KeyDerivation(byte[] key, byte[] salt)
        {
            if (key == null)
            {
                throw new ArgumentNullException(nameof(key));
            }

            byte[] bcryptHash = BCrypt.Generate(key, salt, 10);
            byte[] sha256Hash = new byte[32];
            Sha256Digest sha256 = new Sha256Digest();
            sha256.BlockUpdate(bcryptHash, 0, bcryptHash.Length);
            sha256.DoFinal(sha256Hash, 0);

            return sha256Hash;
        }
        
        private bool KeyVerify(byte[] key, byte[] salt, byte[] hash)
        {
            Debug.WriteLine(Convert.ToBase64String(hash));
            byte[] calculatedHash = KeyDerivation(key, salt);
            Debug.WriteLine(Convert.ToBase64String(calculatedHash));
            for (int i = 0; i < hash.Length; i++)
            {
                byte xorBuffer = (byte) (hash[i] ^ calculatedHash[i]);
                if (xorBuffer == 1)
                {
                    return false;
                }
            }
            return true;
        }

        private HeaderData LoadHeaderData(byte[] header)
        {
            if (header.Length != 128)
            {
                throw new ArgumentException("Header only can be 16 bytes long.", nameof(header));
            }

            HeaderData headerData = new HeaderData();

            using (MemoryStream ms = new MemoryStream())
            using (BinaryWriter bw = new BinaryWriter(ms))
            using (BinaryReader br = new BinaryReader(ms))
            {
                bw.Write(header);
                ms.Seek(0, SeekOrigin.Begin);

                // key verify salt
                int size = br.ReadByte();
                br.Read(headerData.keyVerifySalt, 0, size);
                // key verify hash
                size = br.ReadByte();
                br.Read(headerData.keyVerifyHash, 0, size);
                // key derivation salt
                size = br.ReadByte();
                br.Read(headerData.keyDerivationSalt, 0, size);
                // encrypted file encrypt key 
                size = br.ReadByte();
                br.Read(headerData.fileEncryptKey, 0, size);
            }

            return headerData;
        }

        private void WriteHeader(byte[] header, string path)
        {
            using (FileStream fs = File.OpenWrite(path))
            using (BinaryWriter bw = new BinaryWriter(fs))
            {
                bw.Write(header);
                for (int i = 0; i < 128 - header.Length; i++)
                {
                    bw.Write((byte)0x0);
                }
                bw.Flush();
            }
        }
    }
}
