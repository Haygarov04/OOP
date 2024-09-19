using System.Collections;

namespace Stack_Exercise
{

    public class Stack
    {
        public List<object> elements = new List<object>();
        public void Push(object obj)
        {
            if (obj == null)
            {
                throw new ArgumentNullException();
            }

            elements.Add(obj);
        }

        public object Pop()
        {
            if (elements.Count == 0)
            { throw new InvalidOperationException(); }

            int index = elements.Count - 1;
            object Top = elements[index];
            elements.RemoveAt(index);

            return Top;
        }

        public void Clear()
        { elements.Clear(); }



    }
    internal class Program
    {
        static void Main(string[] args)
        {
            var stack = new Stack();
            stack.Push(1);
            stack.Push(2);
            stack.Push(3);
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Pop());
        }
    }
}
