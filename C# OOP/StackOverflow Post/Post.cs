namespace StackOverflow_Post
{
    public class Post
    {
        public string _title { get; set; }
        public string _description { get; set; }
        public DateTime _datetime { get; set; }
        public int _votes { get; set; } = 0;

        public Post(string title, string description)
        {
            _title = title;
            _description = description;
            _datetime = DateTime.Now;
        }
        public void displayData()
        {
            Console.WriteLine(_title + "\n" + _description + "\n Date:" + _datetime + "\n Votes:" + _votes);
        }
        public void voteUp()
        { _votes++; }

        public void voteDown()
        { _votes--; }
    }
}
