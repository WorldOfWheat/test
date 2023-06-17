using System.IO;
using System.Text;
using System.Net.Sockets;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Math;
using System.Security.Cryptography;

class Program
{
	public static void Main(string[] args)
	{
		string path = @"C:\Users\a3028\Pictures\testFile";
		using (FileStream fileStream = File.OpenWrite(path))
		using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
		{
			binaryWriter.Write(new byte[8]);
		}
	}
}
