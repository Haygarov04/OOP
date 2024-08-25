namespace Inheritance_example
{
    public class Text:PresentationObject
    {
        public int FontSize;
        public int FontName;

        public void AddHyperlink(string url) 
        {
            Console.WriteLine("Link addet to "+ url);
        }
    }
}
