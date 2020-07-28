using System;
using System.Linq;

namespace RussianDollEnvelopes
{
    public class Solution
    {
        public int MaxEnvelopes(int[][] envelopes)
        {
            if (envelopes == null || envelopes.Length == 0)
            {
                return 0;
            }

            var sorted = envelopes.OrderBy(e => e[0]).ThenBy(e => e[1]).ToList();

            var dp = new int[envelopes.Length];
            
            for (int i = sorted.Count - 2; i >= 0; i--)
            {
                var greatest = 0;
                var envelope = sorted[i];

                for (int j = i + 1; j < sorted.Count; j++)
                {
                    var next = sorted[j];
                    if (envelope[0] < next[0] && envelope[1] < next[1])
                    {
                        greatest = Math.Max(dp[j] + 1, greatest);
                    }
                }

                dp[i] = greatest;
            }


            return dp.Max() + 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxEnvelopes(new int[][] { new int[] { 5, 4 }, new int[] { 6, 4 }, new int[] { 6, 7 }, new int[] { 2, 3 } }));
            Console.WriteLine(solution.MaxEnvelopes(new int[][] { new int[] { 15, 8 }, new int[] { 2, 20 }, new int[] { 2, 14 }, new int[] { 4, 17 },
                new int[] { 8, 19 }, new int[] { 8, 9 }, new int[] { 5, 7 }, new int[] { 11, 19 },
                new int[] { 8, 11 }, new int[] { 13, 11 }, new int[] { 2, 13 }, new int[] { 11, 19 },
                new int[] { 8, 11 }, new int[] { 13, 11 }, new int[] { 2, 13 }, new int[] { 11, 19 },
                new int[] { 16, 1 }, new int[] { 18, 13 }, new int[] { 14, 17 }, new int[] { 18, 19 }}));

            Console.WriteLine(solution.MaxEnvelopes(new int[][] { new int[] { 10, 8 }, new int[] { 1, 12 }, new int[] { 6, 15 }, new int[] { 2, 18 } }));

            Console.ReadKey();
        }
    }
}
