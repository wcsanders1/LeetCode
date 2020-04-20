using System;

namespace SudokuSolver
{
    public class Solution
    {
        private const int BoardSize = 9;

        public void SolveSudoku(char[][] board)
        {
            Solve(board);
        }

        private bool Solve(char[][] board)
        {
            for (var row = 0; row < BoardSize; row++)
            {
                for (var column = 0; column < BoardSize; column++)
                {
                    if (board[row][column] != '.')
                    {
                        continue;
                    }

                    for (var number = 1; number < 10; number++)
                    {
                        var charNum = number.ToString()[0];
                        if (IsValid(board, row, column, charNum))
                        {
                            board[row][column] = charNum;
                            if (!Solve(board))
                            {
                                board[row][column] = '.';
                            }
                            else
                            {
                                return true;
                            }
                        }
                    }
                    return false;
                }
            }
            return true;
        }

        private bool IsValid(char[][] board, int row, int column, char number)
        {
            for (var i = 0; i < BoardSize; i++)
            {
                if (board[row][i] == number)
                {
                    return false;
                }
            }

            for (var i = 0; i < BoardSize; i++)
            {
                if (board[i][column] == number)
                {
                    return false;
                }
            }

            var squareRow = row / 3 * 3;
            var squareColumn = column / 3 * 3;

            for (var sRow = squareRow; sRow < squareRow + 3; sRow++)
            {
                for (var sCol = squareColumn; sCol < squareColumn + 3; sCol++)
                {
                    if (board[sRow][sCol] == number)
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var board1 = new char[][]
            {
                new char[] {'5','3','.','.','7','.','.','.','.'},
                new char[] {'6','.','.','1','9','5','.','.','.'},
                new char[] {'.','9','8','.','.','.','.','6','.'},
                new char[] {'8','.','.','.','6','.','.','.','3'},
                new char[] {'4','.','.','8','.','3','.','.','1'},
                new char[] {'7','.','.','.','2','.','.','.','6'},
                new char[] {'.','6','.','.','.','.','2','8','.'},
                new char[] {'.','.','.','4','1','9','.','.','5'},
                new char[] {'.','.','.','.','8','.','.','7','9'}
            };

            solution.SolveSudoku(board1);

            Console.ReadKey();
        }
    }
}
