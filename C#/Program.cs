using System.Collections.Generic;
using System.Security.Cryptography;

class test 
{
    public static bool _binarySearch(List<string> list, string target, int left, int right) 
    {
        if (left > right) 
        {
            return false;
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
        string path = @"C:\Users\a3028\Desktop\test";
        string[] files = Directory.GetFiles(path);
        List<string> hashs = new List<string>();
        Dictionary<string, List<string>> hashToFilePath = new Dictionary<string, List<string>>();

        foreach (var i in files) 
        {
            byte[] fileByte = File.ReadAllBytes(i);
            List<byte> temp = new List<byte>(fileByte);
            if (temp.Count >= 512)
            {
                temp = temp.GetRange(0, 512);
            }
            fileByte = temp.ToArray();
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