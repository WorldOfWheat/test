using System.Security.Cryptography;
using System.Diagnostics;

namespace WinFormsApp1
{
    class EncryptPack
    {
        private Aes aes = Aes.Create();
        private HMACSHA256 hmac = new HMACSHA256();
        private RandomNumberGenerator rng = RandomNumberGenerator.Create();

        private byte[] InputKey;

        private byte[] EncryptBytes(byte[] Plain, byte[] Key)
        {
            Aes aes2 = Aes.Create();
            aes2.Key = Key;
            byte[] Cipher = aes2.EncryptEcb(Plain, PaddingMode.Zeros);
            return Cipher;
        }

        public EncryptPack(byte[] InputKey)
        {
            this.InputKey = new byte[InputKey.Length];
            this.InputKey = InputKey;
            aes.KeySize = 256;
        }

        public void EncryptFile(string OriginalPath)
        {
            if (InputKey == null || InputKey.Length == 0)
            {
                throw new ArgumentNullException("InputKey");
            }

            aes.GenerateKey();
            aes.GenerateIV();
            aes.Padding = PaddingMode.Zeros;
            byte[] FileEncryptKey = aes.Key;
            byte[] IV = aes.IV;
            byte[] HMAC_PlainText = new byte[32];
            rng.GetBytes(HMAC_PlainText);
            hmac.Key = this.InputKey;
            byte[] ProtectKey = hmac.ComputeHash(HMAC_PlainText);

            // make header, 96 bytes
            byte[] Header;
            using (MemoryStream ms = new MemoryStream())
            using (BinaryWriter bw = new BinaryWriter(ms))
            {
                // HMAC PlainText 
                bw.Write(HMAC_PlainText.Length);
                bw.Write(HMAC_PlainText);
                // File Encrypt Key
                byte[] Encrypted = EncryptBytes(FileEncryptKey, ProtectKey);
                bw.Write(Encrypted.Length);
                bw.Write(Encrypted);
                // IV
                Encrypted = EncryptBytes(IV, ProtectKey);
                bw.Write(Encrypted.Length);
                bw.Write(Encrypted);

                Header = ms.ToArray();
            }

            // get path
            string Path =
                OriginalPath.Remove(OriginalPath.LastIndexOf('\\')) +
                "\\ENC_" +
                OriginalPath.Substring(OriginalPath.LastIndexOf('\\') + 1);
            Debug.WriteLine($"{OriginalPath}\n{Path}");
            string DirectoryPath = Path.Remove(Path.LastIndexOf('\\'));
            if (!Directory.Exists(DirectoryPath))
            {
                Directory.CreateDirectory(DirectoryPath);
            }
            if (!File.Exists(Path))
            {
                using (File.Create(Path)) { };
            }

            // write header
            using (FileStream fs_Path = File.OpenWrite(Path))
            using (BinaryWriter bw = new BinaryWriter(fs_Path))
            {
                bw.Write(Header);
                bw.Flush();
            }

            // write main data
            ICryptoTransform Encryptor = aes.CreateEncryptor();
            using (FileStream fs_OriginalPath = File.OpenRead(OriginalPath))
            using (BinaryReader br = new BinaryReader(fs_OriginalPath))
            using (FileStream fs_Path = File.OpenWrite(Path))
            using (CryptoStream cs = new CryptoStream(fs_Path, Encryptor, CryptoStreamMode.Write))
            {
                cs.Write(br.ReadBytes((int) br.BaseStream.Length));
                cs.Flush();
            }
        }
    }
}
