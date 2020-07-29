using System;

namespace LongestCommonSubsequence
{
    public class Solution
    {
        public int LongestCommonSubsequence(string text1, string text2)
        {
            if (string.IsNullOrWhiteSpace(text1) || string.IsNullOrWhiteSpace(text2))
            {
                return 0;
            }

            var dp = new int[text1.Length + 1][];
            for (int i = 0; i <= text1.Length; i++)
            {
                dp[i] = new int[text2.Length + 1];
            }

            for (int col = 1; col <= text1.Length; col++)
            {
                for (int row = 1; row <= text2.Length; row++)
                {
                    if (text1[col - 1] == text2[row - 1])
                    {
                        dp[col][row] = dp[col - 1][row - 1] + 1;
                    }
                    else
                    {
                        dp[col][row] = Math.Max(dp[col - 1][row], dp[col][row - 1]);
                    }
                }
            }

            return dp[text1.Length][text2.Length];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.LongestCommonSubsequence("abcde", "ace"));
            Console.WriteLine(solution.LongestCommonSubsequence("abc", "abc"));
            Console.WriteLine(solution.LongestCommonSubsequence("abc", "def"));
            Console.WriteLine(solution.LongestCommonSubsequence("delete", "leet"));

            Console.ReadKey();
        }
    }
}
