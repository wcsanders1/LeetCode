using System;
using System.Text.RegularExpressions;

namespace ValidNumber
{
    public class Solution
    {
        public bool IsNumber(string s)
        {
            if (string.IsNullOrWhiteSpace(s))
            {
                return false;
            }

            var rx = new Regex(@"^\s*(\-|\+)?(\d+)?(\.)?(?(2)(?(3)([eE]-?)?|\d*))\d+((?(4)|[eE]-?)([\-\+]?\d+))?(?(5)|(?(3)|\.?))\s*$");

            return rx.IsMatch(s);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.IsNumber("abc"));                // false
            Console.WriteLine(solution.IsNumber(null));                 // false
            Console.WriteLine(solution.IsNumber("1 a"));                // false
            Console.WriteLine(solution.IsNumber("-+1"));                // false
            Console.WriteLine(solution.IsNumber("--1"));                // false
            Console.WriteLine(solution.IsNumber("1-1"));                // false
            Console.WriteLine(solution.IsNumber("2e10e"));              // false
            Console.WriteLine(solution.IsNumber("1e"));                 // false
            Console.WriteLine(solution.IsNumber("e3"));                 // false
            Console.WriteLine(solution.IsNumber("99e2.5"));             // false
            Console.WriteLine(solution.IsNumber("99e2.e5"));            // false
            Console.WriteLine(solution.IsNumber("992.e5e"));            // false
            Console.WriteLine(solution.IsNumber("992.e5e4"));           // false
            Console.WriteLine(solution.IsNumber(".e1"));                // false
            Console.WriteLine(solution.IsNumber("4e3."));               // false

            Console.WriteLine("*************************************************");

            Console.WriteLine(solution.IsNumber("3."));                 // true
            Console.WriteLine(solution.IsNumber("0"));                  // true
            Console.WriteLine(solution.IsNumber("   543    "));         // true
            Console.WriteLine(solution.IsNumber("4.5"));                // true
            Console.WriteLine(solution.IsNumber(" 0.1"));               // true
            Console.WriteLine(solution.IsNumber(" .1"));                // true
            Console.WriteLine(solution.IsNumber("-1"));                 // true
            Console.WriteLine(solution.IsNumber("+1"));                 // true
            Console.WriteLine(solution.IsNumber("2e10"));               // true
            Console.WriteLine(solution.IsNumber("53.5e93"));            // true
            Console.WriteLine(solution.IsNumber("6e-1"));               // true
            Console.WriteLine(solution.IsNumber("  -90e3  "));          // true
            Console.WriteLine(solution.IsNumber("53.e3"));              // true
            Console.WriteLine(solution.IsNumber("32.e-80123"));         // true

            Console.ReadKey();
        }
    }
}
