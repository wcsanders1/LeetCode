using System;

namespace Sqrtx
{
    public class Solution
    {
        public int MySqrt(int x)
        {
            var comp = (ulong)x;
            var result = comp;
            while (result * result > comp)
            {
                result /= 2;
            }

            while ((result + 1) * (result + 1) <= comp)
            {
                result++;
            }

            return (int)result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MySqrt(4));
            Console.WriteLine(solution.MySqrt(8));
            Console.WriteLine(solution.MySqrt(400));
            Console.WriteLine(solution.MySqrt(147));
            Console.WriteLine(solution.MySqrt(2025));
            Console.WriteLine(solution.MySqrt(2147395599));

            Console.ReadKey();
        }
    }
}
