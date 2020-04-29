using System;

namespace LengthOfLastWord
{
    public class Solution
    {
        public int LengthOfLastWord(string s)
        {
            var result = 0;

            for (var i = s.Length - 1; i >= 0; i--)
            {
                if (s[i] == ' ')
                {
                    if (result > 0)
                    {
                        return result;
                    }
                }
                else
                {
                    result++;
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

            Console.WriteLine(solution.LengthOfLastWord("Hello World"));
            Console.WriteLine(solution.LengthOfLastWord("Hello World     "));
            Console.WriteLine(solution.LengthOfLastWord("HelloWorld"));
            Console.WriteLine(solution.LengthOfLastWord("     "));
            Console.WriteLine(solution.LengthOfLastWord("e     "));

            Console.ReadKey();
        }
    }
}
