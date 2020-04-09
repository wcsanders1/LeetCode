using System;
using System.Text;

namespace LongestCommonPrefix
{
    public class Solution
    {
        public string LongestCommonPrefix(string[] strs)
        {
            if (strs.Length == 0)
            {
                return string.Empty;
            }

            var result = strs[0];

            for (var i = 1; i < strs.Length; i++)
            {
                var str = strs[i];
                var shortestLength = Math.Min(result.Length, str.Length);

                var newPrefix = new StringBuilder();
                for (var ii = 0; ii < shortestLength; ii++)
                {
                    if (result[ii] != str[ii])
                    {
                        break;
                    }
                    newPrefix.Append(result[ii]);
                }

                if (newPrefix.Length < result.Length)
                {
                    result = newPrefix.ToString();
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

            Console.WriteLine(solution.LongestCommonPrefix(new string[] { "flower", "flow", "flight" }));
            Console.WriteLine(solution.LongestCommonPrefix(new string[] { "dog", "racecar", "car" }));

            Console.ReadKey();
        }
    }
}
