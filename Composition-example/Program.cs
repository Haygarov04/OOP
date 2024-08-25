namespace Composition_example
{
    internal partial class Program
    {
        static void Main(string[] args)
        {
            var dbmigrator = new DbMigrator(new Logger());

            var logger=new Logger();
            var installer = new Installer(logger);

            dbmigrator.Migrate();

            installer.Install();
        }
    }
}
