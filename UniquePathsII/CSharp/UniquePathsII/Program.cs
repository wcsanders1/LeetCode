using System;

namespace UniquePathsII
{
    public class Solution
    {
        public int UniquePathsWithObstacles(int[][] obstacleGrid)
        {
            var result = new int[obstacleGrid.Length][];

            for (var row = obstacleGrid.Length - 1; row >= 0 ; row--)
            {
                result[row] = new int[obstacleGrid[row].Length];
                for (var column = obstacleGrid[row].Length - 1; column >= 0; column--)
                {
                    if (row == obstacleGrid.Length - 1 && column == obstacleGrid[row].Length - 1)
                    {
                        result[row][column] = obstacleGrid[row][column] == 0 ? 1 : 0;
                        continue;
                    }

                    if (row == obstacleGrid.Length - 1)
                    {
                        if (obstacleGrid[row][column] == 0)
                        {
                            result[row][column] = result[row][column + 1];
                        }
                        else
                        {
                            result[row][column] = 0;
                        }
                        continue;
                    }

                    if (column == obstacleGrid[row].Length - 1)
                    {
                        if (obstacleGrid[row][column] == 0)
                        {
                            result[row][column] = result[row + 1][column];
                        }
                        else
                        {
                            result[row][column] = 0;
                        }
                        continue;
                    }

                    if (obstacleGrid[row][column] == 1)
                    {
                        result[row][column] = 0;
                    }
                    else
                    {
                        result[row][column] = result[row][column + 1] + result[row + 1][column];
                    }
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

            Console.WriteLine(solution.UniquePathsWithObstacles(new int[][]
            {
                new int []{0, 0, 0},
                new int []{0, 1, 0},
                new int []{0, 0, 0}
            }));

            Console.WriteLine(solution.UniquePathsWithObstacles(new int[][]
            {
                new int []{1}
            }));

            Console.ReadKey();
        }
    }
}
