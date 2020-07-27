using System;

namespace OutOfBoundaryPaths
{
    public class Solution
    {
        public int FindPaths(int m, int n, int N, int i, int j)
        {
            var moves = new int[][] { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };

            var result = 0;

            var dp = new long[m][];
            for (int col = 0; col < m; col++)
            {
                dp[col] = new long[n];
            }

            dp[i][j] = 1;

            for (int move = 0; move < N; move++)
            {
                var temp = new long[m][];
                for (int c = 0; c < m; c++)
                {
                    temp[c] = new long[n];
                }

                for (int col = 0; col < m; col++)
                {
                    for (int row = 0; row < n; row++)
                    {
                        foreach (var mv in moves)
                        {
                            var curCol = col + mv[0];
                            var curRow = row + mv[1];

                            if (MoveIsInside(curCol, curRow, m - 1, n - 1))
                            {
                                temp[curCol][curRow] = (temp[curCol][curRow] + dp[col][row]) % ((long)Math.Pow(10, 9) + 7);
                            }
                            else
                            {
                                result = (result + (int)dp[col][row]) % ((int)Math.Pow(10, 9) + 7);
                            }
                        }

                    }
                }
                dp = temp;
            }

            return result;
        }

        private bool MoveIsInside(int col, int row, int cols, int rows)
        {
            return col >= 0 && col <= cols && row >= 0 && row <= rows;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.FindPaths(2, 2, 2, 0, 0));
            Console.WriteLine(solution.FindPaths(1, 3, 3, 0, 1));
            Console.WriteLine(solution.FindPaths(8, 50, 23, 5, 26));

            Console.ReadKey();
        }
    }
}
