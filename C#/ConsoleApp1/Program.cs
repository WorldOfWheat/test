class Program
{
    static int a = 0;
    static SemaphoreSlim semaphore = new SemaphoreSlim(1);

    public static async Task Main(string[] args)
    {
        await Run1();
    }

    public static async Task Run1()
    {
        Run2();
        for (int i = 0; i < 10; i++)
        {
            await Task.Delay(2);
            Console.Write($"{i} ");
        }
        Console.WriteLine("");
    }
    public static async Task Run2()
    {
        for (int i = 10; i < 20; i++)
        {
            await Task.Delay(1);
            Console.Write($"{i} ");
        }
        Console.WriteLine("");
    }
}

