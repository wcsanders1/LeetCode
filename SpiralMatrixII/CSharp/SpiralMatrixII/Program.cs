using System;

namespace SpiralMatrixII
{
    public class Solution
    {
        public int[][] GenerateMatrix(int n)
        {
            var result = new int[n][];
            for (int i = 0; i < n; i++)
            {
                result[i] = new int[n];
            }

            var left = 0;
            var top = 0;
            var right = n;
            var bottom = n;

            var number = 1;

            while (left < right && top < bottom)
            {
                for (var i = left; i < right; i++)
                {
                    result[top][i] = number++;
                }

                for (var i = top + 1; i < bottom; i++)
                {
                    result[i][right - 1] = number++;
                }

                if (top < bottom - 1 && left < right - 1)
                {
                    for (var i = right - 2; i >= left; i--)
                    {
                        result[bottom - 1][i] = number++;
                    }

                    for (var i = bottom - 2; i > top; i--)
                    {
                        result[i][left] = number++;
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

            var result1 = solution.GenerateMatrix(3);
            var result2 = solution.GenerateMatrix(4);
            var result3 = solution.GenerateMatrix(5);
            var result4 = solution.GenerateMatrix(0);
            var result5 = solution.GenerateMatrix(1);
            var result6 = solution.GenerateMatrix(2);

            Console.ReadKey();
        }
    }
}
