using System;
using System.Windows.Forms;
using EasyModbus;

namespace WindowsFormsApp1
{
    
    public partial class Login : Form
    {
        private ModbusClient modbusClient;

        public Login()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            modbusClient = new ModbusClient();
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            modbusClient.IPAddress = textBoxIP.Text;
            modbusClient.Port = Convert.ToInt32(numericUpDownPort.Value);
            try
            {
                modbusClient.Connect();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }
    }
}
