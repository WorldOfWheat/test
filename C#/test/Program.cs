namespace Program 
{
    public class Car
    {
        private int weight;
        public int Weight
        {
            set {
                Console.WriteLine("test1");
                weight = value;
            }
            get {
                Console.WriteLine("test2");
                return weight;
            }
        }
    }

    public static class Program
    {

        public static void Main(string[] args)
        {

        }
    }
}