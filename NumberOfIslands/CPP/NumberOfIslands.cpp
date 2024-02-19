// https://leetcode.com/problems/number-of-islands/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int islands = 0;
    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[row].size(); col++)
      {
        if (grid[row][col] == '1')
        {
          islands++;
          visit(grid, row, col);
        }
      }
    }

    return islands;
  }

private:
  void visit(vector<vector<char>> &grid, int row, int col)
  {
    if (grid[row][col] == '1')
    {
      grid[row][col] = '0';
    }
    else
    {
      return;
    }

    if (row < grid.size() - 1)
    {
      visit(grid, row + 1, col);
    }

    if (row > 0)
    {
      visit(grid, row - 1, col);
    }

    if (col < grid[row].size() - 1)
    {
      visit(grid, row, col + 1);
    }

    if (col > 0)
    {
      visit(grid, row, col - 1);
    }
  }
};