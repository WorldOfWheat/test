using System.Diagnostics;
using System.Text;
using EncryptionPackage;

public partial class MainForm : Form
{
    private Dictionary<ErrorCode, string> errorMessage = new Dictionary<ErrorCode, string>()
    {
        [ErrorCode.PathParametersIsInvalid] = "[BUG] 檔案設定錯誤",
        [ErrorCode.EncryptionParametersIsInvalid] = "[BUG] 加密設定錯誤",
        [ErrorCode.InvaildEncryptionAlgorithm] = "[BUG] 找不到選定的加密演算法",
        [ErrorCode.InvaildKey] = "無效的密碼，請再次檢查密碼是否輸入正確",
        [ErrorCode.InvaildFile] = "無效的檔嬤，請再次檢查是否選擇的錯誤的檔案",
    };

    private EncryptionParameters encryptionParameters = new EncryptionParameters();
    private SortedSet<string> selectPaths = new SortedSet<string>();
    private string passwordHintText;
    private string extraEntropyHintText;

    public MainForm()
    {
        InitializeComponent();
    }

    // Method called when Form1 is loaded
    private void Form1_Load_1(object sender, EventArgs e)
    {
        Control.CheckForIllegalCrossThreadCalls = false;
        //
        passwordHintText = password.Text;
        extraEntropyHintText = extraEntropy.Text;
        //
        selectPathsList.View = View.Details;
        selectPathsList.GridLines = true;
        selectPathsList.Columns.Add("路徑");
        //
        ContextMenuStrip contextMenuStrip = new ContextMenuStrip();
        selectPathsList.ContextMenuStrip = contextMenuStrip;
        ToolStripMenuItem toolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem(); // 滑鼠右鍵選單選項
        toolStripMenuItem.Text = "刪除";
        toolStripMenuItem.Click += (sender, e) =>
        {
            if (selectPathsList.SelectedItems.Count <= 0)
            {
                return;
            }
            foreach (ListViewItem i in selectPathsList.SelectedItems)
            {
                selectPaths.Remove(i.Text);
            }
            Task.Run(() => { showSelectPathAndLockExecuteButton(); });
        };
        contextMenuStrip.Items.Add(toolStripMenuItem);
    }

    // Event handler for the buttonSelectFile click event
    private void selectFile_Click(object sender, EventArgs e)
    {
        using (OpenFileDialog selectDialog = new OpenFileDialog())
        {
            selectDialog.Title = "請選擇檔案或資料夾";
            selectDialog.Multiselect = true;

            if (selectDialog.ShowDialog() == DialogResult.OK)
            {
                selectPaths.Clear();
                foreach (var i in selectDialog.FileNames)
                {
                    selectPaths.Add(i);
                }
            }
            else
            {
                return;
            }
        }

        Task.Run(() =>
        {
            showSelectPathAndLockExecuteButton();
        });
    }

    // Event handler for the buttonExecuteEncrypt click event
    private void selectEncrypt_Click(object sender, EventArgs e)
    {
        // left panel
        selectEncrypt.Enabled = false;
        selectDecrypt.Enabled = true;
        selectFile.Enabled = true;
        password.Enabled = true;
        execute.Enabled = true;
        // right panel
        encryptionAlgorithmSelector.Enabled = true;
        cipherBitsSelectGroup.Enabled = true;
        extraEntropy.Enabled = true;
    }

    // Event handler for the buttonExecuteDecrypt click event
    private void selectDecrypt_Click(object sender, EventArgs e)
    {
        // left panel
        selectEncrypt.Enabled = true;
        selectDecrypt.Enabled = false;
        selectFile.Enabled = true;
        password.Enabled = true;
        execute.Enabled = true;
        // right panel
        encryptionAlgorithmSelector.Enabled = false;
        cipherBitsSelectGroup.Enabled = false;
        extraEntropy.Enabled = false;
    }

    private void execute_Click(object sender, EventArgs e)
    {
        if (!CheckParametersAndMessageBox())
        {
            return;
        }

        if (!selectEncrypt.Enabled)
        {
            if (!VerifyPasswordAndMessageBox())
            {
                return;
            }

            RepeatPasswordForm repeatPasswordForm = new RepeatPasswordForm(password.Text);
            repeatPasswordForm.ShowDialog();
            if (!repeatPasswordForm.ifContinue)
            {
                return;
            }

            executeEncryptService();
        }
        else
        {
            executeDecryptService();
        }
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
        if (0 == string.Compare(extraEntropyHintText, extraEntropy.Text))
        {
            extraEntropy.Text = "";
        }
    }

    // Event handler for the extraEntropy Leave event
    private void extraEntropy_Leave(object sender, EventArgs e)
    {
        if (extraEntropy.Text == "" || extraEntropy.Text.Length == 0)
        {
            extraEntropy.Text = extraEntropyHintText;
        }
    }

    // Event handler for the password Enter event
    private void password_Enter(object sender, EventArgs e)
    {
        if (0 == string.Compare(passwordHintText, password.Text))
        {
            password.Text = "";
            password.PasswordChar = '*';
        }
    }

