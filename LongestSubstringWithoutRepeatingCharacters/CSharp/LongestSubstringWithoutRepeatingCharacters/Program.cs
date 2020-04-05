using System;
using System.Collections.Generic;

namespace LongestSubstringWithoutRepeatingCharacters
{
    public class Solution
    {
        public int LengthOfLongestSubstring(string s)
        {
            var previousCharacters = new Dictionary<char, int>();
            
            var currentSequence = 0;
            var longestSequence = 0;
            var currentSequenceBeginning = 0;
            for (int i = 0; i < s.Length; i++)
            {
                var currentChar = s[i];
                if (i == 0)
                {
                    previousCharacters.Add(currentChar, i);
                    currentSequence++;
                    continue;
                }

                if (!previousCharacters.ContainsKey(currentChar))
                {
                    currentSequence++;
                    previousCharacters.Add(currentChar, i);
                    continue;
                }

                if (previousCharacters[currentChar] < currentSequenceBeginning)
                {
                    previousCharacters[currentChar] = i;
                    currentSequence++;
                    continue;
                }

                if (longestSequence < currentSequence)
                {
                    longestSequence = currentSequence;
                }

                currentSequence = i - previousCharacters[currentChar];
                currentSequenceBeginning = previousCharacters[currentChar] + 1;
                previousCharacters[currentChar] = i;
            }

            return Math.Max(longestSequence, currentSequence);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.LengthOfLongestSubstring("abcabcbb"));
            Console.WriteLine(solution.LengthOfLongestSubstring("bbbbb"));
            Console.WriteLine(solution.LengthOfLongestSubstring("pwwkew"));

            Console.WriteLine(solution.LengthOfLongestSubstring("dvdf"));

            Console.WriteLine(solution.LengthOfLongestSubstring("cdd"));

            Console.WriteLine(solution.LengthOfLongestSubstring("abba"));

            Console.WriteLine(solution.LengthOfLongestSubstring("aabaab!bb"));

            Console.ReadKey();
        }
    }
}
