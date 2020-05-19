using System;

namespace ClimbingStairs
{
    public class Solution
    {
        public int ClimbStairs(int n)
        {
            if (n == 0)
            {
                return 0;
            }

            var previous = 0;
            var result = 1;
            for (int i = 1; i <= n; i++)
            {
                var r = result;
                result += previous;
                previous = r;
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.ClimbStairs(0));
            Console.WriteLine(solution.ClimbStairs(1));
            Console.WriteLine(solution.ClimbStairs(2));
            Console.WriteLine(solution.ClimbStairs(3));
            Console.WriteLine(solution.ClimbStairs(4));
            Console.WriteLine(solution.ClimbStairs(5));

            Console.ReadKey();
        }
    }
}
