using System;
using System.Collections.Generic;

namespace MaximalRectangle
{
    public class Solution
    {
        public int MaximalRectangle(char[][] matrix)
        {
            if (matrix == null || matrix.Length == 0)
            {
                return 0;
            }

            var histogram = new int[matrix.Length][];
            for (int column = 0; column < matrix.Length; column++)
            {
                histogram[column] = new int[matrix[column].Length];
                for (int row = 0; row < matrix[column].Length; row++)
                {
                    var matrixNum = matrix[column][row] == '0' ? 0 : 1;
                    if (column == 0)
                    {
                        histogram[0][row] = matrixNum;
                    }
                    else
                    {
                        histogram[column][row] = matrixNum == 0 ? 0 : histogram[column - 1][row] + 1;
                    }
                }
            }

            var result = 0;
            for (int column = 0; column < histogram.Length; column++)
            {
                var indices = new Stack<int>();
                indices.Push(-1);

                var currentIndex = 0;
                while(currentIndex < histogram[column].Length)
                {
                    while (indices.Peek() != -1 && histogram[column][currentIndex] <= histogram[column][indices.Peek()])
                    {
                        result = Math.Max(result, histogram[column][indices.Pop()] * (currentIndex - indices.Peek() - 1));
                    }

                    indices.Push(currentIndex++);
                }

                while(indices.Peek() != -1)
                {
                    result = Math.Max(result, histogram[column][indices.Pop()] * (currentIndex - indices.Peek() - 1));
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

            var gridOne = new char[][]
            {
                new char[] {'1', '0', '1', '0', '0'},
                new char[] {'1', '0', '1', '1', '1'},
                new char[] {'1', '1', '1', '1', '1'},
                new char[] {'1', '0', '0', '1', '0'},
            };

            Console.WriteLine(solution.MaximalRectangle(gridOne));

            Console.ReadKey();
        }
    }
}
