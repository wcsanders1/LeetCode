using System;
using System.Collections.Generic;

namespace StoneGameIV
{
    public class Solution
    {
        private enum GameState
        {
            Loses = 0,
            Wins = 1,
        }

        public bool WinnerSquareGame(int n)
        {
            if (n < 1)
            {
                return false;
            }

            var squares = new List<int>();
            var dp = new GameState[n];
            var nextSquare = 1;
            var lastRoot = 1;

            for (int i = 1; i <= n; i++)
            {
                var index = i - 1;
                if (i == nextSquare)
                {
                    dp[index] = GameState.Wins;
                    nextSquare = ++lastRoot * lastRoot;
                    squares.Add(i);
                }
                else
                {
                    for (int s = squares.Count - 1; s >= 0; s--)
                    {
                        if (dp[index - squares[s]] == GameState.Loses)
                        {
                            dp[index] = GameState.Wins;
                            break;
                        }
                    }
                }
            }

            return dp[n - 1] == GameState.Wins;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.WinnerSquareGame(1));
            Console.WriteLine(solution.WinnerSquareGame(2));
            Console.WriteLine(solution.WinnerSquareGame(4));
            Console.WriteLine(solution.WinnerSquareGame(7));
            Console.WriteLine(solution.WinnerSquareGame(17));

            Console.ReadKey();
        }
    }
}
