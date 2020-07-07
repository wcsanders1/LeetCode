using System;
using System.Linq;

namespace WordSearch
{
    public class Solution
    {
        public bool Exist(char[][] board, string word)
        {
            for (int column = 0; column < board.Length; column++)
            {
                for (int row = 0; row < board[column].Length; row++)
                {
                    var visited = new bool[board.Length][];
                    for (int i = 0; i < board.Length; i++)
                    {
                        visited[i] = new bool[board[i].Length];
                    }

                    if (Exist(board, word, visited, row, column))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        private bool Exist(char[][] board, string word, bool[][] visited, int row, int column, int currentChar = 0)
        {
            if (currentChar >= word.Length)
            {
                return true;
            }

            if (column < 0 ||
                row < 0 ||
                column >= board.Length || 
                row >= board[column].Length ||
                visited[column][row])
            {
                return false;
            }

            visited[column][row] = true;

            if (board[column][row] != word[currentChar])
            {
                return false;
            }

            currentChar++;

            return Exist(board, word, visited.Select(a => a.ToArray()).ToArray(), row + 1, column, currentChar) || 
                Exist(board, word, visited.Select(a => a.ToArray()).ToArray(), row - 1, column, currentChar) ||
                Exist(board, word, visited.Select(a => a.ToArray()).ToArray(), row, column + 1, currentChar) ||
                Exist(board, word, visited.Select(a => a.ToArray()).ToArray(), row, column - 1, currentChar);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var board = new char[][]
            {
                new char[] {'A', 'B', 'C', 'E'},
                new char[] {'S', 'F', 'C', 'S'},
                new char[] {'A', 'D', 'E', 'E'},
            };

            var boardTwo = new char[][]
            {
                new char[] {'a', 'b'},
                new char[] {'c', 'd'}
            };

            var solution = new Solution();

            Console.WriteLine(solution.Exist(board, "ABCCED"));
            Console.WriteLine(solution.Exist(board, "SEE"));
            Console.WriteLine(solution.Exist(board, "ABCB"));
            Console.WriteLine(solution.Exist(boardTwo, "acdb"));

            Console.ReadKey();
        }
    }
}
