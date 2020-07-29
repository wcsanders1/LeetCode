using System;

namespace LongestPalindromicSubsequence
{
    public class Solution
    {
        public int LongestPalindromeSubseq(string s)
        {
            if (string.IsNullOrWhiteSpace(s))
            {
                return 0;
            }

            var dp = new int[s.Length + 1][];
            for (int i = 0; i <= s.Length; i++)
            {
                dp[i] = new int[s.Length + 1];
            }

            for (int col = 1; col <= s.Length; col++)
            {
                var reverseIndex = s.Length - 1;
                for (int row = 1; row <= s.Length; row++)
                {
                    if (s[col - 1] == s[reverseIndex--])
                    {
                        dp[col][row] = dp[col - 1][row - 1] + 1;
                    }
                    else
                    {
                        dp[col][row] = Math.Max(dp[col - 1][row], dp[col][row - 1]);
                    }
                }
            }

            return dp[s.Length][s.Length];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.LongestPalindromeSubseq("bbbab"));
            Console.WriteLine(solution.LongestPalindromeSubseq("cbbd"));

            Console.ReadKey();
        }
    }
}
