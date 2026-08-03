// https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/?envType=daily-question&envId=2026-01-28
// NOT MINE: https://leetcode.com/problems/minimum-cost-path-with-teleportations/solutions/7531032/dijkstra-solution-no-dp-by-jatin-05-5y1f/?envType=daily-question&envId=2026-01-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minCost(vector<vector<int>> &grid, int k)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<tuple<int, int, int>> points;
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        points.push_back({grid[r][c], r, c});
      }
    }

    sort(points.begin(), points.end());
    vector<int> visitedfork(k + 1, 0);
    vector<vector<vector<int>>> dist(rows, vector<vector<int>>(cols, vector<int>(k + 1, INT32_MAX)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    pq.push({0, 0, 0, 0});

    while (!pq.empty())
    {
      auto [cost, currk, nrow, ncol] = pq.top();
      pq.pop();

      if (nrow == rows - 1 && ncol == cols - 1)
      {
        return cost;
      }

      if (isValid(nrow + 1, ncol, rows, cols))
      {
        int ncost = cost + grid[nrow + 1][ncol];
        if (ncost < dist[nrow + 1][ncol][currk])
        {
          dist[nrow + 1][ncol][currk] = ncost;
          pq.push({ncost, currk, nrow + 1, ncol});
        }
      }

      if (isValid(nrow, ncol + 1, rows, cols))
      {
        int ncost = cost + grid[nrow][ncol + 1];
        if (ncost < dist[nrow][ncol + 1][currk])
        {
          dist[nrow][ncol + 1][currk] = ncost;
          pq.push({ncost, currk, nrow, ncol + 1});
        }
      }

      if (currk < k)
      {
        int r = visitedfork[currk];
        for (; r < points.size(); r++)
        {
          auto [c, nr, nc] = points[r];
          if (c > grid[nrow][ncol])
          {
            break;
          }

          if (cost < dist[nr][nc][currk + 1])
          {
            dist[nr][nc][currk + 1] = cost;
            pq.push({cost, currk + 1, nr, nc});
          }
        }

        visitedfork[currk] = r;
      }
    }

    return -1;
  }

private:
  bool isValid(int row, int col, int rows, int cols)
  {
    return row < rows && col < cols;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost(*new vector<vector<int>>{{1, 3, 3}, {2, 5, 4}, {4, 3, 5}}, 2);
  int result2 = solution.minCost(*new vector<vector<int>>{{1, 2}, {2, 3}, {3, 4}}, 1);
}