using System;
using System.Collections.Generic;

namespace SpiralMatrix
{
    public class Solution
    {
        public IList<int> SpiralOrder(int[][] matrix)
        {
            if (matrix.Length == 0)
            {
                return new List<int>();
            }

            var left = 0;
            var top = 0;
            var right = matrix[0].Length;
            var bottom = matrix.Length;

            var result = new List<int>();

            while (left < right && top < bottom)
            {
                // get top
                for (var i = left; i < right; i++)
                {
                    result.Add(matrix[top][i]);
                }

                // get right
                for (var i = top + 1; i < bottom; i++)
                {
                    result.Add(matrix[i][right - 1]);
                }

                if (top < bottom - 1 && left < right - 1)
                {
                    // get bottom
                    for (var i = right - 2; i >= left; i--)
                    {
                        result.Add(matrix[bottom - 1][i]);
                    }

                    // get left
                    for (var i = bottom - 2; i > top; i--)
                    {
                        result.Add(matrix[i][left]);
                    }
                }

                left++;
                top++;
                right--;
                bottom--;
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1, 2, 3},
                new int[] {4, 5, 6 },
                new int[] {7, 8, 9 }
            });

            var result2 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1, 2, 3, 4},
                new int[] { 5, 6, 7, 8 },
                new int[] { 9, 10, 11, 12 }
            });

            var result3 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1, 2 },
                new int[] { 3, 4 },
                new int[] { 5, 6 },
                new int[] { 7, 8 }
            });

            var result4 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1, 2, 3, 4},
                new int[] { 5, 6, 7, 8 },
                new int[] { 9, 10, 11, 12 },
                new int[] { 13, 14, 15, 16 },
                new int[] { 17, 18, 19, 20 }
            });

            var result5 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1, 2, 3, 4}
            });

            var result6 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1, 2, 3, 4},
                new int[] { 5, 6, 7, 8 }
            });

            var result7 = solution.SpiralOrder(new int[][]
            {
                new int[] { 1 }
            });

            var result8 = solution.SpiralOrder(new int[][]
            {
                new int[] { 7 },
                new int[] { 9 },
                new int[] { 6 },
            });

            Console.ReadKey();
        }
    }
}
