class Fruit
{
	private string Name;
	private int Count;
	protected void SetApple(string Name, int Count)
	{
		this.Name = Name;
		this.Count = Count;
	}
	public void Print()
	{
		Console.WriteLine($"{Name} x {Count}");
	}
}
class Apple : Fruit
{
	public Apple(string Name, int Count)
	{
		this.SetApple(Name, Count);
		this.Print();
	}
}

class Program
{
	public static void Main(string[] args)
	{
		Apple apple = new Apple("test1", 5);
		apple.Print();
	}
}
