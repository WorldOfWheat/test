namespace WindowsFormsApp2
{
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
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.TestingButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(201, 165);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(371, 23);
            this.progressBar.TabIndex = 0;
            this.progressBar.Value = 50;
            // 
            // TestingButton
            // 
            this.TestingButton.Location = new System.Drawing.Point(179, 240);
            this.TestingButton.Name = "TestingButton";
            this.TestingButton.Size = new System.Drawing.Size(75, 23);
            this.TestingButton.TabIndex = 1;
            this.TestingButton.Text = "button1";
            this.TestingButton.UseVisualStyleBackColor = true;
            this.TestingButton.Click += new System.EventHandler(this.TestingButton_Click);
            // 
            // ProgressShowForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.TestingButton);
            this.Controls.Add(this.progressBar);
            this.Name = "ProgressShowForm";
            this.Text = "ProcessShow";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Button TestingButton;
    }
}