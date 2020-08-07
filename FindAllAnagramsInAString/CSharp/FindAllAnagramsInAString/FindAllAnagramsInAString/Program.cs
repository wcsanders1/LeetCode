using System;
using System.Collections.Generic;

namespace FindAllAnagramsInAString
{
    public class Solution
    {
        public IList<int> FindAnagrams(string s, string p)
        {
            var result = new List<int>();

            if (string.IsNullOrWhiteSpace(s))
            {
                return result;
            }

            if (string.IsNullOrWhiteSpace(p))
            {
                return result;
            }

            if (s.Length < p.Length)
            {
                return result;
            }

            var charsByAmount = new Dictionary<char, int>();
            var currentCharsByAmount = new Dictionary<char, int>();
            for (int i = 0; i < p.Length; i++)
            {
                var curChar = p[i];
                if (charsByAmount.ContainsKey(curChar))
                {
                    charsByAmount[curChar]++;
                }
                else
                {
                    charsByAmount.Add(curChar, 1);
                }

                var curCharTwo = s[i];
                if (currentCharsByAmount.ContainsKey(curCharTwo))
                {
                    currentCharsByAmount[curCharTwo]++;
                }
                else
                {
                    currentCharsByAmount.Add(curCharTwo, 1);
                }
            }

            var start = 0;
            var end = p.Length - 1;

            while (end < s.Length)
            {
                if (AreSame(charsByAmount, currentCharsByAmount))
                {
                    result.Add(start);
                }

                if (end == s.Length - 1)
                {
                    return result;
                }

                currentCharsByAmount[s[start++]]--;
                var nextChar = s[++end];

                if (!currentCharsByAmount.ContainsKey(nextChar))
                {
                    currentCharsByAmount.Add(nextChar, 1);
                }
                else
                {
                    currentCharsByAmount[nextChar]++;
                }
            }

            return result;
        }

        private bool AreSame(Dictionary<char, int> one, Dictionary<char, int> two)
        {
            foreach (var (letter, number) in one)
            {
                if (!two.ContainsKey(letter))
                {
                    return false;
                }

                if (two[letter] != number)
                {
                    return false;
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.FindAnagrams("cbaebabacd", "abc");
            var result2 = solution.FindAnagrams("abab", "ab");

            Console.ReadKey();
        }
    }
}
