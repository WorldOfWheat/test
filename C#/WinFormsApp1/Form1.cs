using System.Diagnostics;

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
            EncryptPack ep = new EncryptPack(new byte[2] { 0x1, 0x2 });
            ep.EncryptFile(label1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            EncryptPack ep = new EncryptPack(new byte[2] { 0x1, 0x2 });
            ep.DecryptFile(label1.Text);
        }
    }
}