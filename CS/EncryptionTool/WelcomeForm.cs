using System.Diagnostics;

namespace EncryptionTool
{
    public partial class WelcomeForm : Form
    {
        public WelcomeForm()
        {
            InitializeComponent();
        }

        private void WelcomeForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            Hide();
            Form form = new MainForm();
            form.ShowDialog();
        }

        private void confirm_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
