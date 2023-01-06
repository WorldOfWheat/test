class Project2 
{
    public static void Main()
    {
        string path = @"C:\Users\a3028\testFile"; 
        if (!File.Exists(path)) 
        {
            File.Create(path);
        }
        

    }
}