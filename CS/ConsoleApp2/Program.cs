using System.Diagnostics;
using Org.BouncyCastle.Crypto.Digests;

class Program
{
    private static FileStream? fileStream;
    private static BinaryReader? binaryReader;
    // private static Semaphore semaphore = new Semaphore(20, 20);

    private static byte[] CombineByteArrays(byte[] array1, byte[] array2)
    {
        byte[] combinedArrays = new byte[array1.Length + array2.Length];
        Buffer.BlockCopy(array1, 0, combinedArrays, 0, array1.Length);
        Buffer.BlockCopy(array2, 0, combinedArrays, array1.Length, array2.Length);
        return combinedArrays;
    }

    private static byte[] CalculateBytesSha256(byte[] input)
    {
        Sha256Digest sha256 = new Sha256Digest();
        sha256.BlockUpdate(input, 0, input.Length);
        byte[] output = new byte[sha256.GetDigestSize()];
        sha256.DoFinal(output, 0);
        return output;
    }

    private static byte[] CalculateSha256(long left, long right)
    {
        if (right - left < 64)
        {
            fileStream.Seek(left, SeekOrigin.Begin);
            byte[] buffer = new byte[right - left + 1];
            binaryReader.Read(buffer, 0, buffer.Length);

            return CalculateBytesSha256(buffer);
        }

        long mid = (left + right) / 2;
        byte[] leftHash = null;
        byte[] rightHash = null;
        Task taskLeft = Task.Run(() => 
        {
            leftHash = CalculateSha256(left, mid);
        });
        Task taskRight = Task.Run(() =>
        {
            rightHash = CalculateSha256(mid, right);
        });

        Task.WaitAll(taskLeft, taskRight);

        byte[] combined = CombineByteArrays(leftHash, rightHash);

        return CalculateBytesSha256(combined);
    }

    public static void Main(string[] args)
    {
        Stopwatch stopWatch = new Stopwatch();
        stopWatch.Start();        
        
        
        string path = @"D:\Win11_22H2_Chinese_Traditional_x64v1.iso";
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