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
            tableLayoutPanel1 = new TableLayoutPanel();
            flowLayoutPanel1 = new FlowLayoutPanel();
            labelSelectPaths = new Label();
            buttonExecuteEncrypt = new Button();
            buttonExecuteDecrypt = new Button();
            textBoxPassword = new TextBox();
            buttonSelectFile = new Button();
            tableLayoutPanel1.SuspendLayout();
            flowLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.Controls.Add(flowLayoutPanel1, 0, 1);
            tableLayoutPanel1.Controls.Add(buttonExecuteEncrypt, 0, 3);
            tableLayoutPanel1.Controls.Add(buttonExecuteDecrypt, 1, 3);
            tableLayoutPanel1.Controls.Add(textBoxPassword, 0, 2);
            tableLayoutPanel1.Controls.Add(buttonSelectFile, 0, 0);
            tableLayoutPanel1.Location = new Point(12, 11);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 4;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25.50844F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50.6698875F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 8.620703F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15.2009668F));
            tableLayoutPanel1.Size = new Size(378, 401);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // flowLayoutPanel1
            // 
            flowLayoutPanel1.AutoScroll = true;
            flowLayoutPanel1.BorderStyle = BorderStyle.FixedSingle;
            tableLayoutPanel1.SetColumnSpan(flowLayoutPanel1, 2);
            flowLayoutPanel1.Controls.Add(labelSelectPaths);
            flowLayoutPanel1.Location = new Point(3, 105);
            flowLayoutPanel1.Name = "flowLayoutPanel1";
            flowLayoutPanel1.Size = new Size(372, 197);
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
            // buttonExecuteEncrypt
            // 
            buttonExecuteEncrypt.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
            buttonExecuteEncrypt.Location = new Point(3, 342);
            buttonExecuteEncrypt.Name = "buttonExecuteEncrypt";
            buttonExecuteEncrypt.Size = new Size(183, 56);
            buttonExecuteEncrypt.TabIndex = 0;
            buttonExecuteEncrypt.Text = "加密";
            buttonExecuteEncrypt.UseVisualStyleBackColor = true;
            buttonExecuteEncrypt.Click += button1_Click;
            // 
            // buttonExecuteDecrypt
            // 
            buttonExecuteDecrypt.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
            buttonExecuteDecrypt.Location = new Point(192, 342);
            buttonExecuteDecrypt.Name = "buttonExecuteDecrypt";
            buttonExecuteDecrypt.Size = new Size(183, 56);
            buttonExecuteDecrypt.TabIndex = 1;
            buttonExecuteDecrypt.Text = "解密";
            buttonExecuteDecrypt.UseVisualStyleBackColor = true;
            buttonExecuteDecrypt.Click += button2_Click;
            // 
            // textBoxPassword
            // 
            tableLayoutPanel1.SetColumnSpan(textBoxPassword, 2);
            textBoxPassword.Font = new Font("Microsoft JhengHei UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            textBoxPassword.Location = new Point(3, 308);
            textBoxPassword.Name = "textBoxPassword";
            textBoxPassword.PasswordChar = '*';
            textBoxPassword.Size = new Size(372, 28);
            textBoxPassword.TabIndex = 4;
            // 
            // buttonSelectFile
            // 
            tableLayoutPanel1.SetColumnSpan(buttonSelectFile, 2);
            buttonSelectFile.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
            buttonSelectFile.Location = new Point(3, 3);
            buttonSelectFile.Name = "buttonSelectFile";
            buttonSelectFile.Size = new Size(372, 96);
            buttonSelectFile.TabIndex = 5;
            buttonSelectFile.Text = "選取檔案";
            buttonSelectFile.UseVisualStyleBackColor = true;
            buttonSelectFile.Click += buttonSelectFile_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 18F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(885, 448);
            Controls.Add(tableLayoutPanel1);
            Name = "Form1";
            Text = "檔案加密工具";
            Load += Form1_Load;
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel1.PerformLayout();
            flowLayoutPanel1.ResumeLayout(false);
            flowLayoutPanel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Button buttonExecuteEncrypt;
        private TextBox textBoxPassword;
        private Button buttonSelectFile;
        private FlowLayoutPanel flowLayoutPanel1;
        private Label labelSelectPaths;
        private Button buttonExecuteDecrypt;
    }
}