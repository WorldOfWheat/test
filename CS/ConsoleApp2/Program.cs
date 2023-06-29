using Org.BouncyCastle.Security;
using Org.BouncyCastle.Math;
using Org.BouncyCastle.Utilities;
using Org.BouncyCastle.Crypto.Generators;

class Program
{
    public static void Main(string[] args)
    {
        SecureRandom random_engine = new SecureRandom();
        BigInteger prime = BigInteger.ProbablePrime(7, random_engine);
        Console.WriteLine(prime.ToString());
    }
}