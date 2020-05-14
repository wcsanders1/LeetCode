using System;
using System.Text;

namespace AddBinary
{
    public class Solution
    {
        public string AddBinary(string a, string b)
        {
            if (string.IsNullOrWhiteSpace(a) && string.IsNullOrWhiteSpace(b))
            {
                return "0";
            }

            if (string.IsNullOrWhiteSpace(a))
            {
                return b;
            }

            if (string.IsNullOrWhiteSpace(b))
            {
                return a;
            }

            var result = new StringBuilder();

            var aIndex = a.Length - 1;
            var bIndex = b.Length - 1;

            var count = Math.Max(aIndex, bIndex);
            var carry = false;
            var aboveZero = false;

            while (count-- >= 0)
            {
                var aNum = aIndex >= 0 ? a[aIndex--] : '0';
                var bNum = bIndex >= 0 ? b[bIndex--] : '0';

                if (aNum == '0' && bNum == '0')
                {
                    result.Insert(0, carry ? "1" : "0");
                    carry = false;
                }
                else if (aNum == '1' && bNum == '1')
                {
                    aboveZero = true;
                    result.Insert(0, carry ? "1" : "0");
                    carry = true;
                }
                else
                {
                    aboveZero = true;
                    result.Insert(0, carry ? "0" : "1");
                }
            }

            if (!aboveZero)
            {
                return "0";
            }

            if (carry)
            {
                result.Insert(0, "1");
            }

            return result.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.AddBinary("11", "1"));
            Console.WriteLine(solution.AddBinary("1010", "1011"));
            Console.WriteLine(solution.AddBinary("11", "11"));
            Console.WriteLine(solution.AddBinary("111100111101", "1100011111100101010"));
            Console.WriteLine(solution.AddBinary("000000", "00000000000"));

            Console.ReadKey();
        }
    }
}
