using System.IO;
using System.Text;
using System.Net.Sockets;

class Program
{
	public static void Main(string[] args)
	{
		string Path = @"C:\Users\USER\Desktop\TestFile";
		if (!File.Exists(Path))
		{
			File.Create(Path).Close();
		}
		Random rand = new Random();
		using (FileStream fileStream = File.OpenWrite(Path))
		using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
		{
			for (int i = 0; i < 1024; i++)
			{
				for (int j = 0; j < 1024; j++)
				{
					for (int k = 0; k < 1024; k++)
					{
						binaryWriter.Write(rand.Next());
					}
				}
			}
			binaryWriter.Flush();
		}
	}
}
