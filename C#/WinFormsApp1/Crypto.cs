using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Digests;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Modes;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Crypto.Prng;
using System.Diagnostics;

namespace WinFormsApp1
{
    class EncryptPack
    {
        private readonly IStreamCipher cipher = new ChaChaEngine();
        private readonly CryptoApiRandomGenerator rng = new CryptoApiRandomGenerator();

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
                throw new ArgumentException("InputKey cannot be empty.", nameof(inputKey));
            }

            string decryptPath = GetDecryptPath(originalPath);

            byte[] keyHashSalt;
            byte[] encryptedFileEncryptKey;
            using (FileStream fsOriginal = File.OpenRead(originalPath))
            using (BinaryReader bw = new BinaryReader(fsOriginal))
            {
                // Salt
                int Size = bw.ReadByte();
                keyHashSalt = new byte[Size];
                keyHashSalt = bw.ReadBytes(Size);
                // File Encrypt Key
                Size = bw.ReadByte();
                encryptedFileEncryptKey = new byte[Size];
                encryptedFileEncryptKey = bw.ReadBytes(Size);
            }
            byte[] protectKey = KeyDerivation(inputKey, keyHashSalt);
            byte[] fileEncryptKey = DecryptBytes(encryptedFileEncryptKey, protectKey);

            cipher.Init(false, new ParametersWithIV(new KeyParameter(fileEncryptKey), new byte[8]));
            DecryptMainDataAndWrite(originalPath, decryptPath);
        }

        public void EncryptFile(string originalPath)
        {
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("InputKey cannot be empty.", nameof(inputKey));
            }

            string encryptFilePath = GetEncryptPath(originalPath);

            byte[] fileEncryptKey = new byte[32];
            byte[] keyHashSalt = new byte[16];
            rng.NextBytes(fileEncryptKey);
            rng.NextBytes(keyHashSalt);
            byte[] protectKey = KeyDerivation(inputKey, keyHashSalt);

            // Debug.WriteLine($"Salt: {Convert.ToBase64String(keyHashSalt)}\n" +
            //                 $"Protect Key: {Convert.ToBase64String(protectKey)}\n" +
            //                 $"File Encrypt Key: {Convert.ToBase64String(fileEncryptKey)}\n");

            byte[] header = CreateHeader(keyHashSalt, protectKey, fileEncryptKey);
            WriteHeader(header, encryptFilePath);

            cipher.Init(true, new ParametersWithIV(new KeyParameter(fileEncryptKey), new byte[8]));
            EncryptMainDataAndWrite(originalPath, encryptFilePath);
        }

        private byte[] CreateHeader(byte[] keyHashSalt, byte[] protectKey, byte[] fileEncryptKey)
        {
            using (MemoryStream ms = new MemoryStream())
            using (BinaryWriter bw = new BinaryWriter(ms))
            {
                // Salt 
                bw.Write((byte) keyHashSalt.Length);
                bw.Write(keyHashSalt);
                // File Encrypt Key
                byte[] encryptFileEncryptKey = EncryptBytes(fileEncryptKey, protectKey);
                bw.Write((byte) encryptFileEncryptKey.Length);
                bw.Write(encryptFileEncryptKey);

                bw.Flush();

                return ms.ToArray();
            }
        }

        private byte[] DecryptBytes(byte[] cipherText, byte[] key)
        {
            cipher.Init(false, new ParametersWithIV(new KeyParameter(key), new byte[8]));
            byte[] plainText = new byte[cipherText.Length];
            cipher.ProcessBytes(cipherText, plainText);
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
                    cipher.ProcessBytes(buffer, plainText);
                    bw.Write(plainText);
                }
                bw.Flush();
            }
        }

        private byte[] EncryptBytes(byte[] plainText, byte[] key)
        {
            cipher.Init(true, new ParametersWithIV(new KeyParameter(key), new byte[8]));
            byte[] cipherText = new byte[plainText.Length];
            cipher.ProcessBytes(plainText, cipherText);
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
                    cipher.ProcessBytes(buffer, cipherText);
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
            string decryptFileName = /*"DEC_" +*/ fileName;

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
            sha256.BlockUpdate(bcryptHash);
            sha256.DoFinal(sha256Hash);

            return sha256Hash;
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
