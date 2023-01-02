class Project2 
{
    public static void Main()
    {
        string path = @"C:\Users\小麥\testFile"; 
        if (!File.Exists(path)) 
        {
            File.Create(path);
        }

        using (StreamReader sr = new StreamReader(path))
        {
            int len = sr.BaseStream.Length;
            Console.WriteLine(sr.Read());

            sr.Close();
        }


    }
}