using System;

namespace DungeonGame
{
    public class Solution
    {
        public int CalculateMinimumHP(int[][] dungeon)
        {
            if (dungeon == null || dungeon.Length == 0)
            {
                return 0;
            }

            var minHealth = new int[dungeon.Length][];
            for (int i = 0; i < dungeon.Length; i++)
            {
                minHealth[i] = new int[dungeon[i].Length];
            }

            for (int row = dungeon.Length - 1; row >= 0; row--)
            {
                var lastColumn = dungeon[row].Length - 1;
                if (row == dungeon.Length - 1)
                {
                    if (dungeon[row][lastColumn] >= 0)
                    {
                        minHealth[row][lastColumn] = 1;
                    }
                    else
                    {
                        minHealth[row][lastColumn] = (dungeon[row][lastColumn] * -1) + 1;
                    }
                }
                else
                {
                    var needed = minHealth[row + 1][lastColumn];
                    minHealth[row][lastColumn] = Math.Max(1, needed - dungeon[row][lastColumn]);
                }
            }

            for (int column = dungeon[dungeon.Length - 1].Length - 2; column >= 0; column--)
            {
                var lastRow = dungeon.Length - 1;
                var needed = minHealth[lastRow][column + 1];
                minHealth[lastRow][column] = Math.Max(1, needed - dungeon[lastRow][column]);
            }

            for (int row = dungeon.Length - 2; row >= 0; row--)
            {
                for (int column = dungeon[row].Length - 2; column >= 0; column--)
                {
                    var needed = Math.Min(minHealth[row + 1][column], minHealth[row][column + 1]);
                    minHealth[row][column] = Math.Max(1, needed - dungeon[row][column]);
                }
            }

            return minHealth[0][0];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.CalculateMinimumHP(new int[][]
            {
                new int[]{-2, -3, 3},
                new int[]{-5, -10, 1},
                new int[]{10, 30, -5},
            }));

            Console.ReadKey();
        }
    }
}
