using System.Numerics;
using System.Security.Cryptography;
using System.Text;
using System.Net;
using System.Net.Sockets;

class Program
{
	private static TcpListener Listener;
	private static TcpClient Client;
	private static BinaryReader Br;
	private static BinaryWriter Bw;

	private static void ServerCreate(string IP, int Port)
	{
		Console.WriteLine("Starting server on {0}:{1}", IP, Port);
		IPAddress ServerIP = IPAddress.Parse(IP);
		Listener = new TcpListener(ServerIP, Port);
		Console.WriteLine("Server started: {0}:{1}", IP, Port);
		Listener.Start();
        Client = Listener.AcceptTcpClient();
		Console.WriteLine("Client connected");

		while (true)
		{
			NetworkStream ClientStream = Client.GetStream();
			Br = new BinaryReader(ClientStream);
			Console.WriteLine($"Receive Message: {Br.ReadString()}");
		}
	}

	private static async Task CommandInterface(string Command)
	{
		if (Command == null || Command.Length == 0)
		{
			Console.WriteLine("Please enter a command!");
			return;
		}
		string[] args = Command.Split();
		// Console.WriteLine("Command: {0}", args[0]);
		switch (args[0])
		{
			case "create":
				if (args.Length < 3 || args[1] == null || args[1].Length == 0 || args[2] == null || args[2].Length == 0)
				{
					Console.WriteLine("Please enter IP and port");
					break;
				}
				if (Listener!= null)
				{
					Console.WriteLine("Server already running");
					break;
				}
				Task.Run(() => ServerCreate(args[1], int.Parse(args[2])));
				break;

			case "kill":
				if (Listener != null)
				{
					Listener.Stop();
					Listener = null;				
				}
				if (Client != null)
				{
					Client.Close();
					Client = null;
				}
				Console.WriteLine("Server stopped");
				break;
			
			case "wait":
				Console.WriteLine("waitting...");
				await Task.Delay(2000);
				break;
			
			default:
				Console.WriteLine("Unknown command!");
				break;
		}
	}

	public static async Task Main(string[] args)
	{
		while (true)
		{
			string Command = Console.ReadLine();
			await CommandInterface(Command);
		}
	}
}
