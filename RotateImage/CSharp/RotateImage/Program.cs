using System;
using System.Collections.Generic;

namespace RotateImage
{
    public class Solution
    {
        public void Rotate(int[][] matrix)
        {
            Rotate(matrix, 0, matrix.Length - 1);
        }

        private void Rotate(int[][] matrix, int start, int end)
        {
            if (start >= end)
            {
                return;
            }

            var next = new Queue<int>();

            // get left
            var fromEnd = end;
            for (var i = start; i <= end; i++)
            {
                next.Enqueue(matrix[fromEnd--][start]);
            }

            // get top
            for (var i = start; i <= end; i++)
            {
                next.Enqueue(matrix[start][i]);
            }

            // get right
            for (var i = start; i <= end; i++)
            {
                next.Enqueue(matrix[i][end]);
            }

            // get bottom
            for (var i = start; i <= end; i++)
            {
                next.Enqueue(matrix[end][i]);
            }

            // set top
            for (var i = start; i <= end; i++)
            {
                matrix[start][i] = next.Dequeue();
            }

            // set right
            for (var i = start; i <= end; i++)
            {
                matrix[i][end] = next.Dequeue();
            }

            // set bottom
            for (var i = end; i >= start; i--)
            {
                matrix[end][i] = next.Dequeue();
            }

            // set left
            fromEnd = start;
            for (var i = start; i <= end; i++)
            {
                matrix[fromEnd++][start] = next.Dequeue();
            }

            Rotate(matrix, start + 1, end - 1);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var matrix1 = new int[][]
            {
                new int[]{1, 2, 3 },
                new int[]{4, 5, 6 },
                new int[]{7, 8, 9 }
            };

            var matrix2 = new int[][]
            {
                new int[]{5, 1, 9, 11 },
                new int[]{2, 4, 8, 10 },
                new int[]{13, 3, 6, 7 },
                new int[]{15, 14, 12, 16 }
            };

            solution.Rotate(matrix1);
            solution.Rotate(matrix2);

            Console.ReadKey();
        }
    }
}
