using System.IO;
using System.Text;
using System.Security.Cryptography;

class Program
{
	public static void Main(string[] args)
	{
        int processorCount = Environment.ProcessorCount;
        Console.WriteLine("可用核心數量：" + processorCount);
	}
}