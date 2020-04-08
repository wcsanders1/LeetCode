using System;

namespace ContainerWithMostWater
{
    public class Solution
    {
        public int MaxArea(int[] height)
        {
            var result = 0;

            var startIndex = 0;
            var endIndex = height.Length - 1;

            while (startIndex < endIndex)
            {
                var distance = endIndex - startIndex;
                var startHeight = height[startIndex];
                var endHeight = height[endIndex];

                var shorterHeight = Math.Min(startHeight, endHeight);

                var water = distance * shorterHeight;

                if (water > result)
                {
                    result = water;
                }

                if (startHeight <= endHeight)
                {
                    startIndex++;
                }
                else
                {
                    endIndex--;
                }
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxArea(new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 }));
            Console.WriteLine(solution.MaxArea(new int[] { 8, 10, 14, 0, 13, 10, 9, 9, 11, 11 }));

            Console.ReadKey();
        }
    }
}
