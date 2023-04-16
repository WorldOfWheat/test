using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using EasyModbus;

namespace WindowsFormsApp1
{
    
    public partial class Form1 : Form
    {
        ModbusClient modbusClient;

        public Form1()
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
            modbusClient.Port = Convert.ToInt32(textBoxPort.Text);
            try
            {
                modbusClient.Connect();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            if (modbusClient.Connected)
            {
                textBoxStatus.Text = "OK";
            }
            else
            {
                textBoxStatus.Text = "waitting...";
            }
        }

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            modbusClient.Disconnect();
            textBoxStatus.Text = "waitting...";
        }

        private void buttonON_Click(object sender, EventArgs e)
        {
            modbusClient.WriteSingleCoil(1, true);
        }

        private void buttonOFF_Click(object sender, EventArgs e)
        {
            modbusClient.WriteSingleCoil(1, false);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (modbusClient.Connected)
            {
                labelNow.Text = modbusClient.ReadCoils(2, 1)[0].ToString();
            }
        }
    }
}
