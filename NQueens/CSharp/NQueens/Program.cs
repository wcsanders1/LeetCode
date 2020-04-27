using System;
using System.Collections.Generic;
using System.Linq;

namespace NQueens
{
    public class Solution
    {
        public IList<IList<string>> SolveNQueens(int n)
        {
            var result = new List<IList<string>>();

            GetQueens(result, new List<string>(), n);

            return result;
        }

        private void GetQueens(List<IList<string>> solutions, List<string> board, int n, int row = 0)
        {
            if (row == n)
            {
                solutions.Add(board);
                return;
            }

            board.Add(string.Empty);

            for (int y = 0; y < n; y++)
            {
                if (IsSafe(board, row, y, n))
                {
                    var newBoard = board.Select(s => s).ToList();
                    newBoard[row] = $"{newBoard[row]}Q";

                    while (newBoard[row].Length < n)
                    {
                        newBoard[row] = $"{newBoard[row]}.";
                    }

                    GetQueens(solutions, newBoard, n, row + 1);
                }

                board[row] = $"{board[row]}.";
            }
        }

        private bool IsSafe(List<string> board, int row, int y, int n)
        {
            for (var i = 0; i < board.Count - 1; i++)
            {
                if (board[i][y] != '.')
                {
                    return false;
                }
            }

            var tempRow = row;
            var tempY = y;

            while (--tempRow >= 0 && --tempY >= 0)
            {
                if (board[tempRow][tempY] != '.')
                {
                    return false;
                }
            }

            while (--row >= 0 && ++y < n)
            {
                if (board[row][y] != '.')
                {
                    return false;
                }
            }

            if (y < 0 || row < 0)
            {
                return true;
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.SolveNQueens(4);

            Console.ReadKey();
        }
    }
}
