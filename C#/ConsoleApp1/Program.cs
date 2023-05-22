Random dice = new Random();
for (int i = 0; i < 10; i++)
{
    Console.Write((char) (dice.Next(0, 26) + 'A'));
}