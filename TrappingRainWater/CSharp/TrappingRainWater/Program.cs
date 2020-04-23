using System;
using System.Linq;

namespace TrappingRainWater
{
    public class Solution
    {
        public int Trap(int[] height)
        {
            if (height == null || height.Length <= 2)
            {
                return 0;
            }

            var ultimateHighest = height[0];
            var ultimateHighestIndex = 0;
            var values = new int[height.Length];

            for (var i = 1; i < height.Length; i++)
            {
                var currentHeight = height[i];
                if (currentHeight >= ultimateHighest)
                {
                    for (int inner = ultimateHighestIndex + 1; inner < i; inner++)
                    {
                        values[inner] = ultimateHighest - height[inner];
                    }
                    ultimateHighest = currentHeight;
                    ultimateHighestIndex = i;
                }
                else if (currentHeight > height[i - 1])
                {
                    for (int inner = ultimateHighestIndex + 1; inner < i; inner++)
                    {
                        var val = currentHeight - height[inner];
                        if (val < values[inner])
                        {
                            continue;
                        }
                        values[inner] = val;
                    }
                }
            }

            return values.Sum();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Trap(new int[] { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 })); //6
            Console.WriteLine(solution.Trap(new int[] { 5, 4, 3, 2, 1 })); //0
            Console.WriteLine(solution.Trap(new int[] { 2, 3, 4, 5, 6 })); //0
            Console.WriteLine(solution.Trap(new int[] { 6, 5, 6 })); //1
            Console.WriteLine(solution.Trap(new int[] { 6, 5, 6, 5, 99 })); //2
            Console.WriteLine(solution.Trap(new int[] { 6, 5, 6, 5, 99, 0, 5 })); //7
            Console.WriteLine(solution.Trap(new int[] { 6, 5, 6, 5, 99, 0, 1, 5 })); //11
            Console.WriteLine(solution.Trap(new int[] { 5, 2, 1, 2, 1, 5 })); //14
            Console.WriteLine(solution.Trap(new int[] { 5, 4, 1, 2 })); //1
            Console.WriteLine(solution.Trap(new int[] { 9, 6, 8, 8, 5, 6, 3 })); //3

            Console.ReadKey();
        }
    }
}
