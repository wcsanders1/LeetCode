using System;

namespace MinimumPathSum
{
    public class Solution
    {
        public int MinPathSum(int[][] grid)
        {
            if (grid.Length == 0 || grid[0].Length == 0)
            {
                return 0;
            }

            var rows = grid.Length;
            var columns = grid[0].Length;

            var result = new int[rows][];

            for (var row = rows - 1; row >= 0; row--)
            {
                result[row] = new int[columns];
                for (var column = columns - 1; column >= 0; column--)
                {
                    if (row == rows - 1 && column == columns - 1)
                    {
                        result[row][column] = grid[row][column];
                        continue;
                    }

                    if (row == rows - 1)
                    {
                        result[row][column] = grid[row][column] + result[row][column + 1];
                        continue;
                    }

                    if (column == columns - 1)
                    {
                        result[row][column] = grid[row][column] + result[row + 1][column];
                        continue;
                    }

                    result[row][column] = Math.Min(grid[row][column] + result[row][column + 1],
                        grid[row][column] + result[row + 1][column]);
                }
            }

            return result[0][0];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MinPathSum(new int[][]
            {
                new int[] {1, 3, 1},
                new int[] {1, 5, 1},
                new int[] {4, 2, 1}
            }));

            Console.WriteLine(solution.MinPathSum(new int[][]
            {
                new int[] {1, 3, 1}
            }));

            Console.WriteLine(solution.MinPathSum(new int[][]
            {
                new int[] {1}
            }));

            Console.WriteLine(solution.MinPathSum(new int[][]
            {
                new int[] {1, 3, 1, 6},
                new int[] {2, 1, 1, 3},
                new int[] {1, 3, 2, 7},
            }));

            Console.WriteLine(solution.MinPathSum(new int[][]
            {
                new int[] {}
            }));

            Console.ReadKey();
        }
    }
}
