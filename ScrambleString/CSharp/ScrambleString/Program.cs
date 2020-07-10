using System;

namespace ScrambleString
{
    // NOT DONE
    public class Solution
    {
        public bool IsScramble(string s1, string s2)
        {
            if (string.IsNullOrEmpty(s1))
            {
                return false;
            }

            if (s1.Length == 1)
            {
                return true;
            }

            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
