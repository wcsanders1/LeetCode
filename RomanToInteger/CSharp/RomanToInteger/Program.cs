using System;
using System.Collections.Generic;

namespace RomanToInteger
{
    public class Solution
    {
        private static readonly Dictionary<string, int> RomanToArabic = new Dictionary<string, int>
        {
            {"M", 1000 }, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, 
            {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };

        public int RomanToInt(string s)
        {
            var result = 0;

            for (var i = 0; i < s.Length; i++)
            {
                if (i < s.Length - 1)
                {
                    var roman = $"{s[i]}{s[i + 1]}";
                    if (RomanToArabic.TryGetValue(roman, out var doubleValue))
                    {
                        result += doubleValue;
                        i++;
                        continue;
                    }
                }
                result += RomanToArabic[s[i].ToString()];
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.RomanToInt("III"));
            Console.WriteLine(solution.RomanToInt("IV"));
            Console.WriteLine(solution.RomanToInt("IX"));
            Console.WriteLine(solution.RomanToInt("LVIII"));
            Console.WriteLine(solution.RomanToInt("MCMXCIV"));

            Console.ReadKey();
        }
    }
}
