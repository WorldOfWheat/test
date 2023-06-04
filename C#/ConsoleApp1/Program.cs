using System.Security.Cryptography;
using System.Text;

class Program
{
    static RandomNumberGenerator randomNumberGenerator = RandomNumberGenerator.Create();

	static void GenerateCipherText(ref byte[] CipherText, ref byte[] Key, ref byte[] Nonce, ref byte[] Tag)
	{
		Key = new byte[32];
		randomNumberGenerator.GetBytes(Key);
		Nonce = new byte[12];	 
		randomNumberGenerator.GetBytes(Nonce);
		var ChaCha20 = new ChaCha20Poly1305(Key);
		var PlainText = new byte[128];
		randomNumberGenerator.GetBytes(PlainText);

		Console.WriteLine($"PlainText:\n{BitConverter.ToString(PlainText).Replace("-", "")}"); 

		CipherText = new byte[PlainText.Length];
		Tag = new byte[16];

		ChaCha20.Encrypt(Nonce, PlainText, CipherText, Tag);
	}
	
	public static void Main(string[] args)
	{
		byte[] Key = new byte[32];
		byte[] Nonce = new byte[12];
		byte[] CipherText = new byte[128];
		byte[] Tag = new byte[16];

		GenerateCipherText(ref CipherText, ref Key, ref Nonce, ref Tag);
		
		Console.WriteLine($"CipherText:\n{BitConverter.ToString(CipherText).Replace("-", "")}"); 
		Console.WriteLine($"Tag:\n{BitConverter.ToString(Tag).Replace("-", "")}"); 

		var ChaCha20 = new ChaCha20Poly1305(Key);
		var PlainText = new byte[128];
		// Console.WriteLine(PlainText.Length + " " + CipherText.Length);
		ChaCha20.Decrypt(Nonce, CipherText, Tag, PlainText);

		Console.WriteLine($"PlainText:\n{BitConverter.ToString(PlainText).Replace("-", "")}"); 
	}
}
