internal static class Program
{
    /// <summary>
    ///  The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
        Application.EnableVisualStyles();
        Application.SetCompatibleTextRenderingDefault(false);
        ProgressShowForm progressShowForm = new ProgressShowForm();
        Task.Run(() =>
        {
            Application.Run(progressShowForm);
        });
        for (int i = 0; i < 2000; i++)
        {
            Task.Delay(100).Wait();
            progressShowForm.UpdateProgress(i, 2000);
        }
    }
}