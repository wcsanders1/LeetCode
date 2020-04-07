using System;
using System.Collections.Generic;

namespace PalindromeNumber
{
    public class Solution
    {
        public bool IsPalindrome(int x)
        {
            if (x < 0)
            {
                return false;
            }

            var digits = new List<int>();

            while (x > 0)
            {
                var digit = x % 10;
                digits.Add(digit);
                x /= 10;
            }

            var start = 0;
            var end = digits.Count - 1;

            while (start <= end)
            {
                if (digits[start++] != digits[end--])
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

            Console.WriteLine(solution.IsPalindrome(121));
            Console.WriteLine(solution.IsPalindrome(-121));
            Console.WriteLine(solution.IsPalindrome(10));
            Console.WriteLine(solution.IsPalindrome(0));
            Console.WriteLine(solution.IsPalindrome(1));
            Console.WriteLine(solution.IsPalindrome(11));
            Console.WriteLine(solution.IsPalindrome(111));
            Console.WriteLine(solution.IsPalindrome(1111));
            Console.WriteLine(solution.IsPalindrome(11011));
            Console.WriteLine(solution.IsPalindrome(010));

            Console.ReadKey();
        }
    }
}
