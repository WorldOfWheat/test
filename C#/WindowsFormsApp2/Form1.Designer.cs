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
            this.textBoxPassword = new System.Windows.Forms.TextBox();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.labelSelectPaths = new System.Windows.Forms.Label();
            this.buttonExecuteEncrypt = new System.Windows.Forms.Button();
            this.buttonExecuteDecrypt = new System.Windows.Forms.Button();
            this.buttonSelectFile = new System.Windows.Forms.Button();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.deleteOriginalFile = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.cipher = new System.Windows.Forms.ComboBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.textBoxPassword, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel1, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.buttonExecuteEncrypt, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.buttonExecuteDecrypt, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.buttonSelectFile, 0, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(9, 7);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25.50844F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50.66989F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 8.620703F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.20097F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(284, 351);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // textBoxPassword
            // 
            this.tableLayoutPanel1.SetColumnSpan(this.textBoxPassword, 2);
            this.textBoxPassword.Font = new System.Drawing.Font("Microsoft JhengHei UI", 12F);
            this.textBoxPassword.Location = new System.Drawing.Point(2, 268);
            this.textBoxPassword.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textBoxPassword.Name = "textBoxPassword";
            this.textBoxPassword.PasswordChar = '*';
            this.textBoxPassword.Size = new System.Drawing.Size(280, 28);
            this.textBoxPassword.TabIndex = 4;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.AutoScroll = true;
            this.flowLayoutPanel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tableLayoutPanel1.SetColumnSpan(this.flowLayoutPanel1, 2);
            this.flowLayoutPanel1.Controls.Add(this.labelSelectPaths);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(2, 91);
            this.flowLayoutPanel1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(280, 173);
            this.flowLayoutPanel1.TabIndex = 1;
            // 
            // labelSelectPaths
            // 
            this.labelSelectPaths.AutoSize = true;
            this.labelSelectPaths.Font = new System.Drawing.Font("PMingLiU", 12F);
            this.labelSelectPaths.Location = new System.Drawing.Point(2, 0);
            this.labelSelectPaths.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelSelectPaths.Name = "labelSelectPaths";
            this.labelSelectPaths.Size = new System.Drawing.Size(45, 16);
            this.labelSelectPaths.TabIndex = 0;
            this.labelSelectPaths.Text = "label1";
            // 
            // buttonExecuteEncrypt
            // 
            this.buttonExecuteEncrypt.Font = new System.Drawing.Font("DFKai-SB", 18F);
            this.buttonExecuteEncrypt.Location = new System.Drawing.Point(2, 298);
            this.buttonExecuteEncrypt.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.buttonExecuteEncrypt.Name = "buttonExecuteEncrypt";
            this.buttonExecuteEncrypt.Size = new System.Drawing.Size(137, 51);
            this.buttonExecuteEncrypt.TabIndex = 0;
            this.buttonExecuteEncrypt.Text = "加密";
            this.buttonExecuteEncrypt.UseVisualStyleBackColor = true;
            this.buttonExecuteEncrypt.Click += new System.EventHandler(this.buttonExecuteEncrypt_Click);
            // 
            // buttonExecuteDecrypt
            // 
            this.buttonExecuteDecrypt.Font = new System.Drawing.Font("DFKai-SB", 18F);
            this.buttonExecuteDecrypt.Location = new System.Drawing.Point(144, 298);
            this.buttonExecuteDecrypt.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.buttonExecuteDecrypt.Name = "buttonExecuteDecrypt";
            this.buttonExecuteDecrypt.Size = new System.Drawing.Size(137, 51);
            this.buttonExecuteDecrypt.TabIndex = 1;
            this.buttonExecuteDecrypt.Text = "解密";
            this.buttonExecuteDecrypt.UseVisualStyleBackColor = true;
            this.buttonExecuteDecrypt.Click += new System.EventHandler(this.buttonExecuteDecrypt_Click);
            // 
            // buttonSelectFile
            // 
            this.tableLayoutPanel1.SetColumnSpan(this.buttonSelectFile, 2);
            this.buttonSelectFile.Font = new System.Drawing.Font("DFKai-SB", 18F);
            this.buttonSelectFile.Location = new System.Drawing.Point(2, 2);
            this.buttonSelectFile.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.buttonSelectFile.Name = "buttonSelectFile";
            this.buttonSelectFile.Size = new System.Drawing.Size(279, 85);
            this.buttonSelectFile.TabIndex = 5;
            this.buttonSelectFile.Text = "選取檔案";
            this.buttonSelectFile.UseVisualStyleBackColor = true;
            this.buttonSelectFile.Click += new System.EventHandler(this.buttonSelectFile_Click_1);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 1;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.Controls.Add(this.checkBox1, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.deleteOriginalFile, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.cipher, 0, 0);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(310, 7);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 5;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(200, 222);
            this.tableLayoutPanel2.TabIndex = 1;
            // 
            // deleteOriginalFile
            // 
            this.deleteOriginalFile.AutoSize = true;
            this.deleteOriginalFile.Font = new System.Drawing.Font("DFKai-SB", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.deleteOriginalFile.Location = new System.Drawing.Point(3, 47);
            this.deleteOriginalFile.Name = "deleteOriginalFile";
            this.deleteOriginalFile.Size = new System.Drawing.Size(122, 20);
            this.deleteOriginalFile.TabIndex = 0;
            this.deleteOriginalFile.Text = "是否刪除原檔";
            this.deleteOriginalFile.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Font = new System.Drawing.Font("DFKai-SB", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.checkBox1.Location = new System.Drawing.Point(3, 91);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(154, 36);
            this.checkBox1.TabIndex = 1;
            this.checkBox1.Text = "是否使用檔名前綴\r\nENC_、DEC_";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // cipher
            // 
            this.cipher.Font = new System.Drawing.Font("DFKai-SB", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.cipher.FormattingEnabled = true;
            this.cipher.Items.AddRange(new object[] {
            "AES",
            "Twofish",
            "ChaCha20",
            "Camellia"});
            this.cipher.Location = new System.Drawing.Point(3, 3);
            this.cipher.Name = "cipher";
            this.cipher.Size = new System.Drawing.Size(121, 24);
            this.cipher.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(683, 370);
            this.Controls.Add(this.tableLayoutPanel2);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.Text = "檔案加密工具";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Button buttonExecuteEncrypt;
        private TextBox textBoxPassword;
        private Button buttonSelectFile;
        private FlowLayoutPanel flowLayoutPanel1;
        private Label labelSelectPaths;
        private Button buttonExecuteDecrypt;
        private TableLayoutPanel tableLayoutPanel2;
        private CheckBox deleteOriginalFile;
        private CheckBox checkBox1;
        private ComboBox cipher;
    }
}