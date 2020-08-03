using System;
using System.Linq;

namespace UniqueSubstringsInWraparoundString
{
    public class Solution
    {
        public int FindSubstringInWraproundString(string p)
        {
            if (string.IsNullOrWhiteSpace(p))
            {
                return 0;
            }

            var results = new int[26];

            var currentMax = 0;
            for (int i = 0; i < p.Length; i++)
            {
                if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25))
                {
                    currentMax++;
                }
                else
                {
                    currentMax = 1;
                }

                var index = p[i] - 'a';

                results[index] = Math.Max(results[index], currentMax);
            }

            return results.Sum();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.FindSubstringInWraproundString("a"));
            Console.WriteLine(solution.FindSubstringInWraproundString("cac"));
            Console.WriteLine(solution.FindSubstringInWraproundString("zab"));

            Console.ReadKey();
        }
    }
}
