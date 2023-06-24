class Program
{
	static SortedSet<string> allPaths = new SortedSet<string>(); 

	static void getAllPaths(string rootPath)
	{
		if (Directory.Exists(rootPath)) 
		{
			foreach (var i in Directory.GetDirectories(rootPath))
			{
				getAllPaths(i);
			}
		}

		foreach (var i in Directory.GetFiles(rootPath))
		{
			allPaths.Add(i);
		}
	}
	
	public static void Main(string[] args)
	{
		string path = @"d:\軟體\auto click.exe";
		allPaths.Add(@"D:\軟體\auto click.exe");
		allPaths.Add(@"D:\軟體\Sandboxie-Plus\Qt5Core.dll");
		allPaths.Add(@"D:\軟體\Sandboxie-Plus\Qt5Gui.dll");
		allPaths.Add(@"D:\軟體\Sandboxie-Plus\SbieIni.exe");
		allPaths.Add(@"D:\軟體\LocalSend\flutter_windows.dll");
		// SortedSet<string> set = new SortedSet<string>();
		// getAllPaths(path); 
		foreach (var i in allPaths)
		{
			using (FileStream fileStream = File.OpenRead(i))
			using (BinaryReader reader = new BinaryReader(fileStream))
			{

				List<byte> comparisonBytes = new List<byte>();
				for (int j = 1; j < fileStream.Length; j *= 2)
				{
					fileStream.Seek(j, SeekOrigin.Begin);
					comparisonBytes.Add(reader.ReadByte());
				}
				Console.WriteLine(Convert.ToBase64String(comparisonBytes.ToArray()));
			}
		}
	}
}