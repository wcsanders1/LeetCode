using System;
using System.Collections.Generic;

namespace CourseScheduleII
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

        public int[] FindOrder(int numCourses, int[][] prerequisites)
        {
            if (numCourses == 0)
            {
                return new int[0];
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

            var result = GetCourseOrder(coursesCanTake, courses);
            
            if (result.Count == numCourses)
            {
                return result.ToArray();
            }

            return new int[0];
        }

        private List<int> GetCourseOrder(Queue<Course> coursesCanTake, Course[] courses)
        {
            var result = new List<int>();
            var taken = new bool[courses.Length];
            
            while (coursesCanTake.Count > 0)
            {
                var course = coursesCanTake.Dequeue();

                result.Add(course.CourseNumber);
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

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var resultOne = solution.FindOrder(2, new int[][]
            {
                new int[]{1, 0}
            });

            var resultTwo = solution.FindOrder(4, new int[][]
            {
                new int[]{1, 0},
                new int[]{2, 0},
                new int[]{3, 1},
                new int[]{3, 2}
            });

            var resultThree = solution.FindOrder(1, new int[0][]);
            var resultFour = solution.FindOrder(2, new int[0][]);
            var resultFive = solution.FindOrder(3, new int[][]
            {
                new int[]{1, 0}
            });

            var resultSix = solution.FindOrder(2, new int[][]
            {
                new int[]{0, 1},
                new int[]{1, 0}
            });

            var resultSven = solution.FindOrder(7, new int[][]
            {
                new int[]{1, 0},
                new int[]{0, 3},
                new int[]{0, 2},
                new int[]{3, 2},
                new int[]{2, 5},
                new int[]{4, 5},
                new int[]{5, 6},
                new int[]{2, 4},
            });

            var resultSeven = solution.FindOrder(3, new int[][]
            {
                new int[]{2, 0},
                new int[]{2, 1}
            });

            Console.ReadKey();
        }
    }
}
