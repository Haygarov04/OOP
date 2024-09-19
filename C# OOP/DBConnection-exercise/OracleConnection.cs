namespace DBConnection_exercise
{
    public class OracleConnection : DbConnection
    {
        public OracleConnection(string connectionString) : base(connectionString)
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
