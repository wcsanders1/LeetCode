using System;

namespace DivideTwoIntegers
{
    public class Solution
    {
        public int Divide(int dividend, int divisor)
        {
            if (divisor == 1)
            {
                return dividend;
            }

            if (divisor == -1)
            {
                if (dividend == int.MinValue)
                {
                    return int.MaxValue;
                }

                return dividend * -1;
            }

            var temp = 1;
            var quotient = 0;
            var isNegative = (dividend < 0 || divisor < 0) && !(dividend < 0 && divisor < 0);

            var longDividend = (long)dividend;
            var longDivisor = (long)divisor;

            if (longDivisor < 0)
            {
                longDivisor *= -1;
            }

            if (longDividend < 0)
            {
                longDividend *= -1;
            }

            if (longDivisor < int.MinValue || longDividend < int.MinValue)
            {
                return int.MaxValue;
            }

            if (longDivisor == longDividend)
            {
                if (isNegative)
                {
                    return -1;
                }
                return 1;
            }

            if (longDivisor == 2)
            {
                longDividend >>= 1;
                if (isNegative)
                {
                    return (int)(longDividend * -1);
                }
                return (int)longDividend;
            }

            while (longDivisor < longDividend)
            {
                longDivisor <<= 1;
                temp <<= 1;
            }

            while (temp > 1)
            {
                longDivisor >>= 1;
                temp >>= 1;

                if (longDividend > longDivisor)
                {
                    longDividend -= longDivisor;
                    quotient += temp;
                }
            }

            if (isNegative)
            {
                quotient *= -1;
            }

            return quotient;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Divide(30, 5));
            Console.WriteLine(solution.Divide(30, 6));
            Console.WriteLine(solution.Divide(7, -3));
            Console.WriteLine(solution.Divide(-1, -1));
            Console.WriteLine(solution.Divide(-2147483648, -1));
            Console.WriteLine(solution.Divide(2147483647, 1));
            Console.WriteLine(solution.Divide(2147483647, 2));
            Console.WriteLine(solution.Divide(1, -1));
            Console.WriteLine(solution.Divide(-2147483648, 2));

            Console.ReadKey();
        }
    }
}
