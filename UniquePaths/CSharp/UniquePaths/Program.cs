using System;

namespace UniquePaths
{
    public class Solution
    {
        public int UniquePaths(int m, int n)
        {
            if (m == 1 || n == 1)
            {
                return 1;
            }

            var grid = new int[n][];

            for (int row = n - 1; row >= 0; row--)
            {
                grid[row] = new int[m];

                for (int column = m - 1; column >= 0; column--)
                {
                    if (row == n - 1)
                    {
                        if (column == m - 1)
                        {
                            grid[row][column] = 0;
                        }
                        else
                        {
                            grid[row][column] = 1;
                        }
                    }
                    else if (column == m - 1)
                    {
                        grid[row][column] = 1;
                    }
                    else
                    {
                        grid[row][column] = grid[row + 1][column] + grid[row][column + 1];
                    }
                }
            }

            return grid[0][0];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.UniquePaths(3, 2));
            Console.WriteLine(solution.UniquePaths(7, 3));
            Console.WriteLine(solution.UniquePaths(7, 4));
            Console.WriteLine(solution.UniquePaths(1, 2));

            Console.ReadKey();
        }
    }
}
