namespace DBConnection_exercise
{
    public abstract class DbConnection
    {
        public string ConnectionString;
        public TimeSpan Timeout { get; set; } = TimeSpan.FromSeconds(30);
        public abstract void Open();
        public abstract void Close();

        public DbConnection(string connectionString)
        {
            if (string.IsNullOrWhiteSpace(connectionString))
            {
                throw new ArgumentException("Connection string cannot be null or empty.", nameof(connectionString));
            }

            ConnectionString = connectionString;
        }

        public static implicit operator DbConnection(string v)
        {
            throw new NotImplementedException();
        }
    }
}
