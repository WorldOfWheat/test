using System.Diagnostics;
using Org.BouncyCastle.Crypto.Digests;

class Program
{
    private static FileStream? fileStream;
    private static BinaryReader? binaryReader;
    // private static Semaphore semaphore = new Semaphore(20, 20);

    

    public static void Main(string[] args)
    {
        Stopwatch stopWatch = new Stopwatch();
        stopWatch.Start();        
        
        string path = @"C:\Users\USER\Downloads\Array30IME.zip";
        fileStream = File.OpenRead(path);
        binaryReader = new BinaryReader(fileStream);
        long plainTextLength = fileStream.Length;

        Console.WriteLine($"PlainText length: {plainTextLength}");
        byte[] hash = CalculateSha256(0, plainTextLength);
        Console.WriteLine(Convert.ToHexString(hash).Replace("-", " "));

        stopWatch.Stop();

        Console.WriteLine("Time (ms): " + stopWatch.ElapsedMilliseconds);
    }
}