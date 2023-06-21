public partial class ProgressShowForm : Form
{
    public bool isClosed = false;

    public ProgressShowForm()
    {
        InitializeComponent();
    }

    public void UpdateProgress(int progressNow, int progressTotal)
    {
        progressBar.Value = Convert.ToInt32(((double)progressNow / progressTotal) * 100.0);
        progressCount.Text = $"剩下檔案: {progressNow}/{progressTotal}";
    }

    public void AddError(string errorMsg)
    {
    }

    public new void Close()
    {

        base.Close();
    }

    private void ProgressShowForm_Load(object sender, EventArgs e)
    {
        isClosed = false;
    }

    private void ProgressShowForm_FormClosing(object sender, FormClosingEventArgs e)
    {
        isClosed = true;
    }

    private void cancel_Click(object sender, EventArgs e)
    {
        Close();
    }

}
