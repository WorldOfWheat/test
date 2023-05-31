using System.Runtime.CompilerServices;

class Fruit
{
    protected string Name;
    protected int Count;
}

class Apple : Fruit
{
    public Apple(string NewName, int Increasement)
    {
        this.Name = NewName;
        this.Count += Increasement;
    }
    public void GetApple()
    {
        Console.WriteLine($"{this.Name} x {Count}");
    }
    public void SetApple(int Increasement)
    {
        this.Count += Increasement;
    }
}

class Program
{
    static int a = 0;
    static SemaphoreSlim semaphore = new SemaphoreSlim(1);

    public static async Task Main(string[] args)
    {
        Apple a = new Apple("test", 5);
        a.GetApple();
        a.SetApple(500);
        a.Name = "test";
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

