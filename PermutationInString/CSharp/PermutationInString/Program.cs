using System;
using System.Collections.Generic;

namespace PermutationInString
{
    public class Solution
    {
        public bool CheckInclusion(string s1, string s2)
        {
            if (string.IsNullOrWhiteSpace(s2))
            {
                return false;
            }

            if (string.IsNullOrWhiteSpace(s1))
            {
                return true;
            }

            if (s2.Length < s1.Length)
            {
                return false;
            }

            var charsByAmount = new Dictionary<char, int>();
            var currentCharsByAmount = new Dictionary<char, int>();
            for (int i = 0; i < s1.Length; i++)
            {
                var curChar = s1[i];
                if (charsByAmount.ContainsKey(curChar))
                {
                    charsByAmount[curChar]++;
                }
                else
                {
                    charsByAmount.Add(curChar, 1);
                }

                var curCharTwo = s2[i];
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
            var end = s1.Length - 1;

            while (end < s2.Length)
            {
                if (AreSame(charsByAmount, currentCharsByAmount))
                {
                    return true;
                }

                if (end == s2.Length - 1)
                {
                    return false;
                }

                currentCharsByAmount[s2[start++]]--;
                var nextChar = s2[++end];

                if (!currentCharsByAmount.ContainsKey(nextChar))
                {
                    currentCharsByAmount.Add(nextChar, 1);
                }
                else
                {
                    currentCharsByAmount[nextChar]++;
                }
            }

            return false;
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

            Console.WriteLine(solution.CheckInclusion("ab", "eidbaooo"));
            Console.WriteLine(solution.CheckInclusion("ab", "eidboooo"));
            Console.WriteLine(solution.CheckInclusion("adc", "dcda"));

            Console.ReadKey();
        }
    }
}
