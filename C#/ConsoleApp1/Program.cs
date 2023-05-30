class Program
{
    static int a = 0;
    static SemaphoreSlim semaphore = new SemaphoreSlim(1);

    public static async Task Main(string[] args)
    {
        await test();
        Console.WriteLine("test2");
    }

    public static async Task test()
    {
        test2();
        for (int i = 0; i < 10; i++)
        {
            await Task.Delay(20);
            Console.Write(a++ + " ");
        }
        semaphore.Wait();

    }
    public static async Task test2()
    {
        for (int i = 0; i < 10; i++)
        {
            await Task.Delay(50);
            Console.Write(a++ + " ");
        }
        semaphore.Release();
    }
}

