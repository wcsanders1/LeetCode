// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// not mine: https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/312814/simple-BFS-C%2B%2B
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    if (grid.size() == 0 || grid[0].size() == 0)
    {
      return -1;
    }

    if (grid[0][0] != 0 || grid[grid.size() - 1][grid[0].size() - 1] != 0)
    {
      return -1;
    }

    return bfs(grid);
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

  int bfs(vector<vector<int>> &grid)
  {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    grid[0][0] = 1;

    while (!q.empty())
    {
      auto current = q.front();
      q.pop();
      int x = current.first;
      int y = current.second;

      if (x == grid.size() - 1 && y == grid[0].size() - 1)
      {
        return grid[x][y];
      }

      for (auto direction : directions)
      {
        int newX = x + direction[0];
        int newY = y + direction[1];

        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 0)
        {
          q.push(make_pair(newX, newY));
          grid[newX][newY] = grid[x][y] + 1;
        }
      }
    }

    return -1;
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

  int result4 = solution.shortestPathBinaryMatrix(*new vector<vector<int>>{vector<int>{0, 0, 1, 1, 0, 0},
                                                                           vector<int>{0, 0, 0, 0, 1, 1},
                                                                           vector<int>{1, 0, 1, 1, 0, 0},
                                                                           vector<int>{0, 0, 1, 1, 0, 0},
                                                                           vector<int>{1, 0, 0, 0, 0, 0},
                                                                           vector<int>{1, 0, 1, 0, 0, 0}}); // 8

  int result5 = solution.shortestPathBinaryMatrix(*new vector<vector<int>>{vector<int>{0, 0, 0, 1},
                                                                           vector<int>{0, 0, 1, 0},
                                                                           vector<int>{0, 1, 0, 0},
                                                                           vector<int>{1, 0, 0, 0}}); // 4
}