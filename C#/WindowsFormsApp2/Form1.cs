using System;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

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

        private void buttonSelectFile_Click_1(object sender, EventArgs e)
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

        private void buttonExecuteEncrypt_Click(object sender, EventArgs e)
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
                    EncryptionPackage encryptionPackage = new EncryptionPackage(inputKey);
                    encryptionPackage.EncryptFile(i);
                });
            }
        }

        private void buttonExecuteDecrypt_Click(object sender, EventArgs e)
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
                    EncryptionPackage encryptionPackage = new EncryptionPackage(inputKey);
                    try
                    {
                        encryptionPackage.DecryptFile(i);
                    }
                    catch (Exception ex) 
                    {
                        if (ex.Message == "Input key is wrong!")
                        {

                            MessageBox.Show("�K�X���~!", "", MessageBoxButtons.OK);
                        }
                        Debug.WriteLine(ex.Message);
                    }
                });
            }
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
                DialogResult dialogResult = MessageBox.Show("�A��J���K�X���׹L�u�I\n�аݬO�_���n�ϥΡH", "�z�K�Xĵ�i", MessageBoxButtons.YesNo);
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
                DialogResult dialogResult = MessageBox.Show("�K�X���]�t�Ʀr�M�r���I\n�аݬO�_���n�ϥΡH", "�z�K�Xĵ�i", MessageBoxButtons.YesNo);
                useOrNot &= dialogResult == DialogResult.Yes;
            }

            return useOrNot;
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {
            labelSelectPaths.Text = "";
        }
    }
}