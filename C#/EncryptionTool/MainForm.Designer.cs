using System.Drawing;
using System.Windows.Forms;

partial class MainForm
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
        selectEncrypt = new Button();
        selectDecrypt = new Button();
        flowLayoutPanel1 = new FlowLayoutPanel();
        labelSelectPaths = new Label();
        selectFile = new Button();
        password = new TextBox();
        execute = new Button();
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
        tableLayoutPanel1.Controls.Add(selectEncrypt, 0, 0);
        tableLayoutPanel1.Controls.Add(selectDecrypt, 1, 0);
        tableLayoutPanel1.Controls.Add(flowLayoutPanel1, 0, 2);
        tableLayoutPanel1.Controls.Add(selectFile, 0, 1);
        tableLayoutPanel1.Controls.Add(password, 0, 3);
        tableLayoutPanel1.Controls.Add(execute, 0, 4);
        tableLayoutPanel1.Location = new Point(12, 11);
        tableLayoutPanel1.Margin = new Padding(3, 2, 3, 2);
        tableLayoutPanel1.Name = "tableLayoutPanel1";
        tableLayoutPanel1.RowCount = 5;
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 10.4836092F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 13.2337246F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 52.4180679F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 7.02926159F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 16.83534F));
        tableLayoutPanel1.Size = new Size(379, 475);
        tableLayoutPanel1.TabIndex = 0;
        // 
        // selectEncrypt
        // 
        selectEncrypt.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        selectEncrypt.Location = new Point(3, 2);
        selectEncrypt.Margin = new Padding(3, 2, 3, 2);
        selectEncrypt.Name = "selectEncrypt";
        selectEncrypt.Size = new Size(183, 45);
        selectEncrypt.TabIndex = 0;
        selectEncrypt.Text = "加密";
        selectEncrypt.UseVisualStyleBackColor = true;
        selectEncrypt.Click += selectEncrypt_Click;
        // 
        // selectDecrypt
        // 
        selectDecrypt.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        selectDecrypt.Location = new Point(192, 2);
        selectDecrypt.Margin = new Padding(3, 2, 3, 2);
        selectDecrypt.Name = "selectDecrypt";
        selectDecrypt.Size = new Size(184, 45);
        selectDecrypt.TabIndex = 1;
        selectDecrypt.Text = "解密";
        selectDecrypt.UseVisualStyleBackColor = true;
        selectDecrypt.Click += selectDecrypt_Click;
        // 
        // flowLayoutPanel1
        // 
        flowLayoutPanel1.AutoScroll = true;
        flowLayoutPanel1.BorderStyle = BorderStyle.FixedSingle;
        tableLayoutPanel1.SetColumnSpan(flowLayoutPanel1, 2);
        flowLayoutPanel1.Controls.Add(labelSelectPaths);
        flowLayoutPanel1.Location = new Point(3, 113);
        flowLayoutPanel1.Margin = new Padding(3, 2, 3, 2);
        flowLayoutPanel1.Name = "flowLayoutPanel1";
        flowLayoutPanel1.Size = new Size(373, 244);
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
        // selectFile
        // 
        tableLayoutPanel1.SetColumnSpan(selectFile, 2);
        selectFile.Enabled = false;
        selectFile.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        selectFile.Location = new Point(3, 51);
        selectFile.Margin = new Padding(3, 2, 3, 2);
        selectFile.Name = "selectFile";
        selectFile.Size = new Size(373, 58);
        selectFile.TabIndex = 5;
        selectFile.Text = "選取檔案";
        selectFile.UseVisualStyleBackColor = true;
        selectFile.Click += selectFile_Click;
        // 
        // password
        // 
        password.Anchor = AnchorStyles.Left;
        tableLayoutPanel1.SetColumnSpan(password, 2);
        password.Enabled = false;
        password.Font = new Font("DFKai-SB", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
        password.Location = new Point(3, 364);
        password.Margin = new Padding(3, 2, 3, 2);
        password.Name = "password";
        password.Size = new Size(373, 23);
        password.TabIndex = 4;
        password.Text = "請輸入密碼。注意！如果忘記則無法解開檔案！";
        password.Enter += password_Enter;
        password.Leave += password_Leave;
        // 
        // execute
        // 
        tableLayoutPanel1.SetColumnSpan(execute, 2);
        execute.Enabled = false;
        execute.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
        execute.Location = new Point(3, 395);
        execute.Name = "execute";
        execute.Size = new Size(373, 77);
        execute.TabIndex = 6;
        execute.Text = "執行";
        execute.UseVisualStyleBackColor = true;
        execute.Click += execute_Click;
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
        tableLayoutPanel2.Location = new Point(410, 11);
        tableLayoutPanel2.Margin = new Padding(4, 5, 4, 5);
        tableLayoutPanel2.Name = "tableLayoutPanel2";
        tableLayoutPanel2.RowCount = 5;
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 10.6232738F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 15.9904537F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 10.501193F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 12.4105015F));
        tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 51.0739861F));
        tableLayoutPanel2.Size = new Size(347, 419);
        tableLayoutPanel2.TabIndex = 1;
        // 
        // encryptionAlgorithmSelector
        // 
        encryptionAlgorithmSelector.Anchor = AnchorStyles.Left;
        tableLayoutPanel2.SetColumnSpan(encryptionAlgorithmSelector, 2);
        encryptionAlgorithmSelector.Enabled = false;
        encryptionAlgorithmSelector.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point);
        encryptionAlgorithmSelector.FormattingEnabled = true;
        encryptionAlgorithmSelector.Items.AddRange(new object[] { "AES", "ChaCha20", "Camellia", "Twofish", "Blowfish", "3DES" });
        encryptionAlgorithmSelector.Location = new Point(4, 9);
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
        prefixUse.Enabled = false;
        prefixUse.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        prefixUse.Location = new Point(4, 160);
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
        cipherBitsSelectGroup.Location = new Point(4, 49);
        cipherBitsSelectGroup.Margin = new Padding(4, 5, 4, 5);
        cipherBitsSelectGroup.Name = "cipherBitsSelectGroup";
        cipherBitsSelectGroup.Padding = new Padding(4, 5, 4, 5);
        cipherBitsSelectGroup.Size = new Size(339, 54);
        cipherBitsSelectGroup.TabIndex = 2;
        cipherBitsSelectGroup.TabStop = false;
        cipherBitsSelectGroup.Text = "密鑰長度 (bits)";
        // 
        // keySize_128
        // 
        keySize_128.Anchor = AnchorStyles.Top;
        keySize_128.AutoSize = true;
        keySize_128.Checked = true;
        keySize_128.Enabled = false;
        keySize_128.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point);
        keySize_128.Location = new Point(53, 25);
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
        keySize_256.Enabled = false;
        keySize_256.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point);
        keySize_256.Location = new Point(221, 25);
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
        deleteOriginalFile.Enabled = false;
        deleteOriginalFile.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        deleteOriginalFile.Location = new Point(4, 121);
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
        extraEntropy.Enabled = false;
        extraEntropy.Font = new Font("Arial", 12.75F, FontStyle.Regular, GraphicsUnit.Point);
        extraEntropy.Location = new Point(4, 209);
        extraEntropy.Margin = new Padding(4, 5, 4, 5);
        extraEntropy.Multiline = true;
        extraEntropy.Name = "extraEntropy";
        extraEntropy.ScrollBars = ScrollBars.Vertical;
        extraEntropy.Size = new Size(337, 205);
        extraEntropy.TabIndex = 3;
        extraEntropy.Text = "請在這裡打上一些東西，你不需要記得你輸入了什麼。\r\n這是額外的熵，用於增加亂數的品質。";
        extraEntropy.Enter += extraEntropy_Enter;
        extraEntropy.Leave += extraEntropy_Leave;
        // 
        // Form1
        // 
        AutoScaleDimensions = new SizeF(8F, 18F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(770, 494);
        Controls.Add(tableLayoutPanel2);
        Controls.Add(tableLayoutPanel1);
        Margin = new Padding(3, 2, 3, 2);
        MaximizeBox = false;
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
    private Button selectEncrypt;
    private TextBox password;
    private Button selectFile;
    private FlowLayoutPanel flowLayoutPanel1;
    private Label labelSelectPaths;
    private Button selectDecrypt;
    private TableLayoutPanel tableLayoutPanel2;
    private CheckBox deleteOriginalFile;
    private CheckBox prefixUse;
    private ComboBox encryptionAlgorithmSelector;
    private RadioButton keySize_128;
    private RadioButton keySize_256;
    private GroupBox cipherBitsSelectGroup;
    private TextBox extraEntropy;
    private Button execute;
}