using System;

namespace LongestPalindromicSubstring
{
    // I realize this code could be condensed considerably. But I lack the time now; shoot.
    public class Solution
    {
        public string LongestPalindrome(string s)
        {
            var longestPalindrome = string.Empty;

            for (var i = 0; i < s.Length; i++)
            {
                var newOddPalindrome = GetLongestOddPalindroneFromIndex(s, i);
                var newEvenPalindrome = GetLongestEvenPalindrome(s, i);
                if (newOddPalindrome.Length > longestPalindrome.Length)
                {
                    longestPalindrome = newOddPalindrome;
                }

                if (newEvenPalindrome.Length > longestPalindrome.Length)
                {
                    longestPalindrome = newEvenPalindrome;
                }
            }

            return longestPalindrome;
        }

        private string GetLongestEvenPalindrome(string s, int index)
        {
            var leftIndex = index - 1;
            var rightIndex = index + 1;

            var longest = s[index].ToString();

            if (rightIndex >= s.Length || s[rightIndex].ToString() != longest)
            {
                return longest;
            }

            longest = $"{longest}{s[rightIndex]}";
            rightIndex++;

            while (leftIndex >= 0 && rightIndex < s.Length)
            {
                if (s[leftIndex] != s[rightIndex])
                {
                    break;
                }
                longest = s.Substring(leftIndex, rightIndex + 1 - leftIndex);
                leftIndex--;
                rightIndex++;
            }

            return longest;
        }

        private string GetLongestOddPalindroneFromIndex(string s, int index)
        {
            var leftIndex = index - 1;
            var rightIndex = index + 1;

            var longest = s[index].ToString();

            while (leftIndex >= 0 && rightIndex < s.Length)
            {
                if (s[leftIndex] != s[rightIndex])
                {
                    break;
                }
                longest = s.Substring(leftIndex, rightIndex + 1 - leftIndex);
                leftIndex--;
                rightIndex++;
            }

            return longest;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.LongestPalindrome("babad"));
            Console.WriteLine(solution.LongestPalindrome("cbbd"));
            Console.WriteLine(solution.LongestPalindrome("xqasdsarrtt"));
            Console.WriteLine(solution.LongestPalindrome("aaaa"));
            Console.WriteLine(solution.LongestPalindrome("abbbba"));


            Console.ReadKey();
        }
    }
}
