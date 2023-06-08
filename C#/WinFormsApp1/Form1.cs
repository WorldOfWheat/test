using System.Diagnostics;
using System.Text;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        private string[] selectPaths;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            labelSelectPaths.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBoxPassword.Text.Length == 0 || textBoxPassword.Text == "")
            {
                return;
            }
            if (!VerifyPasswordAndMessageBox())
            {
                return;
            }
            byte[] inputKey = Encoding.UTF8.GetBytes(textBoxPassword.Text);
            foreach (var i in selectPaths)
            {
                Task.Run(() =>
                {
                    EncryptPack ep = new EncryptPack(inputKey);
                    ep.EncryptFile(i);
                });
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBoxPassword.Text.Length == 0 || textBoxPassword.Text == "")
            {
                return;
            }
            byte[] inputKey = Encoding.UTF8.GetBytes(textBoxPassword.Text);
            foreach (var i in selectPaths)
            {
                Task.Run(() =>
                {
                    EncryptPack ep = new EncryptPack(inputKey);
                    ep.DecryptFile(i);
                });
            }
        }

        private void buttonSelectFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog selectFile = new OpenFileDialog();

            selectFile.InitialDirectory = @"C:\Users\USER\Desktop";
            selectFile.FilterIndex = 0;
            selectFile.RestoreDirectory = true;
            selectFile.Multiselect = true;

            if (selectFile.ShowDialog() == DialogResult.OK)
            {
                selectPaths = selectFile.FileNames;
            }
            ShowSelectFiles();
        }

        private void ShowSelectFiles()
        {
            labelSelectPaths.Text = "";
            if (selectPaths == null || selectPaths.Length == 0)
            {
                return;
            }
            foreach (var i in selectPaths)
            {
                labelSelectPaths.Text += $"{i}\n";
            }
        }

        private bool VerifyPasswordAndMessageBox()
        {
            string password = textBoxPassword.Text;
            bool useOrNot = true;
            if (password.Length < 8)
            {
                DialogResult dialogResult = MessageBox.Show("你輸入的密碼長度過短！\n請問是否仍要使用？", "弱密碼警告", MessageBoxButtons.YesNo);
                useOrNot &= dialogResult == DialogResult.Yes;
            }
            bool hasDigit = false;
            bool hasLetter = false;
            foreach (var i in password)
            {
                hasDigit |= char.IsDigit(i);
                hasLetter |= char.IsLetter(i);
            }
            if (hasDigit ^ hasLetter)
            {
                DialogResult dialogResult = MessageBox.Show("密碼應包含數字和字母！\n請問是否仍要使用？", "弱密碼警告", MessageBoxButtons.YesNo);
                useOrNot &= dialogResult == DialogResult.Yes;
            }

            return useOrNot;
        }
    }
}