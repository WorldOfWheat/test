using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private readonly PID pid = new PID(0, 0, 0, 50, -50);
        private int Goal;
        private double AdjustedValue;

        public Form1()
        {
            InitializeComponent();
        }

        private void PidValueChange()
        {
            pid._Kp = Convert.ToDouble(numericUpDownP.Value / 10);
            pid._Ki = Convert.ToDouble(numericUpDownI.Value / 10);
            pid._Kd = Convert.ToDouble(numericUpDownD.Value / 10);
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
            PidValueChange();
            Goal = trackBarControl.Value;
        }

        private void ButtonReset_Click(object sender, EventArgs e)
        {
            trackBarControl.Value = 500;
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
            AdjustedValue = pid.Calculate(Goal, trackBarShow.Value);
            labelTest.Text = Convert.ToString(AdjustedValue);
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            trackBarShow.Value += (int) AdjustedValue;
        }
    }
}
public class PID
{
    private const double SampleTime = 50;
    private double Kp, Ki, Kd, Maximum, Minimum;
    private double I_Error, D_Error;
    private double LastError;

    public double _Kp
    {
        get { return Kp; }
        set { Kp = value; }
    }
    public double _Ki
    {
        get { return Ki; }
        set { Ki = value; }
    }
    public double _Kd
    {
        get { return Kd; }
        set { Kd = value; }
    }
    
    public PID(int P, int I, int D, int Maximum, int Minimum)
    {
        Kp = P;
        Ki = I;
        Kd = D;
        this.Maximum = Maximum;
        this.Minimum = Minimum;
    }

    public double Calculate(double Goal, double ValueNow)
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
