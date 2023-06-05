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

		// RSACryptoServiceProvider rsa = new RSACryptoServiceProvider(4096);
		// string PublicKey = BitConverter.ToString(rsa.ExportRSAPublicKey()).Replace("-", "");
		// string PrivateKey = BitConverter.ToString(rsa.ExportRSAPrivateKey()).Replace("-", "");
		// Console.WriteLine($"PublicKey: {PublicKey}\nPrivateKey: {PrivateKey}");
	}
}
