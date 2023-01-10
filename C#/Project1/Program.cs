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
    public static void fileUnique(string path)
    {
        string[] files = Directory.GetFiles(path);
        List<string> hashs = new List<string>();
        Dictionary<string, List<string>> byteToFilePath = new Dictionary<string, List<string>>();

        foreach (var i in files) 
        {
            byte[] fileByte = new byte[512];
            FileStream fs = new FileStream(i, FileMode.Open, FileAccess.Read);
            fs.Read(fileByte, 0, 512);
            fs.Close();
            
            string hex = Convert.ToHexString(fileByte);
            
            if (!byteToFilePath.ContainsKey(hex))
            {
                List<string> temp2 = new List<string>();
                temp2.Add(i);
                byteToFilePath.Add(hex, temp2);
            }
            else
            {
                byteToFilePath[hex].Add(i);
            }

            hashs.Add(hex);
        }

        hashs.Sort();
        
        for (int i = 0; i <= hashs.Count - 1; i++)
        {
            if (_binarySearch(hashs, hashs[i], i + 1, hashs.Count - 1))
            {
                List<string> temp = byteToFilePath[hashs[i]];
                File.Delete(temp.Last());
                byteToFilePath[hashs[i]].Remove(temp.Last());
            }
        }
    }
    public static void Main() 
    {



        return;
        Console.WriteLine(
        """
        #####################################
        Please enter the path to be uniqued. 
        """);
        
        string path = Console.ReadLine();

        Console.WriteLine(
        """
        #####################################
        """
        );
        if (path == null)
        {
            Console.WriteLine(
            """
            Invalid input.
            """
            );
        }
        fileUnique(path);       
    }
}