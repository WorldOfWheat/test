class test 
{
    static void Main() 
    {
        string path = "C:\\Users\\a3028\\Desktop\\input.txt";
        string[] input = File.ReadAllLines(path);

        foreach (var i in input)
        {
            string[] splited = i.Split(',');
            string temp = @"C:\Users\a3028\Desktop\old\" + splited[0];
            string temp2 = "T" + splited[1].Substring(1, splited[1].Length-1);
            //string temp2 = 
            //@"C:\Users\a3028\Desktop\new" + 
            //splited[1].Substring(2, splited[1].Length - 3) + 
            //@"\";

            Console.WriteLine(temp + " " + temp2);
            
            if (!Directory.Exists(temp2))
            {
                Directory.CreateDirectory(temp2);
            }
            if (File.Exists(temp)) 
            {
                Console.WriteLine("test");
                File.Move(temp, temp2 + splited[0], true);
            }
        }
    }
}