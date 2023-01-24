// https://leetcode.com/problems/snakes-and-ladders/description/
#include <vector>

using namespace std;

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    vector<int> longBoard;
    bool right = true;
    for (int row = board.size() - 1; row >= 0; row--)
    {
      if (right)
      {
        for (int col = 0; col <= board[row].size() - 1; col++)
        {
          longBoard.push_back(board[row][col]);
        }
      }
      else
      {
        for (int col = board[row].size() - 1; col >= 0; col--)
        {
          longBoard.push_back(board[row][col]);
        }
      }
      right = !right;
    }
  }
};