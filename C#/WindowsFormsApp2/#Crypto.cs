using System.Security.Cryptography;
using System.Diagnostics;

namespace WinFormsApp1
{
    class EncryptPack
    {
        private readonly Aes aes = Aes.Create();
        private readonly HMACSHA256 hmac = new HMACSHA256();
        private readonly RandomNumberGenerator rng = RandomNumberGenerator.Create();

        private readonly byte[] inputKey;

        public EncryptPack(byte[] inputKey)
        {
            // if inputKey is not null then this.inputKey = key
            // if inputKey is null then throw new...
            this.inputKey = inputKey ?? throw new ArgumentNullException(nameof(inputKey));
            aes.KeySize = 256;
        }
        public void DecryptFile(string originalPath)
        {
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("InputKey cannot be empty.", nameof(inputKey));
            }

            string decryptPath = GetDecryptPath(originalPath);
            Debug.WriteLine(decryptPath);

            byte[] hmacPlainText;
            byte[] encryptedFileEncryptKey;
            byte[] encryptedIV;
            int sumOfSize = 0;
            using (FileStream fsOriginal = File.OpenRead(originalPath))
            using (BinaryReader bw = new BinaryReader(fsOriginal))
            {
                // HMAC PlainText
                int Size = bw.ReadByte();
                sumOfSize += Size;
                hmacPlainText = new byte[Size];
                hmacPlainText = bw.ReadBytes(Size);
                // File Encrypt Key
                Size = bw.ReadByte();
                sumOfSize += Size;
                encryptedFileEncryptKey = new byte[Size];
                encryptedFileEncryptKey = bw.ReadBytes(Size);
                // IV
                Size = bw.ReadByte();
                sumOfSize += Size;
                encryptedIV = new byte[Size];
                encryptedIV = bw.ReadBytes(Size);
            }
            hmac.Key = inputKey;
            byte[] protectKey = hmac.ComputeHash(hmacPlainText);
            byte[] fileEncryptKey = DecryptBytes(encryptedFileEncryptKey, protectKey);
            byte[] iv = DecryptBytes(encryptedIV, protectKey);

            // Debug.WriteLine($"HMAC PlainText: {Convert.ToBase64String(hmacPlainText)}\n" +
            //                 $"Protect Key: {Convert.ToBase64String(protectKey)}\n" +
            //                 $"File Encrypt Key: {Convert.ToBase64String(fileEncryptKey)}\n" +
            //                 $"IV: {Convert.ToBase64String(iv)}");

            aes.Key = fileEncryptKey;
            aes.IV = iv;
            aes.Padding = PaddingMode.PKCS7;
            DecryptMainDataAndWrite(originalPath, decryptPath);
        }

        public void EncryptFile(string originalPath)
        {
            if (inputKey == null || inputKey.Length == 0)
            {
                throw new ArgumentException("InputKey cannot be empty.", nameof(inputKey));
            }

            string encryptFilePath = GetEncryptPath(originalPath);

            aes.GenerateKey();
            aes.GenerateIV();
            aes.Padding = PaddingMode.PKCS7;
            byte[] fileEncryptKey = aes.Key;
            byte[] iv = aes.IV;
            byte[] hmacPlainText = new byte[32];
            rng.GetBytes(hmacPlainText);
            hmac.Key = inputKey;
            byte[] protectKey = hmac.ComputeHash(hmacPlainText);

            // Debug.WriteLine($"HMAC PlainText: {Convert.ToBase64String(hmacPlainText)}\n" +
            //                 $"Protect Key: {Convert.ToBase64String(protectKey)}\n" +
            //                 $"File Encrypt Key: {Convert.ToBase64String(fileEncryptKey)}\n" +
            //                 $"IV: {Convert.ToBase64String(iv)}");

            byte[] header = CreateHeader(hmacPlainText, protectKey, fileEncryptKey, iv);
            WriteHeader(header, encryptFilePath);
            EncryptMainDataAndWrite(originalPath, encryptFilePath);
        }

