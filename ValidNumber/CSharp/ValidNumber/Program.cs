using System;
using System.Text.RegularExpressions;

namespace ValidNumber
{
    // NOT DONE YET!
    public class Solution
    {
        public bool IsNumber(string s)
        {
            if (string.IsNullOrWhiteSpace(s))
            {
                return false;
            }

            var rx = new Regex(@"^\s*[\-\+]?\d*e?\.?\d+\s*$");

            return rx.IsMatch(s);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.IsNumber("   543    "));         // true
            Console.WriteLine(solution.IsNumber("abc"));                // false
            Console.WriteLine(solution.IsNumber(null));                 // false
            Console.WriteLine(solution.IsNumber("4.5"));                // true
            Console.WriteLine(solution.IsNumber(" 0.1"));               // true
            Console.WriteLine(solution.IsNumber("1 a"));                // false
            Console.WriteLine(solution.IsNumber(" .1"));                // true
            Console.WriteLine(solution.IsNumber("-1"));                 // true
            Console.WriteLine(solution.IsNumber("+1"));                 // true
            Console.WriteLine(solution.IsNumber("-+1"));                // false
            Console.WriteLine(solution.IsNumber("--1"));                // false
            Console.WriteLine(solution.IsNumber("1-1"));                // false
            Console.WriteLine(solution.IsNumber("2e10"));               // true
            Console.WriteLine(solution.IsNumber("2e10e"));              // false
            Console.WriteLine(solution.IsNumber("53.5e93"));            // true

            Console.ReadKey();
        }
    }
}
