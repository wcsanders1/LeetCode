using System;
using System.Collections.Generic;

namespace ReverseInteger
{
    public class Solution
    {
        public int Reverse(int x)
        {
            var isNegative = x < 0;
            var digits = new List<int>();

            if (isNegative)
            {
                x *= -1;
            }

            while (x > 0)
            {
                digits.Add(x % 10);
                x /= 10;
            }

            var result = 0;
            var power = 1;
            for (var i = digits.Count - 1; i >= 0; i--)
            {
                try
                {
                    result = checked(result + digits[i] * power);
                }
                catch (Exception)
                {
                    return 0;
                }
                
                try
                {
                    power = checked(power * 10);
                }
                catch (Exception)
                {
                    if (i == 0)
                    {
                        if (isNegative)
                        {
                            return result *= -1;
                        }
                        return result;
                    }
                    return 0;
                }
            }

            if (isNegative)
            {
                result *= -1;
            }

            return result;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Reverse(123));
            Console.WriteLine(solution.Reverse(-123));
            Console.WriteLine(solution.Reverse(120));
            Console.WriteLine(solution.Reverse(1));
            Console.WriteLine(solution.Reverse(-1));
            Console.WriteLine(solution.Reverse(-2147483412));
            Console.WriteLine(solution.Reverse(1534236469));


            Console.ReadKey();
        }
    }
}
