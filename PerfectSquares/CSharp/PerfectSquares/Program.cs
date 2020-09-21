using System;
using System.Collections.Generic;

namespace PerfectSquares
{
    public class Solution
    {
        public int NumSquares(int n)
        {
            if (n < 2)
            {
                return n;
            }

            var sums = new Dictionary<int, int>();
            var squares = new List<int>();

            for (int i = 1; i <= n; i++)
            {
                squares.Add(i * i);

                var leastSquare = GetLeastSquare(squares, sums, i);

                var sum = i / leastSquare;
                var remainder = i % leastSquare;

                if (remainder > 0)
                {
                    sum += sums[remainder];
                }

                sums.Add(i, sum);
            }

            return sums[n];
        }

        private static int GetLeastSquare(List<int> squares, Dictionary<int, int> sums, int num)
        {
            var leastSum = num;
            var leastSquare = 1;

            foreach (var square in squares)
            {
                if (square == num)
                {
                    return square;
                }

                if (square > num)
                {
                    return leastSquare;
                }

                var sum = num / square;
                var remainder = num % square;

                if (remainder > 0)
                {
                    sum += sums[remainder];
                }

                if (sum < leastSum)
                {
                    leastSum = sum;
                    leastSquare = square;
                }
            }

            return leastSquare;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.NumSquares(12));
            Console.WriteLine(solution.NumSquares(13));
            Console.WriteLine(solution.NumSquares(16));

            Console.ReadKey();
        }
    }
}
