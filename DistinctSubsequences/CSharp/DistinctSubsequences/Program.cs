using System;

namespace DistinctSubsequences
{
    public class Solution
    {
        public int NumDistinct(string s, string t)
        {
            var dp = new int[t.Length + 1][];
            for (int i = 0; i <= t.Length; i++)
            {
                dp[i] = new int[s.Length + 1];
            }

            for (int i = 0; i < s.Length; i++)
            {
                dp[0][i] = 1;
            }

            for (int i = 0; i < t.Length; i++)
            {
                for (int j = 0; j < s.Length; j++)
                {
                    if (t[i] == s[j])
                    {
                        dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
                    }
                    else
                    {
                        dp[i + 1][j + 1] = dp[i + 1][j];
                    }
                }
            }

            return dp[t.Length][s.Length];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.NumDistinct("rabbbit", "rabbit"));
            Console.WriteLine(solution.NumDistinct("babgbag", "bag"));
            Console.WriteLine(solution.NumDistinct("ccc", "c"));
            Console.WriteLine(solution.NumDistinct("ccc", "cc"));

            Console.ReadKey();
        }
    }
}
