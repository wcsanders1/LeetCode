using System;
using System.Collections.Generic;

namespace LetterCombinationsOfAPhoneNumber
{
    public class Solution
    {
        private static readonly Dictionary<int, string> NumbersToLetters = new Dictionary<int, string>
        {
            {2, "abc" }, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv" }, {9, "wxyz"}
        };

        public IList<string> LetterCombinations(string digits)
        {
            if (string.IsNullOrWhiteSpace(digits))
            {
                return new List<string>();
            }

            return GetCombinations(digits, 0);
        }

        private List<string> GetCombinations(string digits, int index)
        {
            string letters;
            List<string> result;
            if (index == digits.Length - 1)
            {
                letters = NumbersToLetters[int.Parse(digits[index].ToString())];
                result = new List<string>();

                for (int i = 0; i < letters.Length; i++)
                {
                    result.Add(letters[i].ToString());
                }

                return result;
            }

            var newCombinations = GetCombinations(digits, index + 1);
            letters = NumbersToLetters[int.Parse(digits[index].ToString())];
            result = new List<string>();

            foreach (var combination in newCombinations)
            {
                for (var i = 0; i < letters.Length; i++)
                {
                    result.Add($"{letters[i]}{combination}");
                }
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.LetterCombinations("23");

            Console.ReadKey();
        }
    }
}
