using System;
using System.Collections.Generic;

namespace UglyNumberII
{
    public class Solution
    {
        public int NthUglyNumber(int n)
        {
            var uglies = new int[n];
            uglies[0] = 1;

            var indexTwo = 0;
            var indexThree = 0;
            var indexFive = 0;

            var factorTwo = 2;
            var factorThree = 3;
            var factorFive = 5;

            for (int i = 1; i < n; i++)
            {
                var min = Math.Min(factorTwo, Math.Min(factorThree, factorFive));
                uglies[i] = min;

                if (min == factorTwo)
                {
                    factorTwo = uglies[++indexTwo] * 2;
                }

                if (min == factorThree)
                {
                    factorThree = uglies[++indexThree] * 3;
                }
                if (min == factorFive)
                {
                    factorFive = uglies[++indexFive] * 5;
                }
            }

            return uglies[n - 1];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.NthUglyNumber(10));
            Console.WriteLine(solution.NthUglyNumber(1));
            Console.WriteLine(solution.NthUglyNumber(3));
            Console.WriteLine(solution.NthUglyNumber(100));
            Console.WriteLine(solution.NthUglyNumber(300));
            Console.WriteLine(solution.NthUglyNumber(1690));

            Console.ReadKey();
        }
    }
}
