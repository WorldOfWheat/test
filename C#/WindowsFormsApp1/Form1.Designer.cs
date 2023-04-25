namespace WindowsFormsApp1
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
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.trackBarControl = new System.Windows.Forms.TrackBar();
            this.trackBarShow = new System.Windows.Forms.TrackBar();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.buttonSet = new System.Windows.Forms.Button();
            this.buttonReset = new System.Windows.Forms.Button();
            this.labelTitle = new System.Windows.Forms.Label();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.labelD = new System.Windows.Forms.Label();
            this.labelI = new System.Windows.Forms.Label();
            this.labelP = new System.Windows.Forms.Label();
            this.numericUpDownP = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownI = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownD = new System.Windows.Forms.NumericUpDown();
            this.labelTest = new System.Windows.Forms.Label();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.trackBarControl)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarShow)).BeginInit();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownP)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownI)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownD)).BeginInit();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 10;
            this.timer1.Tick += new System.EventHandler(this.Timer1_Tick);
            // 
            // trackBarControl
            // 
            this.trackBarControl.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.trackBarControl.Location = new System.Drawing.Point(3, 15);
            this.trackBarControl.Maximum = 1000;
            this.trackBarControl.Name = "trackBarControl";
            this.trackBarControl.Size = new System.Drawing.Size(821, 45);
            this.trackBarControl.TabIndex = 0;
            this.trackBarControl.Value = 500;
            this.trackBarControl.ValueChanged += new System.EventHandler(this.TrackBarControl_ValueChanged);
            // 
            // trackBarShow
            // 
            this.trackBarShow.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.trackBarShow.Enabled = false;
            this.trackBarShow.Location = new System.Drawing.Point(3, 90);
            this.trackBarShow.Maximum = 1000;
            this.trackBarShow.Name = "trackBarShow";
            this.trackBarShow.Size = new System.Drawing.Size(821, 45);
            this.trackBarShow.TabIndex = 1;
            this.trackBarShow.Value = 500;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 89.22495F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 10.77505F));
            this.tableLayoutPanel1.Controls.Add(this.trackBarShow, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.buttonSet, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.buttonReset, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.trackBarControl, 0, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(77, 359);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(927, 151);
            this.tableLayoutPanel1.TabIndex = 2;
            // 
            // buttonSet
            // 
            this.buttonSet.Enabled = false;
            this.buttonSet.Font = new System.Drawing.Font("PMingLiU", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.buttonSet.Location = new System.Drawing.Point(830, 3);
            this.buttonSet.Name = "buttonSet";
            this.buttonSet.Size = new System.Drawing.Size(94, 69);
            this.buttonSet.TabIndex = 2;
            this.buttonSet.Text = "Set";
            this.buttonSet.UseVisualStyleBackColor = true;
            this.buttonSet.Click += new System.EventHandler(this.ButtonSet_Click);
            // 
            // buttonReset
            // 
            this.buttonReset.Font = new System.Drawing.Font("PMingLiU", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.buttonReset.Location = new System.Drawing.Point(830, 78);
            this.buttonReset.Name = "buttonReset";
            this.buttonReset.Size = new System.Drawing.Size(94, 70);
            this.buttonReset.TabIndex = 3;
            this.buttonReset.Text = "Reset";
            this.buttonReset.UseVisualStyleBackColor = true;
            this.buttonReset.Click += new System.EventHandler(this.ButtonReset_Click);
            // 
            // labelTitle
            // 
            this.labelTitle.AutoSize = true;
            this.labelTitle.Font = new System.Drawing.Font("PMingLiU", 60F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.labelTitle.Location = new System.Drawing.Point(367, 9);
            this.labelTitle.Name = "labelTitle";
            this.labelTitle.Size = new System.Drawing.Size(305, 80);
            this.labelTitle.TabIndex = 3;
            this.labelTitle.Text = "PID Test";
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 3;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel2.Controls.Add(this.labelD, 2, 0);
            this.tableLayoutPanel2.Controls.Add(this.labelI, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.labelP, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.numericUpDownP, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.numericUpDownI, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.numericUpDownD, 2, 1);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(156, 136);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 2;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50.36496F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 49.63504F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(704, 141);
            this.tableLayoutPanel2.TabIndex = 4;
            // 
            // labelD
            // 
            this.labelD.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.labelD.AutoSize = true;
            this.labelD.Font = new System.Drawing.Font("PMingLiU", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.labelD.Location = new System.Drawing.Point(568, 0);
            this.labelD.Name = "labelD";
            this.labelD.Size = new System.Drawing.Size(36, 71);
            this.labelD.TabIndex = 7;
            this.labelD.Text = "D";
            // 
            // labelI
            // 
            this.labelI.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.labelI.AutoSize = true;
            this.labelI.Font = new System.Drawing.Font("PMingLiU", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.labelI.Location = new System.Drawing.Point(339, 0);
            this.labelI.Name = "labelI";
            this.labelI.Size = new System.Drawing.Size(24, 71);
            this.labelI.TabIndex = 6;
            this.labelI.Text = "I";
            // 
            // labelP
            // 
            this.labelP.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.labelP.AutoSize = true;
            this.labelP.Font = new System.Drawing.Font("PMingLiU", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.labelP.Location = new System.Drawing.Point(101, 0);
            this.labelP.Name = "labelP";
            this.labelP.Size = new System.Drawing.Size(31, 71);
            this.labelP.TabIndex = 5;
            this.labelP.Text = "P";
            // 
            // numericUpDownP
            // 
            this.numericUpDownP.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.numericUpDownP.Location = new System.Drawing.Point(57, 74);
            this.numericUpDownP.Name = "numericUpDownP";
            this.numericUpDownP.Size = new System.Drawing.Size(120, 22);
            this.numericUpDownP.TabIndex = 8;
            // 
            // numericUpDownI
            // 
            this.numericUpDownI.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.numericUpDownI.Location = new System.Drawing.Point(291, 74);
            this.numericUpDownI.Name = "numericUpDownI";
            this.numericUpDownI.Size = new System.Drawing.Size(120, 22);
            this.numericUpDownI.TabIndex = 9;
            // 
            // numericUpDownD
            // 
            this.numericUpDownD.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.numericUpDownD.Location = new System.Drawing.Point(526, 74);
            this.numericUpDownD.Name = "numericUpDownD";
            this.numericUpDownD.Size = new System.Drawing.Size(120, 22);
            this.numericUpDownD.TabIndex = 10;
            // 
            // labelTest
            // 
            this.labelTest.AutoSize = true;
            this.labelTest.Font = new System.Drawing.Font("PMingLiU", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.labelTest.Location = new System.Drawing.Point(919, 83);
            this.labelTest.Name = "labelTest";
            this.labelTest.Size = new System.Drawing.Size(74, 27);
            this.labelTest.TabIndex = 5;
            this.labelTest.Text = "label1";
            // 
            // timer2
            // 
            this.timer2.Enabled = true;
            this.timer2.Interval = 500;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1044, 588);
            this.Controls.Add(this.labelTest);
            this.Controls.Add(this.tableLayoutPanel2);
            this.Controls.Add(this.labelTitle);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackBarControl)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarShow)).EndInit();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownP)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownI)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownD)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TrackBar trackBarControl;
        private System.Windows.Forms.TrackBar trackBarShow;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button buttonSet;
        private System.Windows.Forms.Button buttonReset;
        private System.Windows.Forms.Label labelTitle;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label labelD;
        private System.Windows.Forms.Label labelI;
        private System.Windows.Forms.Label labelP;
        private System.Windows.Forms.NumericUpDown numericUpDownP;
        private System.Windows.Forms.NumericUpDown numericUpDownI;
        private System.Windows.Forms.NumericUpDown numericUpDownD;
        private System.Windows.Forms.Label labelTest;
        private System.Windows.Forms.Timer timer2;
    }
}