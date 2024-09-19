using System.Data.Common;

namespace DBConnection_exercise
{
    public class DbCommand
    {
        public readonly DbConnection _connection;
        public readonly string _instruction;


        public DbCommand(DbConnection connect,string instruction)
        {
            if (connect == null)
                throw new ArgumentNullException(nameof(connect), "DbConnection cannot be null.");

            if (string.IsNullOrWhiteSpace(instruction))
                throw new ArgumentException("Instruction cannot be null or empty.", nameof(instruction));

            _connection = connect;
            _instruction = instruction;
        }

        public void Execute()
        {
            _connection.Open();
            Console.WriteLine($"Executing instruction: {_instruction}");
            _connection.Close();
        }
    }
}
