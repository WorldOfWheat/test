// This code is a C# program that defines a partial class Form1 within the WinFormsApp1 namespace.
// The Form1 class represents a Windows Forms application form.

using System;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using WindowsFormsApp2;

namespace WinFormsApp1
{
public partial class Form1 : Form
{
    private PathParameters pathParameters = new PathParameters();
    private EncryptionParameters encryptionParameters = new EncryptionParameters();
    private string[] selectFiles;

    public Form1()
    {
        InitializeComponent();
    }

    // Method called when Form1 is loaded
    private void Form1_Load_1(object sender, EventArgs e)
    {
        labelSelectPaths.Text = "";
        Control.CheckForIllegalCrossThreadCalls = false; 
    }

    // Event handler for the buttonSelectFile click event
    private void buttonSelectFile_Click_1(object sender, EventArgs e)
    {
        using (OpenFileDialog selectFile = new OpenFileDialog())
        {
            selectFile.FilterIndex = 0;
            selectFile.RestoreDirectory = true;
            selectFile.Multiselect = true;

            if (selectFile.ShowDialog() == DialogResult.OK)
            {
                selectFiles = selectFile.FileNames;
            }
        }
        Task.Run(() => 
        { 
            executeEncrypt.Enabled = false;
            executeDecrypt.Enabled = false;
            ShowSelectFiles(); 
            executeEncrypt.Enabled = true;
            executeDecrypt.Enabled = true;
        });
    }

    // Event handler for the buttonExecuteEncrypt click event
    private void buttonExecuteEncrypt_Click(object sender, EventArgs e)
    {
        writeEncryptionParameters();
        writePathParameters();
        IEncryptionService encryptionService = new EncryptionService(encryptionParameters);
        foreach (var i in selectFiles)
        {
            Task.Run(() =>
            {
                pathParameters.Path = i;
                encryptionService.EncryptFile(pathParameters);
            });
        }
    }

    // Event handler for the buttonExecuteDecrypt click event
    private void buttonExecuteDecrypt_Click(object sender, EventArgs e)
    {
        writeEncryptionParameters();
        writePathParameters();
        IEncryptionService encryptionService = new EncryptionService(encryptionParameters);
        foreach (var i in selectFiles)
        {
            Task.Run(() =>
            {
                pathParameters.Path = i;
                encryptionService.DecryptFile(pathParameters);
            });
        }
    }

    private void writeEncryptionParameters()
    {
        encryptionParameters.EncryptionAlgorithm = (EncryptionAlgorithms) encryptionAlgorithmSelector.SelectedIndex;
        encryptionParameters.Key = Encoding.Unicode.GetBytes(password.Text);
        encryptionParameters.KeyLength = (short) (keySize_128.Checked ? 128 : 256);
        encryptionParameters.ExtraEntropy = Encoding.Unicode.GetBytes(extraEntropy.Text);
    }

    private void writePathParameters()
    {
        pathParameters.IfUsePrefix = prefixUse.Checked;
        pathParameters.IfDeleteOriginalPath = deleteOriginalFile.Checked;
    }
    // Event handler for the deleteOriginalFile CheckStateChanged event
    private void deleteOriginalFile_CheckStateChanged(object sender, EventArgs e)
    {
        if (deleteOriginalFile.Checked == false)
        {
            prefixUse.Checked = true;
        }
    }

    // Event handler for the extraEntropy Enter event
    private void extraEntropy_Enter(object sender, EventArgs e)
    {
        if (extraEntropy.Text.Length >= 30)
        {
            return;
        }
        byte[] textBytes = Encoding.Unicode.GetBytes(extraEntropy.Text);
        string textHex = BitConverter.ToString(textBytes).Replace("-", "");
        string hintText = "CB8A28571990E18853620A4E004E9B4E71677F890CFF604F0D4E00978189188A975F604F388F6551864EC04EBC9E0230";
        if (0 == string.Compare(textHex, hintText))
        {
            extraEntropy.Text = "";
        }
    }

    // Event handler for the extraEntropy Leave event
    private void extraEntropy_Leave(object sender, EventArgs e)
    {
        if (extraEntropy.Text == "" || extraEntropy.Text.Length == 0)
        {
            extraEntropy.Text = "請在這裡打上一些東西，你不需要記得你輸入了什麼。";
        }
    }

    // Event handler for the password Enter event
    private void password_Enter(object sender, EventArgs e)
    {
        if (password.Text.Length >= 30)
        {
            return;
        }
        byte[] passwordBytes = Encoding.Unicode.GetBytes(password.Text);
        string passwordHex = BitConverter.ToString(passwordBytes).Replace("-", "");
        string hintText = "CB8A388F6551C65BBC780230E86C0F6101FF82599C67D85F188A47522171D56CE389C65B946A486801FF";
        if (0 == string.Compare(passwordHex, hintText))
        {
            password.Text = "";
            password.PasswordChar = '.';
        }
    }

    // Event handler for the password Leave event
    private void password_Leave(object sender, EventArgs e)
    {
        if (password.Text == "" || password.Text.Length == 0)
        {
            password.Text = "請輸入密碼。注意！如果忘記則無法解密檔案！";
            password.PasswordChar = '\0';
        }
    }

    // Event handler for the prefixUse CheckStateChanged event
    private void prefixUse_CheckStateChanged(object sender, EventArgs e)
    {
        if (prefixUse.Checked == false)
        {
            deleteOriginalFile.Checked = true;
        }
    }

    // Method to show selected files in the labelSelectPaths label
    private void ShowSelectFiles()
    {
        labelSelectPaths.Text = "";
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < selectFiles.Length; i++)
        {
            stringBuilder.AppendLine(selectFiles[i]);
        }
        labelSelectPaths.Text = stringBuilder.ToString();
    }

    // Method to verify input data and display message boxes

    // Method to verify password and display message boxes
    private bool VerifyPasswordAndMessageBox()
    {
        string password = this.password.Text;
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
