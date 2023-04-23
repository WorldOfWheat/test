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
        PID pid = new PID(2, 2, 2, 1000, 1);

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
            trackBarShow.Value = (int) pid.Calculate(trackBarControl.Value, trackBarShow.Value);
        }
    }
}
public class PID 
{
    private const double SampleTime = 1;
    private readonly double Kp, Ki, Kd, Maximum, Minimum;
    private double I_Error, D_Error;
    private double LastError;
    
    public PID(double P, double I, double D, double Maximum, double Minimum)
    {
        Kp = P;
        Ki = I;
        Kd = D;
        this.Maximum = Maximum;
        this.Minimum = Minimum;
    }

    public double Calculate(int Goal, int ValueNow)
    {
        double Error = Goal - ValueNow;
        I_Error += Error * SampleTime;
        D_Error = (Error - LastError) / SampleTime;
        LastError = Error;
        double Result = Kp * Error + Ki * I_Error + Kd * D_Error;

        Result = Math.Min(Maximum, Result);
        Result = Math.Max(Minimum, Result);

        return Result;
    }
}
