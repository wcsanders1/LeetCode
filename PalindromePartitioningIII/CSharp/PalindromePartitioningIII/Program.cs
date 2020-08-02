using System;
using System.Collections.Generic;

namespace PalindromePartitioningIII
{
    public class Solution
    {
        private Dictionary<string, int> Memo = new Dictionary<string, int>();

        public int PalindromePartition(string s, int k)
        {
            if (string.IsNullOrWhiteSpace(s) || s.Length == k)
            {
                return 0;
            }

            var dp = new int[k][];

            for (int i = 0; i < k; i++)
            {
                dp[i] = new int[s.Length + 1];
            }

            for (int i = 0; i < s.Length; i++)
            {
                dp[0][i + 1] = GetChanges(s.Substring(0, i + 1));
            }

            for (int i = 1; i < k; i++)
            {
                for (int j = i; j <= s.Length; j++)
                {
                    var current = int.MaxValue;
                    for (int p = j; p >= i; p--)
                    {
                        var substring = s[(p - 1)..j];
                        current = Math.Min(current, dp[i - 1][p - 1] + GetChanges(substring));
                    }

                    dp[i][j] = current;
                }
            }

            return dp[k - 1][s.Length];
        }

        private int GetChanges(string str)
        {
            if (string.IsNullOrWhiteSpace(str))
            {
                return 0;
            }

            if (Memo.TryGetValue(str, out var changes))
            {
                return changes;
            }

            var result = 0;
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] != str[str.Length - 1 - i])
                {
                    result++;
                }
            }

            result /= 2;

            Memo.Add(str, result);

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.PalindromePartition("abc", 2));
            Console.WriteLine(solution.PalindromePartition("aabbc", 3));
            Console.WriteLine(solution.PalindromePartition("leetcode", 8));
            Console.WriteLine(solution.PalindromePartition("aabcc", 1));

            Console.ReadKey();
        }
    }
}
