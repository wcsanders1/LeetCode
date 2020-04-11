using System;
using System.Collections.Generic;

namespace ValidParentheses
{
    public class Solution
    {
        private static readonly Dictionary<char, char> OpeningToClosing = new Dictionary<char, char>
        {
            {'(', ')' }, {'{', '}'}, {'[', ']'}
        };

        public bool IsValid(string s)
        {
            var openingChars = new Stack<char>();

            for (int i = 0; i < s.Length; i++)
            {
                var currentChar = s[i];
                if (OpeningToClosing.ContainsKey(currentChar))
                {
                    openingChars.Push(currentChar);
                    continue;
                }
                
                if (!openingChars.TryPop(out var lastOpeningChar))
                {
                    return false;
                }

                if (OpeningToClosing[lastOpeningChar] != currentChar)
                {
                    return false;
                }
            }

            return openingChars.Count == 0;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.IsValid(""));
            Console.WriteLine(solution.IsValid("()"));
            Console.WriteLine(solution.IsValid("()[]{}"));
            Console.WriteLine(solution.IsValid("(]"));
            Console.WriteLine(solution.IsValid("([)]"));
            Console.WriteLine(solution.IsValid("([])"));
            Console.WriteLine(solution.IsValid("([]){}[]"));
            Console.WriteLine(solution.IsValid("([)"));
            Console.WriteLine(solution.IsValid("(([]){})"));
            Console.WriteLine(solution.IsValid("["));

            Console.ReadKey();
        }
    }
}
