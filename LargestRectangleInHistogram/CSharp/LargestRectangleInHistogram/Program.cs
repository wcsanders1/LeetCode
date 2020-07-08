using System;

namespace LargestRectangleInHistogram
{
    public class Solution
    {
        public int LargestRectangleArea(int[] heights)
        {
            var result = 0;

            var highestElement = 0;

            for (int i = 0; i < heights.Length; i++)
            {
                var height = heights[i];
                var currentRectangle = height;
                var currentBiggest = currentRectangle;
                
                if (highestElement == 1 && result >= 1)
                {
                    return result;
                }

                for (int ii = i; ii < heights.Length; ii++)
                {
                    var newHeight = heights[ii];
                    if (newHeight > highestElement)
                    {
                        highestElement = newHeight;
                    }

                    var distance = (ii - i) + 1;
                    if (heights[ii] < height)
                    {
                        height = heights[ii];
                    }

                    currentRectangle = height * distance;
                    if (currentRectangle > currentBiggest)
                    {
                        currentBiggest = currentRectangle;
                    }
                }

                if (currentBiggest > result)
                {
                    result = currentBiggest;
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

            Console.WriteLine(solution.LargestRectangleArea(new int[] { 2, 1, 5, 6, 2, 3 }));
            Console.WriteLine(solution.LargestRectangleArea(new int[] { 2, 1, 5, 6, 2, 3, 2, 2 }));
            Console.WriteLine(solution.LargestRectangleArea(new int[] { 4, 2, 0, 3, 2, 4, 3, 4 }));

            Console.ReadKey();
        }
    }
}
