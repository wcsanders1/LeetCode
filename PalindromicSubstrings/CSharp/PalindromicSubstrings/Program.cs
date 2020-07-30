using System;

namespace PalindromicSubstrings
{
    public class Solution
    {
        public int CountSubstrings(string s)
        {
            if (string.IsNullOrWhiteSpace(s))
            {
                return 0;
            }

            var result = 0;
            for (int i = 0; i < s.Length; i++)
            {
                result += CountSubstrings(s, i, i);

                if (i < s.Length - 1)
                {
                    result += CountSubstrings(s, i, i + 1);
                }
            }

            return result;
        }

        private int CountSubstrings(string s, int start, int end, int count = 0)
        {
            if (start < 0 || end >= s.Length)
            {
                return count;
            }

            if (s[start] != s[end])
            {
                return count;
            }

            return CountSubstrings(s, start - 1, end + 1, count + 1);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.CountSubstrings("abc"));
            Console.WriteLine(solution.CountSubstrings("aaa"));
            Console.WriteLine(solution.CountSubstrings("aaddaada"));

            Console.ReadKey();
        }
    }
}
