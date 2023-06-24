using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Security.Cryptography.X509Certificates;
using System.Net.Security;

class Program
{
	private static TcpListener? Listener;
	private static TcpClient? Client;

	private static void ServerCreate(string IP, int Port)
	{
		Console.WriteLine("Starting server on {0}:{1}", IP, Port);
		IPAddress ServerIP = IPAddress.Parse(IP);
		Listener = new TcpListener(ServerIP, Port);
		Listener.Start();
		Console.WriteLine("Server started: {0}:{1}", IP, Port);
        Client = Listener.AcceptTcpClient();
		Console.WriteLine("Client connected");

		using (NetworkStream NS = Client.GetStream())	
		using (SslStream SS = new SslStream(NS, false))
		using (BinaryReader BR = new BinaryReader(SS))
		{
			while (Client.Connected)
			{
				int Size = BR.ReadInt32();
				Console.WriteLine($"{Encoding.UTF8.GetString(BR.ReadBytes(Size))}");
			}
		}
		Console.WriteLine("Client disconnected");
	}

	private static void CommandInterface(string Command)
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
				if (Listener != null)
				{
					Console.WriteLine("Server already running");
					break;
				}
				Task.Run(() => ServerCreate(args[1], int.Parse(args[2])));
				break;

			case "kill":
				if (Listener == null)
				{
					Console.WriteLine("Server is not running");
					break;
				}
				Listener.Stop();
				Listener = null;
				if (Client!= null)
				{
					Client.Close();
					Client = null;
				}
				Console.WriteLine("Server stopped");
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
