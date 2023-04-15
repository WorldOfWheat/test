namespace WinFormsApp1
{
    partial class Form1
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
            components = new System.ComponentModel.Container();
            tableLayoutPanel1 = new TableLayoutPanel();
            button0 = new Button();
            button3 = new Button();
            button2 = new Button();
            button1 = new Button();
            button6 = new Button();
            button5 = new Button();
            button4 = new Button();
            button9 = new Button();
            button8 = new Button();
            button7 = new Button();
            buttonShuffle = new Button();
            labelDataShow = new Label();
            textBox1 = new TextBox();
            tableLayoutPanel2 = new TableLayoutPanel();
            buttonCopy = new Button();
            buttonClear = new Button();
            labelClearSecond = new Label();
            timer1 = new System.Windows.Forms.Timer(components);
            tableLayoutPanel1.SuspendLayout();
            tableLayoutPanel2.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 3;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 34F));
            tableLayoutPanel1.Controls.Add(button0, 0, 3);
            tableLayoutPanel1.Controls.Add(button3, 2, 2);
            tableLayoutPanel1.Controls.Add(button2, 1, 2);
            tableLayoutPanel1.Controls.Add(button1, 0, 2);
            tableLayoutPanel1.Controls.Add(button6, 2, 1);
            tableLayoutPanel1.Controls.Add(button5, 1, 1);
            tableLayoutPanel1.Controls.Add(button4, 0, 1);
            tableLayoutPanel1.Controls.Add(button9, 2, 0);
            tableLayoutPanel1.Controls.Add(button8, 1, 0);
            tableLayoutPanel1.Controls.Add(button7, 0, 0);
            tableLayoutPanel1.Controls.Add(buttonShuffle, 2, 3);
            tableLayoutPanel1.Location = new Point(90, 33);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 4;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.Size = new Size(303, 372);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // button0
            // 
            tableLayoutPanel1.SetColumnSpan(button0, 2);
            button0.Location = new Point(3, 282);
            button0.Name = "button0";
            button0.Size = new Size(192, 87);
            button0.TabIndex = 9;
            button0.Text = "button10";
            button0.UseVisualStyleBackColor = true;
            button0.Click += button0_Click;
            // 
            // button3
            // 
            button3.Location = new Point(201, 189);
            button3.Name = "button3";
            button3.Size = new Size(99, 87);
            button3.TabIndex = 8;
            button3.Text = "button9";
            button3.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            button2.Location = new Point(102, 189);
            button2.Name = "button2";
            button2.Size = new Size(93, 87);
            button2.TabIndex = 7;
            button2.Text = "button8";
            button2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            button1.Location = new Point(3, 189);
            button1.Name = "button1";
            button1.Size = new Size(93, 87);
            button1.TabIndex = 6;
            button1.Text = "button7";
            button1.UseVisualStyleBackColor = true;
            // 
            // button6
            // 
            button6.Location = new Point(201, 96);
            button6.Name = "button6";
            button6.Size = new Size(99, 87);
            button6.TabIndex = 5;
            button6.Text = "button6";
            button6.UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            button5.Location = new Point(102, 96);
            button5.Name = "button5";
            button5.Size = new Size(93, 87);
            button5.TabIndex = 4;
            button5.Text = "button5";
            button5.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            button4.Location = new Point(3, 96);
            button4.Name = "button4";
            button4.Size = new Size(93, 87);
            button4.TabIndex = 3;
            button4.Text = "button4";
            button4.UseVisualStyleBackColor = true;
            // 
            // button9
            // 
            button9.Location = new Point(201, 3);
            button9.Name = "button9";
            button9.Size = new Size(99, 87);
            button9.TabIndex = 2;
            button9.Text = "button3";
            button9.UseVisualStyleBackColor = true;
            // 
            // button8
            // 
            button8.Location = new Point(102, 3);
            button8.Name = "button8";
            button8.Size = new Size(93, 87);
            button8.TabIndex = 1;
            button8.Text = "button2";
            button8.UseVisualStyleBackColor = true;
            // 
            // button7
            // 
            button7.Location = new Point(3, 3);
            button7.Name = "button7";
            button7.Size = new Size(93, 87);
            button7.TabIndex = 0;
            button7.Text = "button1";
            button7.UseVisualStyleBackColor = true;
            // 
            // buttonShuffle
            // 
            buttonShuffle.Location = new Point(201, 282);
            buttonShuffle.Name = "buttonShuffle";
            buttonShuffle.Size = new Size(99, 87);
            buttonShuffle.TabIndex = 10;
            buttonShuffle.Text = "button11";
            buttonShuffle.UseVisualStyleBackColor = true;
            // 
            // labelDataShow
            // 
            labelDataShow.AutoSize = true;
            tableLayoutPanel2.SetColumnSpan(labelDataShow, 2);
            labelDataShow.Font = new Font("Microsoft JhengHei UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            labelDataShow.Location = new Point(3, 0);
            labelDataShow.Name = "labelDataShow";
            labelDataShow.Size = new Size(85, 30);
            labelDataShow.TabIndex = 1;
            labelDataShow.Text = "輸入：";
            // 
            // textBox1
            // 
            tableLayoutPanel2.SetColumnSpan(textBox1, 3);
            textBox1.Font = new Font("Microsoft JhengHei UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            textBox1.Location = new Point(3, 69);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(280, 28);
            textBox1.TabIndex = 2;
            // 
            // tableLayoutPanel2
            // 
            tableLayoutPanel2.ColumnCount = 2;
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33.3333321F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33.3333321F));
            tableLayoutPanel2.Controls.Add(textBox1, 0, 1);
            tableLayoutPanel2.Controls.Add(buttonCopy, 0, 2);
            tableLayoutPanel2.Controls.Add(buttonClear, 1, 2);
            tableLayoutPanel2.Controls.Add(labelDataShow, 0, 0);
            tableLayoutPanel2.Location = new Point(455, 57);
            tableLayoutPanel2.Name = "tableLayoutPanel2";
            tableLayoutPanel2.RowCount = 3;
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333321F));
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333359F));
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333359F));
            tableLayoutPanel2.Size = new Size(286, 201);
            tableLayoutPanel2.TabIndex = 3;
            // 
            // buttonCopy
            // 
            buttonCopy.Location = new Point(3, 136);
            buttonCopy.Name = "buttonCopy";
            buttonCopy.Size = new Size(137, 62);
            buttonCopy.TabIndex = 3;
            buttonCopy.Text = "button10";
            buttonCopy.UseVisualStyleBackColor = true;
            // 
            // buttonClear
            // 
            buttonClear.Location = new Point(146, 136);
            buttonClear.Name = "buttonClear";
            buttonClear.Size = new Size(137, 62);
            buttonClear.TabIndex = 4;
            buttonClear.Text = "button12";
            buttonClear.UseVisualStyleBackColor = true;
            // 
            // labelClearSecond
            // 
            labelClearSecond.AutoSize = true;
            labelClearSecond.Font = new Font("Microsoft JhengHei UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            labelClearSecond.Location = new Point(540, 315);
            labelClearSecond.Name = "labelClearSecond";
            labelClearSecond.Size = new Size(81, 30);
            labelClearSecond.TabIndex = 4;
            labelClearSecond.Text = "label1";
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(labelClearSecond);
            Controls.Add(tableLayoutPanel2);
            Controls.Add(tableLayoutPanel1);
            Name = "Form1";
            Text = "安全數字鍵盤";
            Load += Form1_Load;
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel2.ResumeLayout(false);
            tableLayoutPanel2.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Button button0;
        private Button button3;
        private Button button2;
        private Button button1;
        private Button button6;
        private Button button5;
        private Button button4;
        private Button button9;
        private Button button8;
        private Button button7;
        private Button buttonShuffle;
        private Label labelDataShow;
        private TableLayoutPanel tableLayoutPanel2;
        private TextBox textBox1;
        private Button buttonCopy;
        private Button buttonClear;
        private Label labelClearSecond;
        private System.Windows.Forms.Timer timer1;
    }
}