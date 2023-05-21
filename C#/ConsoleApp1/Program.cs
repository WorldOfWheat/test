using System.Collections;
using System.Text;

namespace test
{
    class Progrom
    {
        static void Main()
        {
            List<byte> list = new List<byte>();
            list.AddRange(Encoding.Unicode.GetBytes("123456"));
            list.AddRange(Encoding.Unicode.GetBytes("\n"));
            list.AddRange(Encoding.Unicode.GetBytes("789"));
            Console.WriteLine(Encoding.Unicode.GetString(list.ToArray()));
        }
    }
}
