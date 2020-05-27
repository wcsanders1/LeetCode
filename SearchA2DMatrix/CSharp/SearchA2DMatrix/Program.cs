using System;

namespace SearchA2DMatrix
{
    public class Solution
    {
        public bool SearchMatrix(int[][] matrix, int target)
        {
            if (matrix.Length == 0 || matrix[0].Length == 0)
            {
                return false;
            }

            var rows = matrix.Length;
            var columns = matrix[0].Length;
            
            if (target < matrix[0][0] || target > matrix[rows - 1][columns - 1])
            {
                return false;
            }

            var start = 0;
            var end = rows - 1;
            var row = 0;

            while (start <= end)
            {
                row = (end + start) / 2;
                if (target >= matrix[row][0] && target <= matrix[row][columns - 1])
                {
                    break;
                }

                if (target < matrix[row][0])
                {
                    if (end == row)
                    {
                        end--;
                    }
                    else
                    {
                        end = row;
                    }
                }
                else
                {
                    if (start == row)
                    {
                        start++;
                    }
                    else
                    {
                        start = row;
                    }
                }
            }

            start = 0;
            end = columns - 1;

            while (start <= end)
            {
                var column = (end + start) / 2;
                
                if (target == matrix[row][column])
                {
                    return true;
                }

                if (target < matrix[row][column])
                {
                    if (end == column)
                    {
                        end--;
                    }
                    else
                    {
                        end = column;
                    }
                }
                else
                {
                    if (start == column)
                    {
                        start++;
                    }
                    else
                    {
                        start = column;
                    }
                }
            }

            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.SearchMatrix(new int[][]
            {
                new int[] {1, 3, 5, 7},
                new int[] {10, 11, 16, 20},
                new int[] {23, 30, 34, 50}
            }, 3));

            Console.WriteLine(solution.SearchMatrix(new int[][]
            {
                new int[] {1, 3, 5, 7},
                new int[] {10, 11, 16, 20},
                new int[] {23, 30, 34, 50}
            }, 13));

            Console.WriteLine(solution.SearchMatrix(new int[][]
            {
                new int[] {1}
            }, 1));

            Console.ReadKey();
        }
    }
}
