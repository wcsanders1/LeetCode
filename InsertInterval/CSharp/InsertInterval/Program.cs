using System;
using System.Collections.Generic;

namespace InsertInterval
{
    public class Solution
    {
        public int[][] Insert(int[][] intervals, int[] newInterval)
        {
            if (newInterval.Length == 0)
            {
                return intervals;
            }

            var result = new List<int[]>();
            if (intervals.Length == 0)
            {
                result.Add(newInterval);
                return result.ToArray();
            }

            var i = 0;
            while (i < intervals.Length)
            {
                if (newInterval[1] < intervals[i][0])
                {
                    if (i == 0 || intervals[i - 1][1] < newInterval[0])
                    {
                        result.Add(newInterval);
                    }

                    result.Add(intervals[i]);
                    i++;
                    continue;
                }

                if (newInterval[0] > intervals[i][1])
                {
                    result.Add(intervals[i]);
                    if (i == intervals.Length - 1)
                    {
                        result.Add(newInterval);
                        return result.ToArray();
                    }
                    i++;
                    continue;
                }

                if (i < intervals.Length - 1 && intervals[i][1] < newInterval[0] && intervals[i + 1][0] > newInterval[1])
                {
                    result.Add(intervals[i]);
                    result.Add(newInterval);
                    i++;
                    continue;
                }

                var least = Math.Min(intervals[i][0], newInterval[0]);
                var most = Math.Max(intervals[i][1], newInterval[1]);

                i++;

                while (i < intervals.Length && intervals[i][0] <= most)
                {
                    if (intervals[i][1] > most)
                    {
                        most = intervals[i][1];
                    }
                    i++;
                }

                result.Add(new int[] { least, most });
            }

            return result.ToArray();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.Insert(new int[][]
            {
                new int[]{1, 3},
                new int[]{6, 9},
            }, new int[] { 2, 5 });

            var result2 = solution.Insert(new int[][]
            {
                new int[]{1, 2},
                new int[]{3, 5},
                new int[]{6, 7},
                new int[]{8, 10},
                new int[]{12, 16},
            }, new int[] { 4, 8 });

            var result3 = solution.Insert(new int[][]
            {
                new int[]{3, 5},
                new int[]{12, 15},
            }, new int[] { 6, 6 });

            Console.ReadKey();
        }
    }
}
