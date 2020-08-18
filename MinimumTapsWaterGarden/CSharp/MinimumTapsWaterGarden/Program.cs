using System;
using System.Linq;

namespace MinimumTapsWaterGarden
{
    public class Solution
    {
        public int MinTaps(int n, int[] ranges)
        {
            if (ranges == null || ranges.Length == 0)
            {
                return -1;
            }

            var intervals = new int[ranges.Length][];
            for (int i = 0; i < ranges.Length; i++)
            {
                intervals[i] = new int[2];
                intervals[i][0] = Math.Max(i - ranges[i], 0);
                intervals[i][1] = i + ranges[i];
            }

            var sortedIntervals = intervals.OrderBy(i => i[0]).ThenBy(i => i[1]).ToArray();

            var index = 0;
            while (index < sortedIntervals.Length && sortedIntervals[index][0] == 0)
            {
                index++;
            }

            if (index == 0)
            {
                return -1;
            }

            if (index >= sortedIntervals.Length)
            {
                return 1;
            }

            var end = sortedIntervals[index - 1][1];
            var tapsOpen = 1;

            if (end >= n)
            {
                return tapsOpen;
            }

            while (true)
            {
                var nextIndex = GetIndexOfHighestInRange(end, index, sortedIntervals);
                var nextInterval = sortedIntervals[nextIndex];

                tapsOpen++;
                end = nextInterval[1];

                if (end >= n)
                {
                    return tapsOpen;
                }

                if (nextIndex == index)
                {
                    return -1;
                }

                index = nextIndex;
            }
        }

        private int GetIndexOfHighestInRange(int end, int beginningIndex, int[][] intervals)
        {
            var result = beginningIndex;
            var greatestEnd = end;

            for (int i = beginningIndex; i < intervals.Length; i++)
            {
                if (intervals[i][0] > end)
                {
                    return result;
                }

                if (intervals[i][1] > greatestEnd)
                {
                    greatestEnd = intervals[i][1];
                    result = i;
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

            Console.WriteLine(solution.MinTaps(5, new int[] { 3, 4, 1, 1, 0, 0 }));
            Console.WriteLine(solution.MinTaps(3, new int[] { 0, 0, 0, 0 }));
            Console.WriteLine(solution.MinTaps(7, new int[] { 1, 2, 1, 0, 2, 1, 0, 1 }));
            Console.WriteLine(solution.MinTaps(8, new int[] { 4, 0, 0, 0, 0, 0, 0, 0, 4 }));
            Console.WriteLine(solution.MinTaps(8, new int[] { 4, 0, 0, 0, 4, 0, 0, 0, 4 }));
            Console.WriteLine(solution.MinTaps(2, new int[] { 1, 2, 3 }));
            Console.WriteLine(solution.MinTaps(7, new int[] { 3, 0, 5, 4, 5, 4, 4, 3 }));

            Console.ReadKey();
        }
    }
}
