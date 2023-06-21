using System.IO;
using System.Text;
using System.Security.Cryptography;

class Program
{
	public static void Main(string[] args)
	{
		string path = @"C:\Users\a3028\Pictures\新增資料夾";
		List<Task> tasks = new List<Task>();
		for (int i = 0; i < 1e5; i++)
		{
			Task task = Task.Run(() => 
			{
				using (FileStream fileStream = File.OpenWrite(Path.Combine(path, Convert.ToString(i))))
				{
					fileStream.Write(new byte[]wasawdawdwa { 0 }, 0, 1);
				}
			});
			tasks.Add(task);
		}

		Task.WaitAll(tasks.ToArray());
	}
}daadxcaw
