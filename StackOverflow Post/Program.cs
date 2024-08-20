namespace StackOverflow_Post
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var post = new Post("Holiday in Bulgaria", "We will travel in Bulgaria");
            post.voteUp();
            post.voteUp();
            post.voteUp();
            post.displayData();

        }
    }
}
