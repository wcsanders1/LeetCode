using System;
using System.Collections.Generic;
using System.Linq;

namespace CourseScheduleIII
{
    public class Solution
    {
        public int ScheduleCourse(int[][] courses)
        {
            if (courses == null || courses.Length == 0)
            {
                return 0;
            }

            var sortedCourses = courses.OrderBy(c => c[1]).ToArray();
            var scheduledCourses = new List<int>();

            var days = 0;

            for (int i = 0; i < courses.Length; i++)
            {
                if (days + sortedCourses[i][0] <= sortedCourses[i][1])
                {
                    AddSorted(scheduledCourses, sortedCourses[i][0]);
                    days += sortedCourses[i][0];
                }
                else if (scheduledCourses.Count > 0 && scheduledCourses.Last() > sortedCourses[i][0])
                {
                    days += sortedCourses[i][0] - scheduledCourses.Last();
                    scheduledCourses.RemoveAt(scheduledCourses.Count - 1);
                    AddSorted(scheduledCourses, sortedCourses[i][0]);
                }
            }

            return scheduledCourses.Count;
        }

        private void AddSorted(List<int> list, int value)
        {
            var index = list.BinarySearch(value);
            index = index < 0 ? ~index : index;
            list.Insert(index, value);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.ScheduleCourse(new int[][]
            {
                new int[]{100, 200},
                new int[]{200, 1300},
                new int[]{1000, 1250},
                new int[]{2000, 3200}
            }));

            Console.WriteLine(solution.ScheduleCourse(new int[][]
            {
                new int[]{100, 2 },
                new int[]{32, 50}
            }));

            Console.WriteLine(solution.ScheduleCourse(new int[][]
            {
                new int[]{5, 15},
                new int[]{3, 19},
                new int[]{6, 7},
                new int[]{2, 10},
                new int[]{5, 16},
                new int[]{8, 14},
                new int[]{10, 11},
                new int[]{2, 19},
            }));

            Console.ReadKey();
        }
    }
}
