
public partial class ProgressShowForm : Form
{
    public ProgressShowForm()
    {
        InitializeComponent();
    }

    public void UpdateProgress(int progressNow, int progressTotal)
    {
        progressBar.Value = Convert.ToInt32(((double)progressNow / progressTotal) * 100.0);
    }

    public void ProcessFinish()
    {
        Close();
    }

    private void cancel_Click(object sender, EventArgs e)
    {
        cancel.Enabled = false;
        Close();
    }
}
