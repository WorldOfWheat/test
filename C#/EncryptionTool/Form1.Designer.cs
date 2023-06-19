using System.Drawing;
using System.Windows.Forms;

partial class Form1
{
    /// <summary>
    ///  Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    ///  Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
        {
            components.Dispose();
        }
        base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    ///  Required method for Designer support - do not modify
    ///  the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
        tableLayoutPanel1 = new TableLayoutPanel();
        password = new TextBox();
        flowLayoutPanel1 = new FlowLayoutPanel();
        labelSelectPaths = new Label();
        executeEncrypt = new Button();
        executeDecrypt = new Button();
        buttonSelectFile = new Button();
        tableLayoutPanel2 = new TableLayoutPanel();
        encryptionAlgorithmSelector = new ComboBox();
        prefixUse = new CheckBox();
        cipherBitsSelectGroup = new GroupBox();
        keySize_128 = new RadioButton();
        keySize_256 = new RadioButton();
        deleteOriginalFile = new CheckBox();
        extraEntropy = new TextBox();
        tableLayoutPanel1.SuspendLayout();
        flowLayoutPanel1.SuspendLayout();
        tableLayoutPanel2.SuspendLayout();
        cipherBitsSelectGroup.SuspendLayout();
        SuspendLayout();
        // 
        // tableLayoutPanel1
        // 
        tableLayoutPanel1.ColumnCount = 2;
        tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        tableLayoutPanel1.Controls.Add(password, 0, 2);
        tableLayoutPanel1.Controls.Add(flowLayoutPanel1, 0, 1);
        tableLayoutPanel1.Controls.Add(executeEncrypt, 0, 3);
        tableLayoutPanel1.Controls.Add(executeDecrypt, 1, 3);
        tableLayoutPanel1.Controls.Add(buttonSelectFile, 0, 0);
        tableLayoutPanel1.Location = new Point(12, 11);
        tableLayoutPanel1.Margin = new Padding(3, 2, 3, 2);
        tableLayoutPanel1.Name = "tableLayoutPanel1";
        tableLayoutPanel1.RowCount = 4;
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25.50844F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50.66989F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 8.620703F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15.20097F));
        tableLayoutPanel1.Size = new Size(379, 527);
        tableLayoutPanel1.TabIndex = 0;
        // 
        // password
        // 
        password.Anchor = AnchorStyles.Left;
        tableLayoutPanel1.SetColumnSpan(password, 2);
        password.Font = new Font("DFKai-SB", 9F, FontStyle.Regular, GraphicsUnit.Point);
        password.Location = new Point(3, 412);
        password.Margin = new Padding(3, 2, 3, 2);
        password.Name = "password";
        password.Size = new Size(372, 22);
        password.TabIndex = 4;
        password.Text = "請輸入密碼。注意！如果忘記則無法解密檔案！";
        password.Enter += password_Enter;
        password.Leave += password_Leave;
        // 
        // flowLayoutPanel1
        // 
        flowLayoutPanel1.AutoScroll = true;
        flowLayoutPanel1.BorderStyle = BorderStyle.FixedSingle;
        tableLayoutPanel1.SetColumnSpan(flowLayoutPanel1, 2);
        flowLayoutPanel1.Controls.Add(labelSelectPaths);
        flowLayoutPanel1.Location = new Point(3, 136);
        flowLayoutPanel1.Margin = new Padding(3, 2, 3, 2);
        flowLayoutPanel1.Name = "flowLayoutPanel1";
        flowLayoutPanel1.Size = new Size(373, 259);
        flowLayoutPanel1.TabIndex = 1;
        // 
        // labelSelectPaths
        // 
        labelSelectPaths.AutoSize = true;
        labelSelectPaths.Font = new Font("PMingLiU", 12F, FontStyle.Regular, GraphicsUnit.Point);
        labelSelectPaths.Location = new Point(3, 0);
        labelSelectPaths.Name = "labelSelectPaths";
        labelSelectPaths.Size = new Size(45, 16);
        labelSelectPaths.TabIndex = 0;
        labelSelectPaths.Text = "label1";
        // 
        // executeEncrypt
        // 
        executeEncrypt.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        executeEncrypt.Location = new Point(3, 448);
        executeEncrypt.Margin = new Padding(3, 2, 3, 2);
        executeEncrypt.Name = "executeEncrypt";
        executeEncrypt.Size = new Size(183, 77);
        executeEncrypt.TabIndex = 0;
        executeEncrypt.Text = "加密";
        executeEncrypt.UseVisualStyleBackColor = true;
        executeEncrypt.Click += buttonExecuteEncrypt_Click;
        // 
        // executeDecrypt
        // 
        executeDecrypt.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        executeDecrypt.Location = new Point(192, 448);
        executeDecrypt.Margin = new Padding(3, 2, 3, 2);
        executeDecrypt.Name = "executeDecrypt";
        executeDecrypt.Size = new Size(183, 77);
        executeDecrypt.TabIndex = 1;
        executeDecrypt.Text = "解密";
        executeDecrypt.UseVisualStyleBackColor = true;
        executeDecrypt.Click += buttonExecuteDecrypt_Click;
        // 
        // buttonSelectFile
        // 
        tableLayoutPanel1.SetColumnSpan(buttonSelectFile, 2);
        buttonSelectFile.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        buttonSelectFile.Location = new Point(3, 2);
        buttonSelectFile.Margin = new Padding(3, 2, 3, 2);
        buttonSelectFile.Name = "buttonSelectFile";
        buttonSelectFile.Size = new Size(372, 127);
        buttonSelectFile.TabIndex = 5;
        buttonSelectFile.Text = "選取檔案";
        buttonSelectFile.UseVisualStyleBackColor = true;
        buttonSelectFile.Click += buttonSelectFile_Click_1;
        // 
        // tableLayoutPanel2
        // 
        tableLayoutPanel2.ColumnCount = 2;
        tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        tableLayoutPanel2.Controls.Add(encryptionAlgorithmSelector, 0, 0);
        tableLayoutPanel2.Controls.Add(prefixUse, 0, 3);
        tableLayoutPanel2.Controls.Add(cipherBitsSelectGroup, 0, 1);
        tableLayoutPanel2.Controls.Add(deleteOriginalFile, 0, 2);
        tableLayoutPanel2.Controls.Add(extraEntropy, 0, 4);
        tableLayoutPanel2.Location = new Point(413, 11);
        tableLayoutPanel2.Margin = new Padding(4, 5, 4, 5);
        tableLayoutPanel2.Name = "tableLayoutPanel2";
        tableLayoutPanel2.RowCount = 5;
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 15.38461F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 15.38461F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 15.38461F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 15.38461F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 38.46154F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Absolute, 30F));
        tableLayoutPanel2.Size = new Size(347, 523);
        tableLayoutPanel2.TabIndex = 1;
        // 
        // encryptionAlgorithmSelector
        // 
        encryptionAlgorithmSelector.Anchor = AnchorStyles.Left;
        tableLayoutPanel2.SetColumnSpan(encryptionAlgorithmSelector, 2);
        encryptionAlgorithmSelector.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point);
        encryptionAlgorithmSelector.FormattingEnabled = true;
        encryptionAlgorithmSelector.Items.AddRange(new object[] { "AES", "ChaCha20", "Camellia", "Twofish", "Blowfish", "3DES" });
        encryptionAlgorithmSelector.Location = new Point(4, 27);
        encryptionAlgorithmSelector.Margin = new Padding(4, 5, 4, 5);
        encryptionAlgorithmSelector.Name = "encryptionAlgorithmSelector";
        encryptionAlgorithmSelector.Size = new Size(337, 26);
        encryptionAlgorithmSelector.TabIndex = 2;
        encryptionAlgorithmSelector.SelectedIndexChanged += encryptionAlgorithmSelector_SelectedIndexChanged;
        // 
        // prefixUse
        // 
        prefixUse.Anchor = AnchorStyles.Left;
        prefixUse.AutoSize = true;
        tableLayoutPanel2.SetColumnSpan(prefixUse, 2);
        prefixUse.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        prefixUse.Location = new Point(4, 262);
        prefixUse.Margin = new Padding(4, 5, 4, 5);
        prefixUse.Name = "prefixUse";
        prefixUse.Size = new Size(154, 36);
        prefixUse.TabIndex = 1;
        prefixUse.Text = "是否使用檔名前綴\r\nENC_、DEC_";
        prefixUse.UseVisualStyleBackColor = true;
        prefixUse.CheckStateChanged += prefixUse_CheckStateChanged;
        // 
        // cipherBitsSelectGroup
        // 
        tableLayoutPanel2.SetColumnSpan(cipherBitsSelectGroup, 2);
        cipherBitsSelectGroup.Controls.Add(keySize_128);
        cipherBitsSelectGroup.Controls.Add(keySize_256);
        cipherBitsSelectGroup.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        cipherBitsSelectGroup.Location = new Point(4, 85);
        cipherBitsSelectGroup.Margin = new Padding(4, 5, 4, 5);
        cipherBitsSelectGroup.Name = "cipherBitsSelectGroup";
        cipherBitsSelectGroup.Padding = new Padding(4, 5, 4, 5);
        cipherBitsSelectGroup.Size = new Size(339, 70);
        cipherBitsSelectGroup.TabIndex = 2;
        cipherBitsSelectGroup.TabStop = false;
        cipherBitsSelectGroup.Text = "密鑰長度 (bits)";
        // 
        // keySize_128
        // 
        keySize_128.Anchor = AnchorStyles.Top;
        keySize_128.AutoSize = true;
        keySize_128.Checked = true;
        keySize_128.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point);
        keySize_128.Location = new Point(54, 29);
        keySize_128.Margin = new Padding(4, 5, 4, 5);
        keySize_128.Name = "keySize_128";
        keySize_128.Size = new Size(53, 22);
        keySize_128.TabIndex = 3;
        keySize_128.TabStop = true;
        keySize_128.Text = "128";
        keySize_128.UseVisualStyleBackColor = true;
        // 
        // keySize_256
        // 
        keySize_256.Anchor = AnchorStyles.Top;
        keySize_256.AutoSize = true;
        keySize_256.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point);
        keySize_256.Location = new Point(219, 29);
        keySize_256.Margin = new Padding(4, 5, 4, 5);
        keySize_256.Name = "keySize_256";
        keySize_256.Size = new Size(53, 22);
        keySize_256.TabIndex = 4;
        keySize_256.Text = "256";
        keySize_256.UseVisualStyleBackColor = true;
        // 
        // deleteOriginalFile
        // 
        deleteOriginalFile.Anchor = AnchorStyles.Left;
        deleteOriginalFile.AutoSize = true;
        deleteOriginalFile.Checked = true;
        deleteOriginalFile.CheckState = CheckState.Checked;
        tableLayoutPanel2.SetColumnSpan(deleteOriginalFile, 2);
        deleteOriginalFile.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        deleteOriginalFile.Location = new Point(4, 190);
        deleteOriginalFile.Margin = new Padding(4, 5, 4, 5);
        deleteOriginalFile.Name = "deleteOriginalFile";
        deleteOriginalFile.Size = new Size(122, 20);
        deleteOriginalFile.TabIndex = 0;
        deleteOriginalFile.Text = "是否刪除原檔";
        deleteOriginalFile.UseVisualStyleBackColor = true;
        deleteOriginalFile.CheckStateChanged += deleteOriginalFile_CheckStateChanged;
        // 
        // extraEntropy
        // 
        tableLayoutPanel2.SetColumnSpan(extraEntropy, 2);
        extraEntropy.Font = new Font("Arial", 12.75F, FontStyle.Regular, GraphicsUnit.Point);
        extraEntropy.Location = new Point(4, 325);
        extraEntropy.Margin = new Padding(4, 5, 4, 5);
        extraEntropy.Multiline = true;
        extraEntropy.Name = "extraEntropy";
        extraEntropy.ScrollBars = ScrollBars.Vertical;
        extraEntropy.Size = new Size(337, 191);
        extraEntropy.TabIndex = 3;
        extraEntropy.Text = "請在這裡打上一些東西，你不需要記得你輸入了什麼。";
        extraEntropy.Enter += extraEntropy_Enter;
        extraEntropy.Leave += extraEntropy_Leave;
        // 
        // Form1
        // 
        AutoScaleDimensions = new SizeF(8F, 18F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(768, 545);
        Controls.Add(tableLayoutPanel2);
        Controls.Add(tableLayoutPanel1);
        Margin = new Padding(3, 2, 3, 2);
        Name = "Form1";
        Text = "檔案加密工具";
        Load += Form1_Load_1;
        tableLayoutPanel1.ResumeLayout(false);
        tableLayoutPanel1.PerformLayout();
        flowLayoutPanel1.ResumeLayout(false);
        flowLayoutPanel1.PerformLayout();
        tableLayoutPanel2.ResumeLayout(false);
        tableLayoutPanel2.PerformLayout();
        cipherBitsSelectGroup.ResumeLayout(false);
        cipherBitsSelectGroup.PerformLayout();
        ResumeLayout(false);
    }

    #endregion

    private TableLayoutPanel tableLayoutPanel1;
    private Button executeEncrypt;
    private TextBox password;
    private Button buttonSelectFile;
    private FlowLayoutPanel flowLayoutPanel1;
    private Label labelSelectPaths;
    private Button executeDecrypt;
    private TableLayoutPanel tableLayoutPanel2;
    private CheckBox deleteOriginalFile;
    private CheckBox prefixUse;
    private ComboBox encryptionAlgorithmSelector;
    private RadioButton keySize_128;
    private RadioButton keySize_256;
    private GroupBox cipherBitsSelectGroup;
    private TextBox extraEntropy;
}