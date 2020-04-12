using System;

namespace ImplementStrStr
{
    public class Solution
    {
        public int StrStr(string haystack, string needle)
        {
            if (string.IsNullOrWhiteSpace(needle))
            {
                return 0;
            }

            if (string.IsNullOrWhiteSpace(haystack))
            {
                return -1;
            }

            for (var i = 0; i < haystack.Length; i++)
            {
                if (haystack[i] == needle[0])
                {
                    if (needle.Length == 1)
                    {
                        return i;
                    }

                    for (int n = 1; n < needle.Length; n++)
                    {
                        if (i + n >= haystack.Length)
                        {
                            return -1;
                        }

                        if (haystack[i + n] != needle[n])
                        {
                            break;
                        }

                        if (n == needle.Length - 1)
                        {
                            return i;
                        }
                    }
                }
            }

            return -1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.StrStr("hello", "ll"));
            Console.WriteLine(solution.StrStr("aaaaa", "bba"));
            Console.WriteLine(solution.StrStr("a", "a"));
            Console.WriteLine(solution.StrStr("mississippi", "issipi"));
            Console.WriteLine(solution.StrStr("mississippi", "issip"));

            Console.ReadKey();
        }
    }
}
