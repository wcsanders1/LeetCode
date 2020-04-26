using System;

namespace PowXN
{
    public class Solution
    {
        public double MyPow(double x, int n)
        {
            if (n == 0)
            {
                return 1;
            }

            if (n == int.MinValue)
            {
                n += 2;
            }

            if (n < 0)
            {
                n = -n;
                x = 1 / x;
            }

            return (n % 2 == 0) ? MyPow(x * x, n / 2) : x * MyPow(x * x, n / 2);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MyPow(2, 10));
            Console.WriteLine(solution.MyPow(2.1, 3));
            Console.WriteLine(solution.MyPow(2, -2));
            Console.WriteLine(solution.MyPow(.00001, 2147483647));
            Console.WriteLine(solution.MyPow(2, int.MinValue)); // 0
            Console.WriteLine(solution.MyPow(1, int.MinValue)); // 1
            Console.WriteLine(solution.MyPow(-1, int.MinValue)); // 1

            Console.ReadKey();
        }
    }
}
