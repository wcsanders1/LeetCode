using System;
using System.Collections.Generic;

namespace ValidSudoku
{
    public class Solution
    {
        public bool IsValidSudoku(char[][] board)
        {
            const int boardSize = 9;

            var columns = new HashSet<int>[boardSize];
            var rows = new HashSet<int>[boardSize];
            var squares = new HashSet<int>[boardSize];

            for (var row = 0; row < boardSize; row++)
            {
                rows[row] = new HashSet<int>();

                for (var column = 0; column < boardSize; column++)
                {
                    var space = board[row][column];
                    if (space == '.')
                    {
                        continue;
                    }

                    var square = (row / 3 * 3) + column / 3;

                    if (columns[column] == null)
                    {
                        columns[column] = new HashSet<int>();
                    }

                    if (squares[square] == null)
                    {
                        squares[square] = new HashSet<int>();
                    }

                    if (columns[column].Contains(space) ||
                        rows[row].Contains(space) ||
                        squares[square].Contains(space))
                    {
                        return false;
                    }

                    columns[column].Add(space);
                    rows[row].Add(space);
                    squares[square].Add(space);
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
                new char[] {'8','3','.','.','7','.','.','.','.'},
                new char[] {'6','.','.','1','9','5','.','.','.'},
                new char[] {'.','9','8','.','.','.','.','6','.'},
                new char[] {'8','.','.','.','6','.','.','.','3'},
                new char[] {'4','.','.','8','.','3','.','.','1'},
                new char[] {'7','.','.','.','2','.','.','.','6'},
                new char[] {'.','6','.','.','.','.','2','8','.'},
                new char[] {'.','.','.','4','1','9','.','.','5'},
                new char[] {'.','.','.','.','8','.','.','7','9'}
            };

            Console.WriteLine(solution.IsValidSudoku(board1));

            Console.ReadKey();
        }
    }
}
