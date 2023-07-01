namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            Task.Run(() =>
            {
                while (true)
                {
                    for (int i = 0; i < 500; i++)
                    {
                        int x = button1.Location.X;
                        int y = button1.Location.Y;
                        x += 2;
                        button1.Location = new Point(x, y);
                        Task.Delay(1).Wait();
                    }
                    Task.Delay(1000);
                    for (int i = 0; i < 500; i++)
                    {
                        int x = button1.Location.X;
                        int y = button1.Location.Y;
                        x--;
                        button1.Location = new Point(x, y);
                        Task.Delay(1).Wait();
                    }
                }
            });
        }
    }
}