using System.IO;
using System.Text;
using System.Net.Sockets;

class Program
{
	private static TcpClient Client;
	private static NetworkStream NS;
	private static BinaryWriter BW;

    private static async Task SendMessage(string message)
    {
        if (Client == null)
        {
            Console.WriteLine("Connect first");
            return;
        }
		if (NS == null)
		{
			NS = Client.GetStream();
			BW = new BinaryWriter(NS);
		}

		BW.Write(message.Length);
        BW.Write(Encoding.UTF8.GetBytes(message));
		Console.WriteLine("Send Successfully");
    }

	private static async Task ConnectServer(string IP, int Port)
	{
        Client = new TcpClient(IP, Port);
        Console.WriteLine("Connected Successfully");
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
