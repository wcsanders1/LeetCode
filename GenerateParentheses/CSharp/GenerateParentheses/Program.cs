using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GenerateParentheses
{
    public class Solution
    {
        public IList<string> GenerateParenthesis(int n)
        {
            var result = new HashSet<string>();

            if (n == 0)
            {
                result.Add(string.Empty);
                return result.ToList();
            }

            var sb = new StringBuilder();
            for (var i = 0; i < n; i++)
            {
                sb.Append("()");
            }

            var currentString = sb.ToString();
            result.Add(currentString);

            GetCombinations(currentString, result);

            return result.ToList();
        }

        private void GetCombinations(string s, HashSet<string> combinations)
        {
            var indexesToFlip = new List<int>();
            for (int i = 0; i < s.Length - 1; i++)
            {
                if (s[i] == ')' && s[i + 1] == '(')
                {
                    indexesToFlip.Add(i);
                }
            }

            foreach (var index in indexesToFlip)
            {
                var newCombination = $"{s.Substring(0, index)}(){s.Substring(index + 2, s.Length - (index + 2))}";
                
                if (combinations.Contains(newCombination))
                {
                    continue;
                }

                combinations.Add(newCombination);
                GetCombinations(newCombination, combinations);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.GenerateParenthesis(3);
            var result2 = solution.GenerateParenthesis(4);
            var result3 = solution.GenerateParenthesis(1);

            Console.ReadKey();
        }
    }
}
