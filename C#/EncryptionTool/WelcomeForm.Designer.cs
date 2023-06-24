namespace EncryptionTool
{
    partial class WelcomeForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tableLayoutPanel1 = new TableLayoutPanel();
            confirm = new Button();
            info = new Label();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 1;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100F));
            tableLayoutPanel1.Controls.Add(confirm, 0, 1);
            tableLayoutPanel1.Controls.Add(info, 0, 0);
            tableLayoutPanel1.Location = new Point(12, 12);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 2;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 66.442955F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.55705F));
            tableLayoutPanel1.Size = new Size(228, 159);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // confirm
            // 
            confirm.Anchor = AnchorStyles.None;
            confirm.Font = new Font("DFKai-SB", 18F, FontStyle.Regular, GraphicsUnit.Point);
            confirm.Location = new Point(55, 113);
            confirm.Name = "confirm";
            confirm.Size = new Size(118, 38);
            confirm.TabIndex = 0;
            confirm.Text = "確定";
            confirm.UseVisualStyleBackColor = true;
            confirm.Click += confirm_Click;
            // 
            // info
            // 
            info.Anchor = AnchorStyles.None;
            info.AutoSize = true;
            info.Font = new Font("DFKai-SB", 15.75F, FontStyle.Regular, GraphicsUnit.Point);
            info.Location = new Point(15, 10);
            info.Name = "info";
            info.Size = new Size(197, 84);
            info.TabIndex = 1;
            info.Text = "歡迎使用加密工具\r\n作者：小麥\r\n版本：v1.0\r\n本程式使用MIT條款";
            info.TextAlign = ContentAlignment.MiddleCenter;
            info.UseWaitCursor = true;
            // 
            // WelcomeForm
            // 
            AutoScaleDimensions = new SizeF(8F, 18F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(250, 179);
            Controls.Add(tableLayoutPanel1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MaximizeBox = false;
            Name = "WelcomeForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "歡迎";
            FormClosing += WelcomeForm_FormClosing;
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Button confirm;
        private Label info;
    }
}