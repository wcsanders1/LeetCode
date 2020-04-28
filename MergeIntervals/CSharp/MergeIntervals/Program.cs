using System;
using System.Collections.Generic;
using System.Linq;

namespace MergeIntervals
{
    public class Solution
    {
        public int[][] Merge(int[][] intervals)
        {
            var result = new List<int[]>();

            if (intervals.Length == 0)
            {
                return result.ToArray();
            }

            var orderedIntervals = intervals.OrderBy(i => i[0]).ToArray();
            var index = 0;
            while (index < intervals.Length)
            {
                var nextIndex = index + 1;
                var nextInterval = orderedIntervals[index][1];
                while (nextIndex < intervals.Length && nextInterval >= orderedIntervals[nextIndex][0])
                {
                    if (orderedIntervals[nextIndex][1] > nextInterval)
                    {
                        nextInterval = orderedIntervals[nextIndex][1];
                    }
                    nextIndex++;
                }

                result.Add(new int[] { orderedIntervals[index][0], nextInterval });
                index = nextIndex;
            }

            return result.ToArray();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.Merge(new int[][]
            {
                new [] {1, 3},
                new [] {2, 6},
                new [] {8, 10},
                new [] {15, 18}
            });

            var result2 = solution.Merge(new int[][]
            {
                new [] {1, 4},
                new [] {4, 5}
            });

            var result3 = solution.Merge(new int[][]
            {
                new [] {1, 4},
                new [] {0, 1}
            });

            var result4 = solution.Merge(new int[][]
            {
                new [] {1, 4},
                new [] {2, 3}
            });

            var result5 = solution.Merge(new int[][]
            {
                new [] {1, 4},
                new [] {0, 2},
                new [] {3, 5}
            });

            Console.ReadKey();
        }
    }
}
