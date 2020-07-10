using System;

namespace RottingOranges
{
    public class Solution
    {
        public int OrangesRotting(int[][] grid)
        {
            if (grid == null || grid.Length == 0)
            {
                return 0;
            }

            var hasOranges = false;

            for (int i = 0; i < grid.Length * grid[0].Length; i++)
            {
                for (int column = 0; column < grid.Length; column++)
                {
                    for (int row = 0; row < grid[column].Length; row++)
                    {
                        var cell = grid[column][row];

                        if (cell == 0)
                        {
                            continue;
                        }

                        if (cell == 1)
                        {
                            hasOranges = true;
                            continue;
                        }

                        hasOranges = true;

                        var newMinute = cell + 1;
                        if (row > 0 && grid[column][row - 1] > 0)
                        {
                            if (grid[column][row - 1] == 1 || grid[column][row - 1] > newMinute)
                            {
                                grid[column][row - 1] = newMinute;
                            }
                        }

                        if (row < grid[column].Length - 1 && grid[column][row + 1] > 0)
                        {
                            if (grid[column][row + 1] == 1 || grid[column][row + 1] > newMinute)
                            {
                                grid[column][row + 1] = newMinute;
                            }
                        }

                        if (column > 0 && grid[column - 1][row] > 0)
                        {
                            if (grid[column - 1][row] == 1 || grid[column - 1][row] > newMinute)
                            {
                                grid[column - 1][row] = newMinute;
                            }
                        }

                        if (column < grid.Length - 1 && grid[column + 1][row] > 0)
                        {
                            if (grid[column + 1][row] == 1 || grid[column + 1][row] > newMinute)
                            {
                                grid[column + 1][row] = newMinute;
                            }
                        }
                    }
                }
            }

            if (!hasOranges)
            {
                return 0;
            }

            var result = 0;

            for (int column = 0; column < grid.Length; column++)
            {
                for (int row = 0; row < grid[column].Length; row++)
                {
                    if (grid[column][row] == 1)
                    {
                        return -1;
                    }

                    if (grid[column][row] > result)
                    {
                        result = grid[column][row];
                    }
                }
            }

            return result - 2;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var gridOne = new int[][]
            {
                new int[]{2, 1, 1,},
                new int[]{1, 1, 0,},
                new int[]{0, 1, 1,},
            };

            var gridTwo = new int[][]
            {
                new int[]{0, 2}
            };

            var gridThree = new int[][]
            {
                new int[]{1, 1, 2, 0, 2, 0}
            };

            var gridFour = new int[][]
            {
                new int[]{2, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                new int[]{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                new int[]{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                new int[]{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
                new int[]{1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                new int[]{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                new int[]{1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                new int[]{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                new int[]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            };

            Console.WriteLine(solution.OrangesRotting(gridOne));
            Console.WriteLine(solution.OrangesRotting(gridTwo));
            Console.WriteLine(solution.OrangesRotting(gridThree));
            Console.WriteLine(solution.OrangesRotting(gridFour));

            Console.ReadKey();
        }
    }
}
