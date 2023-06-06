using System.IO;
using System.Text;
using System.Net.Sockets;

class Program
{
	public static void Main(string[] args)
	{
		string Path = @"C:\temp\";
		if (!Directory.Exists(Path))
		{
			Directory.CreateDirectory(Path);
		}
		if (!File.Exists(Path + "test.txt"))
		{
			File.Create(Path + "test.txt").Close();
		}
		Random random = new Random(6);
		byte[] Data = Encoding.UTF8.GetBytes("abcdefghijklmnopqrstuvwxyz");
		byte[] Mask = new byte[Data.Length];
		random.NextBytes(Mask);
		for (int i = 0; i < Mask.Length; i++)
		{
			Data[i] = (byte)(Data[i] ^ Mask[i]);
		}
		using (FileStream fs = new FileStream(Path + "test.txt", FileMode.Create, FileAccess.Write))
		using (BinaryWriter bw = new BinaryWriter(fs))
		{
			bw.Write(Data);
		}
	}
}
