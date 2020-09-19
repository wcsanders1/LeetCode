using System;

namespace GameOfLife
{
    public class Solution
    {
        public void GameOfLife(int[][] board)
        {
            for (int row = 0; row < board.Length; row++)
            {
                for (int column = 0; column < board[row].Length; column++)
                {
                    var willLive = WillLive(board, row, column);
                    var number = board[row][column];

                    if (willLive && number == 0)
                    {
                        board[row][column] = 3;
                    }

                    if (!willLive && number == 1)
                    {
                        board[row][column] = 2;
                    }
                }
            }

            RenderNewBoard(board);
        }

        private void RenderNewBoard(int[][] board)
        {
            for (int row = 0; row < board.Length; row++)
            {
                for (int column = 0; column < board[row].Length; column++)
                {
                    if (board[row][column] == 2)
                    {
                        board[row][column] = 0;
                    }

                    if (board[row][column] == 3)
                    {
                        board[row][column] = 1;
                    }
                }
            }
        }

        private static bool WillLive(int[][] board, int row, int column)
        {
            var piece = board[row][column];
            var pieceIsLive = piece == 1 || piece == 2;
            var liveNeighbors = 0;

            if (row != 0)
            {
                liveNeighbors = (board[row - 1][column] == 1 || board[row - 1][column] == 2) ? liveNeighbors + 1 : liveNeighbors;

                if (column != 0)
                {
                    liveNeighbors = (board[row - 1][column - 1] == 1 || board[row - 1][column - 1] == 2) ? liveNeighbors + 1 : liveNeighbors;
                }

                if (column < board[row].Length - 1)
                {
                    liveNeighbors = (board[row - 1][column + 1] == 1 || board[row - 1][column + 1] == 2) ? liveNeighbors + 1 : liveNeighbors;
                }
            }

            if (column != 0)
            {
                liveNeighbors = (board[row][column - 1] == 1 || board[row][column - 1] == 2) ? liveNeighbors + 1 : liveNeighbors;
            }

            if (column < board[row].Length - 1)
            {
                liveNeighbors = (board[row][column + 1] == 1 || board[row][column + 1] == 2) ? liveNeighbors + 1 : liveNeighbors;
            }

            if (row < board.Length - 1)
            {
                liveNeighbors = (board[row + 1][column] == 1 || board[row + 1][column] == 2) ? liveNeighbors + 1 : liveNeighbors;

                if (column != 0)
                {
                    liveNeighbors = (board[row + 1][column - 1] == 1 || board[row + 1][column - 1] == 2) ? liveNeighbors + 1 : liveNeighbors;
                }

                if (column < board[row].Length - 1)
                {
                    liveNeighbors = (board[row + 1][column + 1] == 1 || board[row + 1][column + 1] == 2) ? liveNeighbors + 1 : liveNeighbors;
                }
            }

            if (pieceIsLive && (liveNeighbors < 2 || liveNeighbors > 3))
            {
                return false;
            }

            if (pieceIsLive && (liveNeighbors == 2 || liveNeighbors == 3))
            {
                return true;
            }

            if (!pieceIsLive && liveNeighbors == 3)
            {
                return true;
            }

            return pieceIsLive;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var boardOne = new int[][]
            {
                new int[]{0,1,0},
                new int[]{0,0,1},
                new int[]{1,1,1},
                new int[]{0,0,0},
            };

            solution.GameOfLife(boardOne);

            Console.ReadKey();
        }
    }
}
