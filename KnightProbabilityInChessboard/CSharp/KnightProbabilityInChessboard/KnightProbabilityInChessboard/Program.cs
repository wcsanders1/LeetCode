using System;

namespace KnightProbabilityInChessboard
{
    public class Solution
    {
        private int[][] Moves = new int[][]
        {
            new int[] {1, 2},
            new int[] {1, -2},
            new int[] {2, 1},
            new int[] {2, -1},
            new int[] {-1, 2},
            new int[] {-1, -2},
            new int[] {-2, 1},
            new int[] {-2, -1},
        };

        public double KnightProbability(int N, int K, int r, int c)
        {
            var dp = new double[N][];
            for (int i = 0; i < N; i++)
            {
                dp[i] = new double[N];
                for (int j = 0; j < N; j++)
                {
                    dp[i][j] = 1;
                }
            }

            for (int move = 0; move < K; move++)
            {
                var tempDP = new double[N][];
                for (int t = 0; t < N; t++)
                {
                    tempDP[t] = new double[N];
                }

                for (int column = 0; column < N; column++)
                {
                    for (int row = 0; row < N; row++)
                    {
                        foreach (var m in Moves)
                        {
                            var tRow = row + m[0];
                            var tCol = column + m[1];
                            if (IsLegalMove(tRow, tCol, N))
                            {
                                tempDP[column][row] += dp[tCol][tRow];
                            }
                        }
                    }
                }

                dp = tempDP;
            }

            return dp[r][c] / Math.Pow(8, K);
        }

        private bool IsLegalMove(int row, int column, int length)
        {
            return row >= 0 && row < length && column >= 0 && column < length;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.KnightProbability(3, 3, 0, 0));
            Console.WriteLine(solution.KnightProbability(8, 30, 6, 4));

            Console.ReadKey();
        }
    }
}
