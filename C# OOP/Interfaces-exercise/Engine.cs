using System.Security;

namespace Interfaces_exercise
{
    public class Engine
    {
        public IList<IActivities> activities = new List<IActivities>();

        public void Run()
        {
            activities.Add(new Swim());
            activities.Add(new Run());

            foreach (var activity in activities)
            {
                activity.Execute();
            }
        }
    }
}