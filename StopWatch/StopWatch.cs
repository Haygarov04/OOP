namespace StopWatch
{
    public class StopWatch
    {
        public DateTime start { get; set; }
        public DateTime stop { get; set; }

        public TimeSpan Duration
        {
            get
            {

                return stop - start;
            }
        }

        public void Start()
        {
            start = DateTime.Now;

        }

        public void Stop()
        {
            stop = DateTime.Now;
        }
    }
}
