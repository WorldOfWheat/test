using System.Security.Cryptography;

class test 
{
    static void Main() 
    {
        string path = @"C:\Users\a3028\Desktop\新增資料夾";
        string[] files = Directory.GetFiles(path);
        int len = files.Length;

        var hashs = new List<string>();
        for (int i = 0; i < len; i++) 
        {
            byte[] b = File.ReadAllBytes(files[i]);
            string h = Convert.ToHexString(SHA1.Create().ComputeHash(b));
            hashs.Add(h);
        } 

        hashs.Sort();
    
        foreach (var i in hashs)
        {
            Console.WriteLine(i);
        }
    }
}