using System.Linq.Expressions;

namespace StopWatch
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var stopWatch = new StopWatch();
            //stopWatch.Start();
            //System.Threading.Thread.Sleep(2000); // Simulating a 2-second delay
            //stopWatch.Stop();
            //Console.WriteLine(stopWatch.Duration.Seconds);
            int choice = -1;

            while (choice != 0)
            {
                Console.Clear();
                Console.WriteLine("Start: 1");
                Console.WriteLine("Stop: 2");
                Console.WriteLine("Exit: 0");
                Console.Write("Please enter number:");
                choice = int.Parse(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        Console.WriteLine("The time started.");
                        stopWatch.Start();
                        break;

                    case 2:
                        Console.Clear();
                        Console.WriteLine("The time stopped.\n");
                        stopWatch.Stop();
                        Console.WriteLine("The duration is " + stopWatch.Duration.Seconds+" !");
                        int choice2;
                        Console.WriteLine("Do you want to continue: 1-yes/2-no");
                        choice2 = int.Parse(Console.ReadLine());
                        if (choice2 ==2)
                        { choice = 0; }
                        break;
                        
                       
                }
            }
        }
    }
}
