using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClassLibraryTest;

namespace WindowsFormsApp2
{
    public partial class ProgressShowForm : Form
    {
        public ProgressShowForm()
        {
            InitializeComponent();
            Class1 class1 = new Class1();
            // Debug.WriteLine(class1.Touppser("test"));
        }

        public void UpdateProgress(int progressNow, int progressTotal)
        {
            progressBar.Value = Convert.ToInt32(((double) progressNow / progressTotal) * 100.0);
        }

        private void TestingButton_Click(object sender, EventArgs e)
        {
        }
    }
}
