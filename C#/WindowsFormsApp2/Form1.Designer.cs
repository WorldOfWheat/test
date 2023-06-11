using System.Drawing;
using System.Windows.Forms;

namespace WinFormsApp1
{
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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.password = new System.Windows.Forms.TextBox();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.labelSelectPaths = new System.Windows.Forms.Label();
            this.executeEncrypt = new System.Windows.Forms.Button();
            this.executeDecrypt = new System.Windows.Forms.Button();
            this.buttonSelectFile = new System.Windows.Forms.Button();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.cipherSelect = new System.Windows.Forms.ComboBox();
            this.prefixUse = new System.Windows.Forms.CheckBox();
            this.cipherBitsSelectGroup = new System.Windows.Forms.GroupBox();
            this.keySize_128 = new System.Windows.Forms.RadioButton();
            this.keySize_256 = new System.Windows.Forms.RadioButton();
            this.deleteOriginalFile = new System.Windows.Forms.CheckBox();
            this.extraEntropy = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.cipherBitsSelectGroup.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.password, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel1, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.executeEncrypt, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.executeDecrypt, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.buttonSelectFile, 0, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(12, 9);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25.50844F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50.66989F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 8.620703F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.20097F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(379, 439);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // password
            // 
            this.password.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.tableLayoutPanel1.SetColumnSpan(this.password, 2);
            this.password.Font = new System.Drawing.Font("DFKai-SB", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.password.Location = new System.Drawing.Point(3, 339);
            this.password.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.password.Name = "password";
            this.password.Size = new System.Drawing.Size(372, 25);
            this.password.TabIndex = 4;
            this.password.Text = "請輸入密碼。注意！如果忘記則無法解密檔案！";
            this.password.Enter += new System.EventHandler(this.password_Enter);
            this.password.Leave += new System.EventHandler(this.password_Leave);
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.AutoScroll = true;
            this.flowLayoutPanel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tableLayoutPanel1.SetColumnSpan(this.flowLayoutPanel1, 2);
            this.flowLayoutPanel1.Controls.Add(this.labelSelectPaths);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(3, 113);
            this.flowLayoutPanel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(373, 216);
            this.flowLayoutPanel1.TabIndex = 1;
            // 
            // labelSelectPaths
            // 
            this.labelSelectPaths.AutoSize = true;
            this.labelSelectPaths.Font = new System.Drawing.Font("PMingLiU", 12F);
            this.labelSelectPaths.Location = new System.Drawing.Point(3, 0);
            this.labelSelectPaths.Name = "labelSelectPaths";
            this.labelSelectPaths.Size = new System.Drawing.Size(53, 20);
            this.labelSelectPaths.TabIndex = 0;
            this.labelSelectPaths.Text = "label1";
            // 
            // executeEncrypt
            // 
            this.executeEncrypt.Font = new System.Drawing.Font("DFKai-SB", 18F);
            this.executeEncrypt.Location = new System.Drawing.Point(3, 372);
            this.executeEncrypt.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.executeEncrypt.Name = "executeEncrypt";
            this.executeEncrypt.Size = new System.Drawing.Size(183, 64);
            this.executeEncrypt.TabIndex = 0;
            this.executeEncrypt.Text = "加密";
            this.executeEncrypt.UseVisualStyleBackColor = true;
            this.executeEncrypt.Click += new System.EventHandler(this.buttonExecuteEncrypt_Click);
            // 
            // executeDecrypt
            // 
            this.executeDecrypt.Font = new System.Drawing.Font("DFKai-SB", 18F);
            this.executeDecrypt.Location = new System.Drawing.Point(192, 372);
            this.executeDecrypt.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.executeDecrypt.Name = "executeDecrypt";
            this.executeDecrypt.Size = new System.Drawing.Size(183, 64);
            this.executeDecrypt.TabIndex = 1;
            this.executeDecrypt.Text = "解密";
            this.executeDecrypt.UseVisualStyleBackColor = true;
            this.executeDecrypt.Click += new System.EventHandler(this.buttonExecuteDecrypt_Click);
            // 
            // buttonSelectFile
            // 
            this.tableLayoutPanel1.SetColumnSpan(this.buttonSelectFile, 2);
            this.buttonSelectFile.Font = new System.Drawing.Font("DFKai-SB", 18F);
            this.buttonSelectFile.Location = new System.Drawing.Point(3, 2);
            this.buttonSelectFile.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonSelectFile.Name = "buttonSelectFile";
            this.buttonSelectFile.Size = new System.Drawing.Size(372, 106);
            this.buttonSelectFile.TabIndex = 5;
            this.buttonSelectFile.Text = "選取檔案";
            this.buttonSelectFile.UseVisualStyleBackColor = true;
            this.buttonSelectFile.Click += new System.EventHandler(this.buttonSelectFile_Click_1);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.Controls.Add(this.cipherSelect, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.prefixUse, 0, 3);
            this.tableLayoutPanel2.Controls.Add(this.cipherBitsSelectGroup, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.deleteOriginalFile, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.extraEntropy, 0, 4);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(413, 9);
            this.tableLayoutPanel2.Margin = new System.Windows.Forms.Padding(4);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 5;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.38461F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.38461F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.38461F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.38461F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 38.46154F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(347, 436);
            this.tableLayoutPanel2.TabIndex = 1;
            // 
            // cipherSelect
            // 
            this.cipherSelect.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.tableLayoutPanel2.SetColumnSpan(this.cipherSelect, 2);
            this.cipherSelect.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cipherSelect.FormattingEnabled = true;
            this.cipherSelect.Items.AddRange(new object[] {
            "AES",
            "Twofish",
            "ChaCha20",
            "Camellia"});
            this.cipherSelect.Location = new System.Drawing.Point(4, 18);
            this.cipherSelect.Margin = new System.Windows.Forms.Padding(4);
            this.cipherSelect.Name = "cipherSelect";
            this.cipherSelect.Size = new System.Drawing.Size(337, 31);
            this.cipherSelect.TabIndex = 2;
            // 
            // prefixUse
            // 
            this.prefixUse.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.prefixUse.AutoSize = true;
            this.tableLayoutPanel2.SetColumnSpan(this.prefixUse, 2);
            this.prefixUse.Font = new System.Drawing.Font("DFKai-SB", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.prefixUse.Location = new System.Drawing.Point(4, 212);
            this.prefixUse.Margin = new System.Windows.Forms.Padding(4);
            this.prefixUse.Name = "prefixUse";
            this.prefixUse.Size = new System.Drawing.Size(191, 44);
            this.prefixUse.TabIndex = 1;
            this.prefixUse.Text = "是否使用檔名前綴\r\nENC_、DEC_";
            this.prefixUse.UseVisualStyleBackColor = true;
            this.prefixUse.CheckStateChanged += new System.EventHandler(this.prefixUse_CheckStateChanged);
            // 
            // cipherBitsSelectGroup
            // 
            this.tableLayoutPanel2.SetColumnSpan(this.cipherBitsSelectGroup, 2);
            this.cipherBitsSelectGroup.Controls.Add(this.keySize_128);
            this.cipherBitsSelectGroup.Controls.Add(this.keySize_256);
            this.cipherBitsSelectGroup.Font = new System.Drawing.Font("DFKai-SB", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.cipherBitsSelectGroup.Location = new System.Drawing.Point(4, 71);
            this.cipherBitsSelectGroup.Margin = new System.Windows.Forms.Padding(4);
            this.cipherBitsSelectGroup.Name = "cipherBitsSelectGroup";
            this.cipherBitsSelectGroup.Padding = new System.Windows.Forms.Padding(4);
            this.cipherBitsSelectGroup.Size = new System.Drawing.Size(339, 59);
            this.cipherBitsSelectGroup.TabIndex = 2;
            this.cipherBitsSelectGroup.TabStop = false;
            this.cipherBitsSelectGroup.Text = "密鑰長度";
            // 
            // keySize_128
            // 
            this.keySize_128.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.keySize_128.AutoSize = true;
            this.keySize_128.Checked = true;
            this.keySize_128.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.keySize_128.Location = new System.Drawing.Point(54, 24);
            this.keySize_128.Margin = new System.Windows.Forms.Padding(4);
            this.keySize_128.Name = "keySize_128";
            this.keySize_128.Size = new System.Drawing.Size(64, 27);
            this.keySize_128.TabIndex = 3;
            this.keySize_128.TabStop = true;
            this.keySize_128.Text = "128";
            this.keySize_128.UseVisualStyleBackColor = true;
            // 
            // keySize_256
            // 
            this.keySize_256.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.keySize_256.AutoSize = true;
            this.keySize_256.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.keySize_256.Location = new System.Drawing.Point(219, 24);
            this.keySize_256.Margin = new System.Windows.Forms.Padding(4);
            this.keySize_256.Name = "keySize_256";
            this.keySize_256.Size = new System.Drawing.Size(64, 27);
            this.keySize_256.TabIndex = 4;
            this.keySize_256.Text = "256";
            this.keySize_256.UseVisualStyleBackColor = true;
            // 
            // deleteOriginalFile
            // 
            this.deleteOriginalFile.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.deleteOriginalFile.AutoSize = true;
            this.deleteOriginalFile.Checked = true;
            this.deleteOriginalFile.CheckState = System.Windows.Forms.CheckState.Checked;
            this.tableLayoutPanel2.SetColumnSpan(this.deleteOriginalFile, 2);
            this.deleteOriginalFile.Font = new System.Drawing.Font("DFKai-SB", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.deleteOriginalFile.Location = new System.Drawing.Point(4, 155);
            this.deleteOriginalFile.Margin = new System.Windows.Forms.Padding(4);
            this.deleteOriginalFile.Name = "deleteOriginalFile";
            this.deleteOriginalFile.Size = new System.Drawing.Size(151, 24);
            this.deleteOriginalFile.TabIndex = 0;
            this.deleteOriginalFile.Text = "是否刪除原檔";
            this.deleteOriginalFile.UseVisualStyleBackColor = true;
            this.deleteOriginalFile.CheckStateChanged += new System.EventHandler(this.deleteOriginalFile_CheckStateChanged);
            // 
            // extraEntropy
            // 
            this.tableLayoutPanel2.SetColumnSpan(this.extraEntropy, 2);
            this.extraEntropy.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.extraEntropy.Location = new System.Drawing.Point(4, 272);
            this.extraEntropy.Margin = new System.Windows.Forms.Padding(4);
            this.extraEntropy.Multiline = true;
            this.extraEntropy.Name = "extraEntropy";
            this.extraEntropy.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.extraEntropy.Size = new System.Drawing.Size(337, 160);
            this.extraEntropy.TabIndex = 3;
            this.extraEntropy.Text = "請在這裡打上一些東西，你不需要記得你輸入了什麼。";
            this.extraEntropy.Enter += new System.EventHandler(this.extraEntropy_Enter);
            this.extraEntropy.Leave += new System.EventHandler(this.extraEntropy_Leave);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 468);
            this.Controls.Add(this.tableLayoutPanel2);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "檔案加密工具";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.cipherBitsSelectGroup.ResumeLayout(false);
            this.cipherBitsSelectGroup.PerformLayout();
            this.ResumeLayout(false);

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
        private ComboBox cipherSelect;
        private RadioButton keySize_128;
        private RadioButton keySize_256;
        private GroupBox cipherBitsSelectGroup;
        private TextBox extraEntropy;
    }
}