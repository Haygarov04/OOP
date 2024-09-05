namespace DBConnection_exercise
{
    public class SqlConnection : DbConnection
    {
        public SqlConnection(string connectionString) : base(connectionString)
        {
        }

        public override void Close()
        {
            Console.WriteLine("Connection is closed");
        }

        public override void Open()
        {
            Console.WriteLine("Connection is opened");
        }
    }
}
