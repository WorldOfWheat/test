using System.Security.Cryptography;
using System.Text;

class Program
{
	public static void Main(string[] args)
	{
		HMACSHA256 hMACSHA256 = new HMACSHA256();
		hMACSHA256.Initialize();
		var key = Encoding.UTF8.GetBytes("tesat");
		hMACSHA256.Key = key;
		var result = hMACSHA256.ComputeHash(Encoding.UTF8.GetBytes("message"));
		Console.WriteLine(BitConverter.ToString(result));
	}
}
