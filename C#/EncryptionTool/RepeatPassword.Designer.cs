partial class RepeatPasswordForm
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
        pleaseInputRepeatPassword = new Label();
        confirm = new Button();
        cancel = new Button();
        repeatPassword = new TextBox();
        tableLayoutPanel1.SuspendLayout();
        SuspendLayout();
        // 
        // tableLayoutPanel1
        // 
        tableLayoutPanel1.ColumnCount = 2;
        tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        tableLayoutPanel1.Controls.Add(pleaseInputRepeatPassword, 0, 0);
        tableLayoutPanel1.Controls.Add(confirm, 0, 2);
        tableLayoutPanel1.Controls.Add(cancel, 1, 2);
        tableLayoutPanel1.Controls.Add(repeatPassword, 0, 1);
        tableLayoutPanel1.Location = new Point(12, 11);
        tableLayoutPanel1.Name = "tableLayoutPanel1";
        tableLayoutPanel1.RowCount = 3;
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3344421F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.334446F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3311157F));
        tableLayoutPanel1.Size = new Size(423, 127);
        tableLayoutPanel1.TabIndex = 0;
        // 
        // pleaseInputRepeatPassword
        // 
        pleaseInputRepeatPassword.Anchor = AnchorStyles.Left;
        pleaseInputRepeatPassword.AutoSize = true;
        pleaseInputRepeatPassword.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        pleaseInputRepeatPassword.Location = new Point(3, 13);
        pleaseInputRepeatPassword.Name = "pleaseInputRepeatPassword";
        pleaseInputRepeatPassword.Size = new Size(119, 16);
        pleaseInputRepeatPassword.TabIndex = 4;
        pleaseInputRepeatPassword.Text = "請再次輸入密碼";
        // 
        // confirm
        // 
        confirm.Anchor = AnchorStyles.None;
        confirm.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        confirm.Location = new Point(3, 92);
        confirm.Name = "confirm";
        confirm.Size = new Size(205, 26);
        confirm.TabIndex = 2;
        confirm.Text = " 確認";
        confirm.UseVisualStyleBackColor = true;
        confirm.Click += confirm_Click;
        // 
        // cancel
        // 
        cancel.Anchor = AnchorStyles.None;
        cancel.Font = new Font("DFKai-SB", 12F, FontStyle.Regular, GraphicsUnit.Point);
        cancel.Location = new Point(214, 92);
        cancel.Name = "cancel";
        cancel.Size = new Size(206, 26);
        cancel.TabIndex = 3;
        cancel.Text = "取消";
        cancel.UseVisualStyleBackColor = true;
        cancel.Click += cancel_Click;
        // 
        // repeatPassword
        // 
        repeatPassword.Anchor = AnchorStyles.Left;
        tableLayoutPanel1.SetColumnSpan(repeatPassword, 2);
        repeatPassword.Font = new Font("DFKai-SB", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
        repeatPassword.Location = new Point(3, 51);
        repeatPassword.Name = "repeatPassword";
        repeatPassword.Size = new Size(417, 24);
        repeatPassword.TabIndex = 1;
        repeatPassword.Enter += repeatPassword_Enter;
        repeatPassword.KeyPress += repeatPassword_KeyPress;
        repeatPassword.Leave += repeatPassword_Leave;
        // 
        // RepeatPasswordForm
        // 
        AutoScaleDimensions = new SizeF(8F, 18F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(447, 148);
        Controls.Add(tableLayoutPanel1);
        MaximizeBox = false;
        MinimizeBox = false;
        Name = "RepeatPasswordForm";
        StartPosition = FormStartPosition.CenterScreen;
        Text = "密碼確認";
        Load += repeatPasswordForm_Load;
        tableLayoutPanel1.ResumeLayout(false);
        tableLayoutPanel1.PerformLayout();
        ResumeLayout(false);
    }

    #endregion

    private TableLayoutPanel tableLayoutPanel1;
    private Label pleaseRepeatPassword;
    private TextBox repeatPassword;
    private Button confirm;
    private Button cancel;
    private Label pleaseInputRepeatPassword;
}