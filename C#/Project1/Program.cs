using System.Security.Cryptography;

class test 
{
    public static bool _binarySearch(List<string> list, string target, int left, int right) 
    {
        if (left > right) 
        {
            return false;
            Console.WriteLine("test");
        }

        int mid = (left + right) >> 1;
        if (list[mid] == target) 
        {
            return true;
        }

        if (String.Compare(list[mid], target) == 1) 
        {
            return _binarySearch(list, target, left, mid - 1);
        }
        else
        {
            return _binarySearch(list, target, mid + 1, right);
        }
    }
    public static void Main() 
    {
        string path = @"C:\Users\小麥\Desktop\test";
        string[] files = Directory.GetFiles(path);
        List<string> hashs = new List<string>();
        Dictionary<string, List<string>> hashToFilePath = new Dictionary<string, List<string>>();

        foreach (var i in files) 
        {
            FileStream fs = new FileStream(i, FileMode.Open, FileAccess.Read);
            byte[] fileByte = new byte[512];
            fs.Read(fileByte, 0, 512);
            fs.Close();
            byte[] hash = SHA1.Create().ComputeHash(fileByte);
            string hex = Convert.ToHexString(hash);
            
            if (!hashToFilePath.ContainsKey(hex))
            {
                List<string> temp2 = new List<string>();
                temp2.Add(i);
                hashToFilePath.Add(hex, temp2);
            }
            else
            {
                hashToFilePath[hex].Add(i);
            }

            hashs.Add(hex);
        }

        hashs.Sort();
        
        for (int i = 0; i <= hashs.Count - 1; i++)
        {
            if (_binarySearch(hashs, hashs[i], i + 1, hashs.Count - 1))
            {
                List<string> temp = hashToFilePath[hashs[i]];
                File.Delete(temp.Last());
                hashToFilePath[hashs[i]].Remove(temp.Last());
            }
        }
    }
}