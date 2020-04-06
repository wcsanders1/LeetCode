using System;
using System.Text;

namespace ZigZagConversion
{
    public class Solution
    {
        public string Convert(string s, int numRows)
        {
            var increment = (numRows * 2) - 2;

            if (s.Length <= numRows || increment <= 0)
            {
                return s;
            }

            var result = new StringBuilder();

            var skipBegin = increment;
            var skipEnd = 0;

            for (var i = 0; i < increment; i++)
            {
                var currentSkip = skipBegin > 0 ? skipBegin : skipEnd;
                var useBegin = true;
                var alternate = skipBegin > 0 && skipEnd > 0;
                for (var j = i; j < s.Length; j += currentSkip)
                {
                    result.Append(s[j]);

                    if (result.Length == s.Length)
                    {
                        return result.ToString();
                    }

                    if (alternate)
                    {
                        currentSkip = useBegin ? skipBegin : skipEnd;
                    }

                    useBegin = !useBegin;
                }
                skipBegin -= 2;
                skipEnd += 2;
            }

            return result.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Convert("PAYPALISHIRING", 3));
            Console.WriteLine(solution.Convert("PAYPALISHIRING", 4));
            Console.WriteLine(solution.Convert("A", 1));
            Console.WriteLine(solution.Convert("AB", 1));

            Console.ReadKey();
        }
    }
}
