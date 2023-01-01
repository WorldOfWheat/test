using System.Security.Cryptography;

class test 
{
    static void Main() 
    {
        string path = @"C:\Users\a3028\Desktop\新增資料夾";
        SHA512 sha512 = new SHA512Managed();        
        string[] files = Directory.GetFiles(path);
        int len = files.Length;

        for (int i = 0; i < len; i++) 
        {
            for (int j = i + 1; j < len; j++) 
            {
                byte[] b1 = File.ReadAllBytes(files[i]);
                byte[] b2 = File.ReadAllBytes(files[j]);
                string h1 = Convert.ToHexString(sha512.ComputeHash(b1));
                string h2 = Convert.ToHexString(sha512.ComputeHash(b2));
                
                Console.WriteLine(h1 + " " + h2);
                
                if (h1 == h2) 
                {
                    File.Delete(files[i]);
                    break;
                }
            }
        } 
    }
}