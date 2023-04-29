using System.Collections.Specialized;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("請輸入數字A: ");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("請輸入數字B: ");
            int b = Convert.ToInt32(Console.ReadLine());

            int result = 1;
            for (int i = 0; i < b; i++)
            {
                result *= a;
            }

            Console.WriteLine("A的B次方為: ");
            Console.WriteLine(result.ToString());
        }
    }
}