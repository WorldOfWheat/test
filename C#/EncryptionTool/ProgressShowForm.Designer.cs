partial class ProgressShowForm
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
        progressBar = new ProgressBar();
        cancel = new Button();
        tableLayoutPanel1 = new TableLayoutPanel();
        tableLayoutPanel1.SuspendLayout();
        SuspendLayout();
        // 
        // progressBar
        // 
        progressBar.Location = new Point(3, 37);
        progressBar.Margin = new Padding(3, 4, 3, 4);
        progressBar.Name = "progressBar";
        progressBar.Size = new Size(428, 25);
        progressBar.TabIndex = 0;
        progressBar.Value = 50;
        // 
        // cancel
        // 
        cancel.Anchor = AnchorStyles.Top;
        cancel.Location = new Point(139, 70);
        cancel.Margin = new Padding(3, 4, 3, 4);
        cancel.Name = "cancel";
        cancel.Size = new Size(155, 26);
        cancel.TabIndex = 1;
        cancel.Text = "取消";
        cancel.UseVisualStyleBackColor = true;
        cancel.Click += cancel_Click;
        // 
        // tableLayoutPanel1
        // 
        tableLayoutPanel1.ColumnCount = 1;
        tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100F));
        tableLayoutPanel1.Controls.Add(progressBar, 0, 1);
        tableLayoutPanel1.Controls.Add(cancel, 0, 2);
        tableLayoutPanel1.Location = new Point(12, 12);
        tableLayoutPanel1.Name = "tableLayoutPanel1";
        tableLayoutPanel1.RowCount = 3;
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333321F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333321F));
        tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333321F));
        tableLayoutPanel1.Size = new Size(434, 100);
        tableLayoutPanel1.TabIndex = 2;
        // 
        // ProgressShowForm
        // 
        AutoScaleDimensions = new SizeF(8F, 18F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(459, 127);
        Controls.Add(tableLayoutPanel1);
        Margin = new Padding(3, 4, 3, 4);
        MaximizeBox = false;
        Name = "ProgressShowForm";
        Text = "進度";
        FormClosing += ProgressShowForm_FormClosing;
        Load += ProgressShowForm_Load;
        tableLayoutPanel1.ResumeLayout(false);
        ResumeLayout(false);
    }

    #endregion

    private ProgressBar progressBar;
    private Button cancel;
    private TableLayoutPanel tableLayoutPanel1;
}