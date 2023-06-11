using System;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        private EncryptionDetail detail = new EncryptionDetail();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            labelSelectPaths.Text = "";
        }

        private void Form1_Load_1(object sender, EventArgs e)
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
                detail.Paths = selectFile.FileNames;
            }
            ShowSelectFiles();
        }

        private void buttonExecuteEncrypt_Click(object sender, EventArgs e)
        {
            if (!VerifyInputDataAndMessageBox())
            {
                return;
            }
            if (!VerifyPasswordAndMessageBox())
            {
                return;
            }
            WriteEncryptionDetial();
            foreach (var i in detail.Paths)
            {
                Task.Run(() =>
                {
                    EncryptionPackage encryptionPackage = new EncryptionPackage(detail);
                    encryptionPackage.EncryptFile(i);
                });
            }
        }

        private void buttonExecuteDecrypt_Click(object sender, EventArgs e)
        {
            if (!VerifyInputDataAndMessageBox())
            {
                return;
            }
            WriteEncryptionDetial();
            foreach (var i in detail.Paths)
            {
                Task.Run(() =>
                {
                    EncryptionPackage encryptionPackage = new EncryptionPackage(detail);
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

        private void deleteOriginalFile_CheckStateChanged(object sender, EventArgs e)
        {
            if (deleteOriginalFile.Checked == false)
            {
                prefixUse.Checked = true;
            }
        }

        private void extraEntropy_Enter(object sender, EventArgs e)
        {
            byte[] textBytes = Encoding.Unicode.GetBytes(extraEntropy.Text);
            string textHex = BitConverter.ToString(textBytes).Replace("-", "");
            string hintText = "CB8A28571990E18853620A4E004E9B4E71677F890CFF604F0D4E00978189188A975F604F388F6551864EC04EBC9E0230";
            if (0 == string.Compare(textHex, hintText))
            {
                extraEntropy.Text = "";
            }
        }

        private void extraEntropy_Leave(object sender, EventArgs e)
        {
            if (extraEntropy.Text == "" || extraEntropy.Text.Length == 0)
            {
                extraEntropy.Text = "�Цb�o�̥��W�@�ǪF��A�A���ݭn�O�o�A��J�F����C";
            }
        }

        private void password_Enter(object sender, EventArgs e)
        {
            byte[] passwordBytes = Encoding.Unicode.GetBytes(password.Text);
            string passwordHex = BitConverter.ToString(passwordBytes).Replace("-", "");
            string hintText = "CB8A388F6551C65BBC780230E86C0F6101FF82599C67D85F188A47522171D56CE389C65B946A486801FF";
            if (0 == string.Compare(passwordHex, hintText))
            {
                password.Text = "";
                password.PasswordChar = '.';
            }
        }

        private void password_Leave(object sender, EventArgs e)
        {
            if (password.Text == "" || password.Text.Length == 0)
            {
                password.Text = "�п�J�K�X�C�`�N�I�p�G�ѰO�h�L�k�ѱK�ɮסI";
                password.PasswordChar = '\0';
            }
        }

        private void prefixUse_CheckStateChanged(object sender, EventArgs e)
        {
            if (prefixUse.Checked == false)
            {
                deleteOriginalFile.Checked = true;
            }
        }

        private void ShowSelectFiles()
        {
            labelSelectPaths.Text = "";
            try
            {
                foreach (var i in detail.Paths)
                {
                    labelSelectPaths.Text += $"{i}\n";
                }
            }
            catch (ArgumentNullException) { }
            {
                return;
            }
        }

        private bool VerifyInputDataAndMessageBox()
        {
            try
            {
                _ = detail.Paths;
            }
            catch
            {
                MessageBox.Show("�п�Ķ�n�[�K�θѱK���ɮסI", "�]�w���~", MessageBoxButtons.OK);
                return false;
            }
            if (password.Text == "" || password.Text.Length == 0)
            {
                MessageBox.Show("�ж�J�K�X�I\n�K�X���i���šI", "�]�w���~", MessageBoxButtons.OK);
                return false;
            }
            if (cipherSelect == null)
            {
                MessageBox.Show("�п�Ķ�[�K��k�I", "�]�w���~", MessageBoxButtons.OK);
                return false;
            }

            return true;
        }

        private bool VerifyPasswordAndMessageBox()
        {
            string password = this.password.Text;
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

        private void WriteEncryptionDetial()
        {
            detail.CipherSelected = (EncryptionDetail.Cipher) cipherSelect.SelectedIndex;
            if (keySize_128.Checked) 
            {
                detail.KeyBits = 128;
            }
            else if (keySize_256.Checked)
            {
                detail.KeyBits = 256;
            }
            detail.InputKey = Encoding.Unicode.GetBytes(password.Text);
            detail.ExtraEntropy = Encoding.Unicode.GetBytes(extraEntropy.Text);
            detail.UsePrefix = prefixUse.Checked;
            detail.DeleteOriginalFile = deleteOriginalFile.Checked;
        }

    }
}