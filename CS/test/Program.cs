using System.IO;
using System.Text;
using System.Net.Sockets;
using System.Net.Security;

class Program
{
	private static TcpClient? Client;
	private static NetworkStream? NS;
	private static SslStream? SS;
	private static BinaryWriter BW;

	private static void ConnectTest()
	{
		while (Client.Connected)
		{
			Task.Delay(1000).Wait();
		}
		BW.Close();
		SS.Close();
		NS.Close();
		Client.Close();
		Console.WriteLine("Disconnected");
	}
    private static void SendMessage(string message)
    {
        if (Client == null || !Client.Connected)
        {
            Console.WriteLine("Connect first");
            return;
        }
		BW.Write(message.Length);
		BW.Write(Encoding.UTF8.GetBytes(message));
		Console.WriteLine("Send Successfully");
    }

	private static void ConnectServer(string IP, int Port)
	{
        Client = new TcpClient(IP, Port);
		NS = Client.GetStream();
		SS = new SslStream(NS);
		BW = new BinaryWriter(SS);
		Task.Run(() => ConnectTest());
		Console.WriteLine("Connected");
	}

	private static void CommandInterface(string Command)
	{
		if (Command == null || Command.Length == 0)
		{
			Console.WriteLine("Please enter a command!");
			return;
		}
		string[] args = Command.Split();
		switch (args[0])
		{
			case "connect":
                if (args.Length < 3 || args[1] == null || args[1].Length == 0 || args[2] == null || args[2].Length == 0)
                {
                    Console.WriteLine("Please enter a IP and port!");
                    break;
                }
				Task.Run(() => ConnectServer(args[1], int.Parse(args[2])));
				break;

            case "send":
                if (args.Length < 2 || args[1] == null || args[1].Length == 0)
                {
                    Console.WriteLine("Please enter a message!");
                }
				Task.Run(() => SendMessage(args[1]));
                break;
			
			default:
				Console.WriteLine("Unknown command!");
				break;
		}
	}

	public static void Main(string[] args)
	{
		while (true)
		{
			string Command = Console.ReadLine();
			CommandInterface(Command);
		}
	}
}
