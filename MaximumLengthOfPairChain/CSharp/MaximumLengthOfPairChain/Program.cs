using System;
using System.Linq;

namespace MaximumLengthOfPairChain
{
    public class Solution
    {
        public int FindLongestChain(int[][] pairs)
        {
            if (pairs == null || pairs.Length < 1)
            {
                return 0;
            }

            var sorted = pairs.OrderBy(p => p[0]).ThenBy(p => p[1]).ToArray();
            var dp = new int[pairs.Length];

            var result = 0;

            for (var i = pairs.Length - 2; i >= 0; i--)
            {
                var pair = sorted[i];
                var greatest = 0;

                for (int j = i + 1; j < pairs.Length; j++)
                {
                    if (pair[1] < sorted[j][0] && dp[j] >= greatest)
                    {
                        greatest = dp[j] + 1;
                    }
                }

                dp[i] = greatest;

                if (greatest > result)
                {
                    result = greatest;
                }
            }

            return result + 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.FindLongestChain(new int[][]
            {
                new int[] {1, 2},
                new int[] {2, 3},
                new int[] {3, 4}
            }));

            Console.ReadKey();
        }
    }
}
