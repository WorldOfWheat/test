using System.Diagnostics;
using System.Text;

namespace WinFormsApp1
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

        private void button3_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = @"C:\Users\USER\Desktop";
            openFileDialog1.FilterIndex = 0;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string selectedFileName = openFileDialog1.FileName;
                label1.Text = selectedFileName;
            }
            Debug.WriteLine(openFileDialog1.FileName);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0 || textBox1.Text == "")
            {
                return;
            }
            byte[] inputKey = Encoding.UTF8.GetBytes(textBox1.Text);
            Task.Run(() =>
            {
                EncryptPack ep = new EncryptPack(inputKey);
                ep.EncryptFile(label1.Text);
            });
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0 || textBox1.Text == "")
            {
                return;
            }
            byte[] inputKey = Encoding.UTF8.GetBytes(textBox1.Text);
            Task.Run(() =>
            {
                EncryptPack ep = new EncryptPack(inputKey);
                ep.DecryptFile(label1.Text);
            });
        }
    }
}