using System.Security.Cryptography;
using System.Text;

class Program
{
	static void PrintBytesArray(byte[] Input)
	{
		foreach (byte i in Input)
		{
			Console.Write(i + " ");
		}
		Console.WriteLine();
	}

	public static void Main(string[] args)
	{
		RSACryptoServiceProvider rsa = new RSACryptoServiceProvider(1024);
		string PublicKey = Convert.ToBase64String(rsa.ExportRSAPublicKey()).Replace("-", "");
		string PrivateKey = Convert.ToBase64String(rsa.ExportRSAPrivateKey()).Replace("-", "");
		Console.WriteLine($"PublicKey: {PublicKey}\nPrivateKey: {PrivateKey}");
		byte[] PlainText = Encoding.UTF8.GetBytes("Secure message");
		byte[] CipherText = rsa.Encrypt(PlainText, true);
		Console.WriteLine($"CipherText: {Convert.ToBase64String(CipherText).Replace("-", "")}");
		byte[] PlainText2 = rsa.Decrypt(CipherText, true);
		Console.WriteLine($"PlainText: {Encoding.UTF8.GetString(PlainText2)}");
	}
}
