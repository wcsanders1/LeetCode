using System;
using System.Collections.Generic;

namespace RegularExpressionMatching
{
    public class Expression
    {
        public bool CanRepeatOrBeNone { get; set; }
        public char Pattern { get; set; }
    }

    public class Solution
    {
        public bool IsMatch(string s, string p)
        {
            var expressions = new List<Expression>();
            var expression = 'A';

            for (var i = 0; i < p.Length; i++)
            {
                if (p[i] == '*')
                {
                    expressions.Add(new Expression
                    {
                        CanRepeatOrBeNone = true,
                        Pattern = expression
                    });
                    expression = 'A';
                }
                else if (expression != 'A')
                {
                    expressions.Add(new Expression
                    {
                        CanRepeatOrBeNone = false,
                        Pattern = expression
                    });
                    expression = p[i];
                }
                else
                {
                    expression = p[i];
                }
            }

            if (expression != 'A')
            {
                expressions.Add(new Expression
                {
                    CanRepeatOrBeNone = false,
                    Pattern = expression
                });
            }

            return IsMatch(expressions, 0, s, 0);
        }

        private bool IsMatch(List<Expression> expressions, int expressionIndex, string s, int stringIndex)
        {
            if (stringIndex >= s.Length)
            {
                while (expressionIndex < expressions.Count)
                {
                    if (expressions[expressionIndex].CanRepeatOrBeNone)
                    {
                        expressionIndex++;
                    }
                    else
                    {
                        break;
                    }
                }
                return expressionIndex >= expressions.Count;
            }

            if (expressionIndex >= expressions.Count)
            {
                return stringIndex >= s.Length;
            }

            var expression = expressions[expressionIndex];
            var character = s[stringIndex];

            if (expression.CanRepeatOrBeNone)
            {
                if (expression.Pattern == '.' || expression.Pattern == s[stringIndex])
                {
                    if (IsMatch(expressions, expressionIndex, s, stringIndex + 1))
                    {
                        return true;
                    }
                }

                return IsMatch(expressions, expressionIndex + 1, s, stringIndex);
            }
            
            if (expression.Pattern == '.' || expression.Pattern == character)
            {
                return IsMatch(expressions, expressionIndex + 1, s, stringIndex + 1);
            }

            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.IsMatch("aa", "a"));
            Console.WriteLine(solution.IsMatch("aa", "a*"));
            Console.WriteLine(solution.IsMatch("ab", ".*"));
            Console.WriteLine(solution.IsMatch("aab", "c*a*b"));
            Console.WriteLine(solution.IsMatch("mississippi", "mis*is*p*."));
            Console.WriteLine(solution.IsMatch("mississippi", "mis*is*ip*."));
            Console.WriteLine(solution.IsMatch("ab", ".*c"));
            Console.WriteLine(solution.IsMatch("aaa", "a*a"));
            Console.WriteLine(solution.IsMatch("aaa", "ab*ac*a"));

            Console.ReadKey();
        }
    }
}
