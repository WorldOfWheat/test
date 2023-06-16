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
		Semaphore semaphore = new Semaphore(2, 2);
		for (int i = 0; i < 10; i++)
		{
			Task.Run(() => 
			{
				semaphore.WaitOne();
				try 
				{
					Console.Write(i + " ");
				}
				finally
				{
					semaphore.Release();
				}
			});
		}
		Thread.Sleep(10000);
	}
}
