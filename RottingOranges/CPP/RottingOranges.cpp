// https://leetcode.com/problems/rotting-oranges/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    queue<vector<int>> q;
    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[0].size(); col++)
      {
        if (grid[row][col] == 2)
        {
          q.push({row, col});
        }
      }
    }

    int seconds = 0;
    while (!q.empty())
    {
      int count = q.size();
      while (count-- > 0)
      {
        auto cur = q.front();
        q.pop();
        for (auto &dir : directions)
        {
          int nrow = cur[0] + dir[0];
          int ncol = cur[1] + dir[1];
          if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1)
          {
            grid[nrow][ncol] = 2;
            q.push({nrow, ncol});
          }
        }
      }

      if (!q.empty())
      {
        seconds++;
      }
    }

    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[0].size(); col++)
      {
        if (grid[row][col] == 1)
        {
          return -1;
        }
      }
    }

    return seconds;
  }

private:
  vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};

int main()
{
  Solution solution;

  int result1 = solution.orangesRotting(*new vector<vector<int>>{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}); // 4
  int result2 = solution.orangesRotting(*new vector<vector<int>>{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}); //-1
  int result3 = solution.orangesRotting(*new vector<vector<int>>{{0, 2}});                          // 0
  int result4 = solution.orangesRotting(*new vector<vector<int>>{{2, 1, 1}, {1, 1, 1}, {0, 1, 2}}); // 2
  int result5 = solution.orangesRotting(*new vector<vector<int>>{{0}});                             // 0
}