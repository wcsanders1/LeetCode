// https://leetcode.com/problems/minimum-path-sum/description/
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[n - 1].size();
    for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < m; c++)
      {
        if (r == 0 && c == 0)
        {
          continue;
        }
        else if (r == 0)
        {
          grid[r][c] += grid[r][c - 1];
        }
        else if (c == 0)
        {
          grid[r][c] += grid[r - 1][c];
        }
        else
        {
          grid[r][c] += min(grid[r][c - 1], grid[r - 1][c]);
        }
      }
    }

    return grid[n - 1][m - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minPathSum(*new vector<vector<int>>{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
  int result2 = solution.minPathSum(*new vector<vector<int>>{{1, 2, 3}, {4, 5, 6}});
}