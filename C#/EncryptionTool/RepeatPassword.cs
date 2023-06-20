using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

public partial class RepeatPasswordForm : System.Windows.Forms.Form
{
    public bool ifContinue = false;

    private string password;
    private string repeatPasswordHintText;

    public RepeatPasswordForm(string password)
    {
        InitializeComponent();
        this.password = password;
    }

    private void confirm_Click(object sender, EventArgs e)
    {
        if (passwordCheckAndMessageBox())
        {
            ifContinue = true;
            Close();
        }
    }

    private void cancel_Click(object sender, EventArgs e)
    {
        ifContinue = false;
        Close();
    }

    private void repeatPasswordForm_Load(object sender, EventArgs e)
    {
        repeatPasswordHintText = repeatPassword.Text;
    }

    private void repeatPassword_Enter(object sender, EventArgs e)
    {
        if (0 == string.Compare(repeatPasswordHintText, repeatPassword.Text))
        {
            repeatPassword.Text = "";
            repeatPassword.PasswordChar = '*';
        }
    }

    private void repeatPassword_Leave(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(repeatPassword.Text))
        {
            repeatPassword.Text = repeatPasswordHintText;
            repeatPassword.PasswordChar = '\0';
        }
    }

    private void repeatPassword_KeyPress(object sender, KeyPressEventArgs e)
    {
        if (e.KeyChar == (char)Keys.Enter)
        {
            if (passwordCheckAndMessageBox())
            {
                ifContinue = true;
                Close();
            }
        }
    }

    private bool passwordCheckAndMessageBox()
    {
        if (0 != string.Compare(password, repeatPassword.Text))
        {
            MessageBox.Show("重複密碼和原密碼必需相同", "項目錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return false;
        }
        return true;
    }

}
