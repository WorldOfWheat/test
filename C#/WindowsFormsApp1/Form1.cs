using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

public class PID 
{
    private double P, I, D, Max, Min;
    
    public PID(double P, double I, double D, double Max, double Min)
    {
        this.P = P;
        this.I = I;
        this.D = D;
        this.Max = Max;
        this.Min = Min;
    }

    public int Calculate(int Goal, int ValueNow)
    {
        return 0;
    }
}

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void TrackBarControl_ValueChanged(object sender, EventArgs e)
        {
            buttonSet.Enabled = true;
        }

        private void ButtonSet_Click(object sender, EventArgs e)
        {
            buttonSet.Enabled = false;
        }

        private void ButtonReset_Click(object sender, EventArgs e)
        {
            trackBarControl.Value = 50;
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
        }
    }
}
