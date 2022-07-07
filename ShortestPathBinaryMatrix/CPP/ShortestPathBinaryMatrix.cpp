// https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include <vector>

using namespace std;

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    int result = dfs(0, 0, grid, visited);
    return result == INT32_MAX ? -1 : result;
  }

private:
  vector<vector<int>> directions{
      vector<int>{0, 1},
      vector<int>{0, -1},
      vector<int>{1, 0},
      vector<int>{-1, 0},
      vector<int>{1, 1},
      vector<int>{-1, 1},
      vector<int>{1, -1},
      vector<int>{-1, -1}};

  int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited)
  {
    if (x == grid.size() - 1 && y == grid[0].size() - 1)
    {
      return grid[x][y] == 1 ? INT32_MAX : 1;
    }

    visited[x][y] = true;

    if (grid[x][y] == 1)
    {
      return INT32_MAX;
    }

    int path = INT32_MAX;

    for (vector<int> direction : directions)
    {
      int newX = x + direction[0];
      int newY = y + direction[1];

      if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size())
      {
        continue;
      }

      if (visited[newX][newY])
      {
        continue;
      }

      path = min(path, dfs(newX, newY, grid, visited));
    }

    visited[x][y] = false;

    return path == INT32_MAX ? path : path + 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.shortestPathBinaryMatrix(*new vector<vector<int>>{vector<int>{0, 1},
                                                                           vector<int>{1, 0}});

  int result2 = solution.shortestPathBinaryMatrix(*new vector<vector<int>>{vector<int>{0, 0, 0},
                                                                           vector<int>{1, 1, 0},
                                                                           vector<int>{1, 1, 0}});

  int result3 = solution.shortestPathBinaryMatrix(*new vector<vector<int>>{vector<int>{1, 0, 0},
                                                                           vector<int>{1, 1, 0},
                                                                           vector<int>{1, 1, 0}});
}