        private byte[] CreateHeader(byte[] hmacPlainText, byte[] protectKey, byte[] fileEncryptKey, byte[] iv)
        {
            using (MemoryStream ms = new MemoryStream())
            using (BinaryWriter bw = new BinaryWriter(ms))
            {
                // HMAC PlainText 
                bw.Write((byte) hmacPlainText.Length);
                bw.Write(hmacPlainText);
                // File Encrypt Key
                byte[] encryptedFileEncryptKey = EncryptBytes(fileEncryptKey, protectKey);
                bw.Write((byte) encryptedFileEncryptKey.Length);
                bw.Write(encryptedFileEncryptKey);
                // IV
                byte[] encryptedIV = EncryptBytes(iv, protectKey);
                bw.Write((byte) encryptedIV.Length);
                bw.Write(encryptedIV);

                bw.Flush();

                return ms.ToArray();
            }
        }

        private byte[] DecryptBytes(byte[] Cipher, byte[] Key)
        {
            using (Aes aes2 = Aes.Create())
            {
                aes2.Key = Key;
                return aes2.DecryptEcb(Cipher, PaddingMode.PKCS7);
            }
        }

        private void DecryptMainDataAndWrite(string originalPath, string decryptedPath)
        {
            ICryptoTransform decryptor = aes.CreateDecryptor();
            using (FileStream fsOriginalPath = File.OpenRead(originalPath))
            using (BinaryReader br = new BinaryReader(fsOriginalPath))
            using (FileStream fsDecryptedPath = File.OpenWrite(decryptedPath))
            using (CryptoStream cs = new CryptoStream(fsDecryptedPath, decryptor, CryptoStreamMode.Write))
            {
                fsOriginalPath.Seek(128, SeekOrigin.Begin);
                br.BaseStream.CopyTo(cs);
                cs.Flush();
            }
        }

        private byte[] EncryptBytes(byte[] Plain, byte[] Key)
        {
            using (Aes aes2 = Aes.Create())
            {
                aes2.Key = Key;
                return aes2.EncryptEcb(Plain, PaddingMode.PKCS7);
            }
        }

        private void EncryptMainDataAndWrite(string originalPath, string encryptedPath)
        {
            ICryptoTransform encryptor = aes.CreateEncryptor();
            using (FileStream fsOriginalPath = File.OpenRead(originalPath))
            using (BinaryReader br = new BinaryReader(fsOriginalPath))
            using (FileStream fsEncryptedPath = File.OpenWrite(encryptedPath))
            using (CryptoStream cs = new CryptoStream(fsEncryptedPath, encryptor, CryptoStreamMode.Write))
            {
                fsEncryptedPath.Seek(128, SeekOrigin.Begin);
                br.BaseStream.CopyTo(cs);
                cs.Flush();
            }
        }

        private string GetDecryptPath(string encryptedPath)
        {
            if (encryptedPath == null || encryptedPath.Length == 0)
            {
                throw new ArgumentNullException(nameof(encryptedPath));
            }
            string fileName = Path.GetFileName(encryptedPath);
            string directoryPath = Path.GetDirectoryName(encryptedPath);
            if (fileName.StartsWith("ENC_"))
            {
                fileName = fileName.Substring(4);
            }
            string decryptedFileName = "DEC_" + fileName;

            return Path.Combine(directoryPath, decryptedFileName);
        }

        private string GetEncryptPath(string originalPath)
        {
            if (originalPath == null || originalPath.Length == 0)
            {
                throw new ArgumentNullException(nameof(originalPath));
            }
            string fileName = Path.GetFileName(originalPath);
            string directoryPath = Path.GetDirectoryName(originalPath);
            string encryptedFileName = "ENC_" + fileName;
            return Path.Combine(directoryPath, encryptedFileName);
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
