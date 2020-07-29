using System;
using System.Linq;

namespace MinimumASCIIDeleteSumForTwoStrings
{
    public class Solution
    {
        public int MinimumDeleteSum(string s1, string s2)
        {
            if (string.IsNullOrWhiteSpace(s1) && string.IsNullOrWhiteSpace(s2))
            {
                return 0;
            }

            if (string.IsNullOrWhiteSpace(s1))
            {
                return s2.Select(s => (int)s).Sum();
            }

            if (string.IsNullOrWhiteSpace(s2))
            {
                return s1.Select(s => (int)s).Sum();
            }

            var dp = new int[s1.Length + 1][];
            for (int i = 0; i <= s1.Length; i++)
            {
                dp[i] = new int[s2.Length + 1];
            }

            for (int row = 1; row <= s1.Length; row++)
            {
                dp[row][0] = s1[row - 1] + dp[row -1][0];
            }

            for (int col = 1; col <= s2.Length; col++)
            {
                dp[0][col] = s2[col - 1] + dp[0][col - 1];
            }

            for (int row = 1; row <= s1.Length; row++)
            {
                var rowChar = s1[row - 1];
                for (int col = 1; col <= s2.Length; col++)
                {
                    var colChar = s2[col - 1];

                    if (rowChar != colChar)
                    {
                        dp[row][col] = Math.Min(dp[row][col - 1] + colChar, dp[row - 1][col] + rowChar);
                    }
                    else
                    {
                        dp[row][col] = dp[row - 1][col - 1];
                    }
                }
            }

            return dp[s1.Length][s2.Length];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MinimumDeleteSum("sea", "eat"));
            Console.WriteLine(solution.MinimumDeleteSum("delete", "leet"));

            Console.ReadKey();
        }
    }
}
