using System;
using System.Collections.Generic;

namespace SetMatrixZeroes
{
    public class Solution
    {
        public void SetZeroes(int[][] matrix)
        {
            var zeroedColumns = new List<int>();

            for (var row = 0; row < matrix.Length; row++)
            {
                for (int column = 0; column < matrix[row].Length; column++)
                {
                    if (matrix[row][column] == 0)
                    {
                        for (int i = 0; i < matrix[row].Length; i++)
                        {
                            if (matrix[row][i] == 0)
                            {
                                zeroedColumns.Add(i);
                            }
                            matrix[row][i] = 0;
                        }
                        
                        break;
                    }
                }
            }

            foreach (var column in zeroedColumns)
            {
                for (var row = 0; row < matrix.Length; row++)
                {
                    matrix[row][column] = 0;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var matrix1 = new int[][] 
            { 
                new int[] { 1, 1, 1 }, 
                new int[] { 1, 0, 1 },
                new int[] { 1, 1, 1 }
            };

            var matrix2 = new int[][] 
            { 
                new int[] { 0, 1, 2, 0 }, 
                new int[] { 3, 4, 5, 2 },
                new int[] { 1, 3, 1, 5 },
            };

            solution.SetZeroes(matrix1);
            solution.SetZeroes(matrix2);

            Console.ReadKey();
        }
    }
}
