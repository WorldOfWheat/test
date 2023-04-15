using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        private static List<Button> number_board = new List<Button>();

        public Form1()
        {
            InitializeComponent();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            number_board.Add(button0);
            number_board.Add(button1);
            number_board.Add(button2);
            number_board.Add(button3);
            number_board.Add(button4);
            number_board.Add(button5);
            number_board.Add(button6);
            number_board.Add(button7);
            number_board.Add(button8);
            number_board.Add(button9);

            Random rand = new Random();
            List<int> numbers = new List<int>();
            for (int i = 0; i <= 9; i++)
            {
                numbers.Add(i);
            }
            for (int i = 0; i < 20; i++)
            {
                int place1 = rand.Next(0, 100);
                int place2 = rand.Next(0, 100);
                
            }
            foreach (Button i in number_board)
            {
                i.Text = rand.Next(0, 9).ToString();
            }
        }

        private void button0_Click(object sender, EventArgs e)
        {

        }
    }
}
