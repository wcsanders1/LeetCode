using System;

namespace NumberOfIslands
{
    public class Solution
    {
        public int NumIslands(char[][] grid)
        {
            if (grid == null || grid.Length == 0)
            {
                return 0;
            }

            var visited = new bool[grid.Length][];
            for (int column = 0; column < grid.Length; column++)
            {
                visited[column] = new bool[grid[column].Length];
            }

            var islands = 0;
            for (int column = 0; column < grid.Length; column++)
            {
                for (int row = 0; row < grid[column].Length; row++)
                {
                    if (grid[column][row] == '1' && !visited[column][row])
                    {
                        islands++;
                        MarkIsland(grid, column, row, visited);
                    }
                }
            }

            return islands;
        }

        private void MarkIsland(char[][] grid, int column, int row, bool[][] visited)
        {
            if (visited[column][row] || grid[column][row] != '1')
            {
                return;
            }

            visited[column][row] = true;

            if (column < grid.Length - 1)
            {
                MarkIsland(grid, column + 1, row, visited);
            }

            if (row < grid[column].Length - 1)
            {
                MarkIsland(grid, column, row + 1, visited);
            }

            if (row > 0)
            {
                MarkIsland(grid, column, row - 1, visited);
            }

            if (column > 0)
            {
                MarkIsland(grid, column - 1, row, visited);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var gridOne = new char[][]
            {
                new char[]{'1', '1', '1', '1', '0'},
                new char[]{'1', '1', '0', '1', '0'},
                new char[]{'1', '1', '0', '0', '0'},
                new char[]{'0', '0', '0', '0', '0'}
            };

            var gridTwo = new char[][]
            {
                new char[]{'1', '1', '0', '0', '0'},
                new char[]{'1', '1', '0', '0', '0'},
                new char[]{'0', '0', '1', '0', '0'},
                new char[]{'0', '0', '0', '1', '1'}
            };

            var gridThree = new char[][]
            {
                new char[]{'1', '1', '1'},
                new char[]{'0', '1', '0'},
                new char[]{'1', '1', '1'}
            };

            Console.WriteLine(solution.NumIslands(gridOne));
            Console.WriteLine(solution.NumIslands(gridTwo));
            Console.WriteLine(solution.NumIslands(gridThree));

            Console.ReadKey();
        }
    }
}
