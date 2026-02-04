// https://leetcode.com/problems/surrounded-regions/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  void solve(vector<vector<char>> &board)
  {
    int rows = board.size();
    int cols = board[0].size();
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        if (board[row][col] == 'O' && isSurrounded(board, visited, row, col))
        {
          fill(board, row, col);
        }
      }
    }
  }

private:
  bool isSurrounded(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col)
  {
    if (isOOB(board, row, col))
    {
      return false;
    }

    if (visited[row][col])
    {
      return true;
    }

    visited[row][col] = true;

    if (board[row][col] == 'X')
    {
      return true;
    }

    return isSurrounded(board, visited, row + 1, col) &&
           isSurrounded(board, visited, row - 1, col) &&
           isSurrounded(board, visited, row, col + 1) &&
           isSurrounded(board, visited, row, col - 1);
  }

  void fill(vector<vector<char>> &board, int row, int col)
  {
    if (isOOB(board, row, col) || board[row][col] == 'X')
    {
      return;
    }

    board[row][col] = 'X';
    fill(board, row + 1, col);
    fill(board, row - 1, col);
    fill(board, row, col + 1);
    fill(board, row, col - 1);
  }

  bool isOOB(vector<vector<char>> &board, int row, int col)
  {
    return row < 0 || col < 0 || row >= board.size() || col >= board[0].size();
  }
};

int main()
{
  Solution solution;

  vector<vector<char>> board1 = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
  solution.solve(board1);

  vector<vector<char>> board2 = {{'O', 'O'}, {'O', 'O'}};
  solution.solve(board2);

  vector<vector<char>> board3 = {
      {'O', 'O', 'O', 'O', 'X', 'X'},
      {'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'},
      {'O', 'X', 'O', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'},
      {'O', 'X', 'O', 'O', 'O', 'O'}};
  solution.solve(board3);
}