    // Event handler for the password Leave event
    private void password_Leave(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(password.Text))
        {
            password.Text = passwordHintText;
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
            keySize_256.Checked = true;
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

    private void executeEncryptService()
    {
        // lock the current form to prevent operations
        Enabled = false;
        WriteEncryptionParameters();
        encryptionParameters.IfEncrypt = true;
        Semaphore semaphore = new Semaphore(2, 2);
        List<Task> tasks = new List<Task>();

        ProgressShowForm progressShowForm = new ProgressShowForm();
        Task.Run(() =>
        {
            progressShowForm.ShowDialog();
        });

        int counter = 0;
        int selectPathsCount = selectPaths.Count;
        foreach (var i in selectPaths)
        {
            PathParameters pathParameters = new PathParameters();
            WritePathParameters(ref pathParameters);
            pathParameters.Path = i;
            Task task = Task.Run(() =>
            {
                semaphore.WaitOne();
                if (!progressShowForm.isClosed)
                {
                    IEncryptionService encryptionService = new EncryptionService(encryptionParameters);
                    try
                    {
                        encryptionService.EncryptFile(pathParameters);
                    }
                    catch (Exception ex)
                    {
                        lock (progressShowForm)
                        {
                            progressShowForm.AddError(pathParameters.Path, errorMessage[(ErrorCode) Convert.ToByte(ex.Message)]);
                        }
                    }
                }
                semaphore.Release();
                lock (progressShowForm)
                {
                    counter++;
                    progressShowForm.UpdateProgress(counter, selectPathsCount);
                }
            });
            tasks.Add(task);
        }

        Task.WaitAll(tasks.ToArray());
        progressShowForm.Close();
        semaphore.Dispose();
        // unlock the current form
        Enabled = true;
    }

    private void executeDecryptService()
    {
        // lock the current form to prevent operations
        Enabled = false;
        WriteEncryptionParameters();
        encryptionParameters.IfEncrypt = false;
        Semaphore semaphore = new Semaphore(2, 2);
        List<Task> tasks = new List<Task>();

        ProgressShowForm progressShowForm = new ProgressShowForm();
        Task.Run(() =>
        {
            progressShowForm.ShowDialog();
        });

        int counter = 0;
        int selectPathsCount = selectPaths.Count;
        foreach (var i in selectPaths)
        {
            PathParameters pathParameters = new PathParameters();
            WritePathParameters(ref pathParameters);
            pathParameters.Path = i;
            Task task = Task.Run(() =>
            {
                semaphore.WaitOne();
                if (!progressShowForm.isClosed)
                {
                    IEncryptionService encryptionService = new EncryptionService(encryptionParameters);
                    try
                    {
                        encryptionService.DecryptFile(pathParameters);
                    }
                    catch (Exception ex)
                    {
                        lock (progressShowForm)
                        {
                            progressShowForm.AddError(pathParameters.Path, errorMessage[(ErrorCode) Convert.ToByte(ex.Message)]);
                        }
                    }
                }
                semaphore.Release();
                lock (progressShowForm)
                {
                    counter++;
                    progressShowForm.UpdateProgress(counter, selectPathsCount);
                }
            });
            tasks.Add(task);
        }

        Task.WaitAll(tasks.ToArray());
        progressShowForm.Close();
        semaphore.Dispose();
        // unlock the current form
        Enabled = true;
    }

    // Method to show selected files in the labelSelectPaths label
    private void showSelectPathAndLockExecuteButton()
    {
        execute.Enabled = false;
        selectPathsList.BeginUpdate();
        //
        selectPathsList.Items.Clear();
        foreach (var i in selectPaths)
        {
            selectPathsList.Items.Add(i);
        }
        selectPathsList.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
        //
        selectPathsList.EndUpdate();
        execute.Enabled = true;
    }

    private bool VerifyPasswordAndMessageBox()
    {
        string password = this.password.Text;
        if (password.Length < 8)
        {
            DialogResult dialogResult = MessageBox.Show("你輸入的密碼長度過短！\n請問是否仍要使用？", "弱密碼警告", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.No)
            {
                return false;
            }
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
            DialogResult dialogResult = MessageBox.Show("密碼應包含數字和字母！\n請問是否仍要使用？", "弱密碼警告", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.No)
            {
                return false;
            }
        }

        return true;
    }

    private bool CheckParametersAndMessageBox()
    {
        if (0 == string.Compare(passwordHintText, password.Text))
        {
            MessageBox.Show("請填入密碼", "項目錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return false;
        }
        if (selectPaths.Count == 0)
        {
            MessageBox.Show("請選擇檔案", "項目錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return false;
        }

        if (!selectEncrypt.Enabled)
        {
            if (encryptionAlgorithmSelector.SelectedIndex == -1)
            {
                MessageBox.Show("請選擇加密演算法", "項目錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (0 == string.Compare(extraEntropy.Text, extraEntropyHintText))
            {
                MessageBox.Show("請填入額外的熵", "項目錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
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

}