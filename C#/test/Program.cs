class Program
{
    static void Sum(ref int Sum, int[] Array)
    {
        Sum = 0;
        foreach (var i in Array)
        {
            Sum += i;
        }
    }
    public static void Main(string[] args)
    {
        var array = new int[32];
        for (int i = 0; i < array.Length; i++)
        {
            array[i] = i;
        }
        Random rand = new Random();
        for (int i = 0; i < array.Length; i++)
        {
            int randNumber = rand.Next(0, array.Length);
            if (i == randNumber)
            {
                continue;
            }
            array[i] ^= array[randNumber];
            array[randNumber] ^= array[i];
            array[i] ^= array[randNumber];
        }

        foreach (var i in array)
        {
            Console.Write(i + " ");
        }
        Console.WriteLine("");
        
        int Result = 0;
        Sum(ref Result, array);
        Console.WriteLine(Result);
    }
}