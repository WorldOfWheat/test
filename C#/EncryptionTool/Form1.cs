using System.Diagnostics;
using System.Text;
using EncryptionPackage;

public partial class Form1 : Form
{
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
        if (!CheckEncryptionParameterAndMessageBox()) 
        {
            return;
        }

        if (!VerifyPasswordAndMessageBox())
        {
            return;
        }

        WriteEncryptionParameters();
        encryptionParameters.IfEncrypt = true;
        Semaphore semaphore = new Semaphore(2, 2);
        List<Task> tasks = new List<Task>();
        try
        {
            foreach (var i in selectFiles)
            {
                PathParameters pathParameters = new PathParameters();
                WritePathParameters(ref pathParameters);
                pathParameters.Path = i;
                Task task = Task.Run(() =>
                {
                    semaphore.WaitOne();
                    IEncryptionService encryptionService = new EncryptionService(encryptionParameters);
                    encryptionService.EncryptFile(pathParameters);
                    semaphore.Release();
                });
                tasks.Add(task);
            }
        }
        catch (Exception ex)
        {
            // Debug.WriteLine(ex.ToString());
            // MessageBox.Show(ex.Message);
            MessageBox.Show(ex.ToString());
        }
        Task.WaitAll(tasks.ToArray());
        semaphore.Dispose();
    }

    // Event handler for the buttonExecuteDecrypt click event
    private void buttonExecuteDecrypt_Click(object sender, EventArgs e)
    {
        WriteEncryptionParameters();
        encryptionParameters.IfEncrypt = false;
        Semaphore semaphore = new Semaphore(1, 1);
        List<Task> tasks = new List<Task>();
        foreach (var i in selectFiles)
        {
            try
            {
                PathParameters pathParameters = new PathParameters();
                WritePathParameters(ref pathParameters);
                pathParameters.Path = i;
                Task task = Task.Run(() =>
                {
                    semaphore.WaitOne();
                    IEncryptionService encryptionService = new EncryptionService(encryptionParameters);
                    try
                    {
                        encryptionService.DecryptFile(pathParameters);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show($"{ex.Message}\n{i}\n無法解密，可能是選擇了錯誤的檔案", "檔案錯誤", MessageBoxButtons.OK);
                    }
                    semaphore.Release();
                });
                tasks.Add(task);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        Task.WaitAll(tasks.ToArray());
        semaphore.Dispose();
    }

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
        if (0 == string.Compare("請在這裡打上一些東西，你不需要記得你輸入了什麼。", extraEntropy.Text))
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
        if (0 == string.Compare("請輸入密碼。注意！如果忘記則無法解密檔案！", password.Text))
        {
            password.Text = "";
            password.PasswordChar = '.';
        }
    }

    // Event handler for the password Leave event
    private void password_Leave(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(password.Text))
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

    private void encryptionAlgorithmSelector_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = encryptionAlgorithmSelector.SelectedIndex;
        // ChaCha20
        if (index == 1)
        {
            keySize_128.Enabled = false;
            keySize_256.Enabled = false;
            return;
        }

        keySize_128.Text = "128";
        keySize_256.Text = "256";
        keySize_128.Enabled = true;
        keySize_256.Enabled = true;

        // 3DES
        if (index == 5)
        {
            keySize_128.Text = "128";
            keySize_256.Text = "192";
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

    private bool CheckEncryptionParameterAndMessageBox()
    {
        if (encryptionAlgorithmSelector.SelectedIndex == -1)
        {
            MessageBox.Show("請選擇加密演算法", "項目錯誤", MessageBoxButtons.OK);
            return false;
        }

        if (0 == string.Compare(extraEntropy.Text, "請在這裡打上一些東西，你不需要記得你輸入了什麼。"))
        {
            MessageBox.Show("請填入額外的熵", "項目錯誤", MessageBoxButtons.OK);
            return false;
        }

        return true;
    }

    private void WriteEncryptionParameters()
    {
        encryptionParameters.EncryptionAlgorithm = (EncryptionAlgorithms)encryptionAlgorithmSelector.SelectedIndex;
        encryptionParameters.Key = Encoding.Unicode.GetBytes(password.Text);
        encryptionParameters.KeyLength = (short)(keySize_128.Checked ? 128 : 256);
        encryptionParameters.ExtraEntropy = Encoding.Unicode.GetBytes(extraEntropy.Text);
    }

    private void WritePathParameters(ref PathParameters pathParameters)
    {
        pathParameters.IfUsePrefix = prefixUse.Checked;
        pathParameters.IfDeleteOriginalPath = deleteOriginalFile.Checked;
    }
    // Event handler for the deleteOriginalFile CheckStateChanged event

}