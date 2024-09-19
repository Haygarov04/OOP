namespace DBConnection_exercise
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var Sqlcon = new SqlConnection("asdasdasd");
            var Oraclecon = new OracleConnection("gdfgdfg");

            DbCommand command = new DbCommand(Sqlcon,"insert");
            command.Execute();

        }
    }
}
