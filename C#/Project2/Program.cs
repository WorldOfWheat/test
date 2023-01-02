class Project2 
{
    public static void Main()
    {
        string path = @"C:\Users\a3028\testFile"; 
        if (!File.Exists(path)) 
        {
            File.Create(path);
        }
        
        using (StreamWriter sw = new StreamWriter(path))
        {
            sw.Write('0');
            sw.
             
            sw.Close();
        }

        using (StreamReader sr = new StreamReader(path))
        {
            Console.WriteLine(sr.Read());

            sr.Close();
        }


    }
}