public partial class ProgressShowForm : Form
{
    public bool isClosed = false;

    public ProgressShowForm()
    {
        InitializeComponent();
    }

    private void ProgressShowForm_Load(object sender, EventArgs e)
    {
        isClosed = false;
        //
        errorList.View = View.Details;
        errorList.GridLines = true;
        errorList.Columns.Add("路徑");
        errorList.Columns.Add("錯誤訊息");
        errorList.Columns[0].Width = 350;
    }

    private void ProgressShowForm_FormClosing(object sender, FormClosingEventArgs e)
    {
        isClosed = true;
    }
    public void UpdateProgress(int progressNow, int progressTotal)
    {
        progressBar.Value = Convert.ToInt32(((double)progressNow / progressTotal) * 100.0);
        progressCount.Text = $"剩下檔案: {progressNow}/{progressTotal}";
    }

    public void AddError(string path, string errorMsg)
    {
        errorList.BeginUpdate();
        //
        ListViewItem newRow = new ListViewItem(path);
        newRow.SubItems.Add(errorMsg);
        errorList.Items.Add(newRow);
        errorList.AutoResizeColumn(1, ColumnHeaderAutoResizeStyle.ColumnContent);
        //
        errorList.EndUpdate();
    }

    public new void Close()
    {
        if (errorList.Items.Count > 0)
        {
            cancel.Text = "確定";
            return;
        }
        base.Close();
    }


    private void cancel_Click(object sender, EventArgs e)
    {
        base.Close();
    }

}
