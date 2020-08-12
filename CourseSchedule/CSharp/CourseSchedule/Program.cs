using System;
using System.Collections.Generic;
using System.Linq;

namespace CourseSchedule
{
    public class Solution
    {
        private class Course
        {
            public List<int> Prerequisites { get; set; }
            public List<int> Children { get; set; }
            public int CourseNumber { get; set; }

            public Course(int courseNumber)
            {
                CourseNumber = courseNumber;
                Prerequisites = new List<int>();
                Children = new List<int>();
            }
        }

        public bool CanFinish(int numCourses, int[][] prerequisites)
        {
            if (numCourses == 0)
            {
                return true;
            }

            var courses = new Course[numCourses];
            for (int i = 0; i < courses.Length; i++)
            {
                courses[i] = new Course(i);
            }

            foreach (var prerequisite in prerequisites)
            {
                courses[prerequisite[0]].Prerequisites.Add(prerequisite[1]);
                courses[prerequisite[1]].Children.Add(prerequisite[0]);
            }

            var coursesCanTake = new Queue<Course>();

            foreach (var course in courses)
            {
                if (course.Prerequisites.Count == 0)
                {
                    coursesCanTake.Enqueue(course);
                }
            }

            return CanTakeAllCourses(coursesCanTake, courses);
        }

        private bool CanTakeAllCourses(Queue<Course> coursesCanTake, Course[] courses)
        {
            var taken = new bool[courses.Length];

            while (coursesCanTake.Count > 0)
            {
                var course = coursesCanTake.Dequeue();
                taken[course.CourseNumber] = true;

                foreach (var childNum in course.Children)
                {
                    var child = courses[childNum];
                    var canTake = true;
                    foreach (var prerequisite in child.Prerequisites)
                    {
                        if (!taken[prerequisite])
                        {
                            canTake = false;
                            break;
                        }
                    }

                    if (canTake)
                    {
                        coursesCanTake.Enqueue(child);
                    }
                }
            }

            return taken.All(t => t);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.CanFinish(2, new int[][]
            {
                new int[]{1, 0}
            }));

            Console.WriteLine(solution.CanFinish(4, new int[][]
            {
                new int[]{1, 0},
                new int[]{2, 0},
                new int[]{3, 1},
                new int[]{3, 2}
            }));

            Console.WriteLine(solution.CanFinish(1, new int[0][]));
            Console.WriteLine(solution.CanFinish(2, new int[0][]));
            Console.WriteLine(solution.CanFinish(3, new int[][]
            {
                new int[]{1, 0}
            }));

            Console.WriteLine(solution.CanFinish(2, new int[][]
            {
                new int[]{0, 1},
                new int[]{1, 0}
            }));

            Console.WriteLine(solution.CanFinish(7, new int[][]
            {
                new int[]{1, 0},
                new int[]{0, 3},
                new int[]{0, 2},
                new int[]{3, 2},
                new int[]{2, 5},
                new int[]{4, 5},
                new int[]{5, 6},
                new int[]{2, 4},
            }));

            Console.WriteLine(solution.CanFinish(3, new int[][]
            {
                new int[]{2, 0},
                new int[]{2, 1}
            }));

            Console.ReadKey();
        }
    }
}
