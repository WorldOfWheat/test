using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Random rand = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            trackBar1.SetRange(0, 100);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            trackBar1.Value = rand.Next(0, 100);
        }

        private void button2_MouseHover(object sender, EventArgs e)
        {
            button2.Location = new Point(rand.Next(0, 900), rand.Next(0, 400));
        }

        private void button2_MouseMove(object sender, MouseEventArgs e)
        {
            button2.Location = new Point(rand.Next(0, 900), rand.Next(0, 400));
        }
    }
}
