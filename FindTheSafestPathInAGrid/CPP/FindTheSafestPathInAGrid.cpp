// https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01
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
  int maximumSafenessFactor(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> safenesses(rows, vector<int>(cols, INT32_MAX));
    queue<vector<int>> thieves;
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        if (grid[row][col] == 1)
        {
          thieves.push({row, col});
          safenesses[row][col] = 0;
        }
      }
    }

    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!thieves.empty())
    {
      int count = thieves.size();
      while (count-- > 0)
      {
        auto t = thieves.front();
        thieves.pop();
        for (auto &d : directions)
        {
          int nrow = t[0] + d[0];
          int ncol = t[1] + d[1];
          if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols)
          {
            continue;
          }
          int dist = (abs(nrow - t[0]) + abs(ncol - t[1])) + safenesses[t[0]][t[1]];
          if (dist < safenesses[nrow][ncol])
          {
            safenesses[nrow][ncol] = dist;
            thieves.push({nrow, ncol});
          }
        }
      }
    }

    vector<vector<int>> bests(rows, vector<int>(cols, -1));
    bests[0][0] = safenesses[0][0];
    queue<vector<int>> cords;
    cords.push({0, 0});
    while (!cords.empty())
    {
      int count = cords.size();
      while (count-- > 0)
      {
        auto cord = cords.front();
        cords.pop();
        int row = cord[0];
        int col = cord[1];
        int safeness = bests[row][col];
        for (auto &d : directions)
        {
          int nextRow = row + d[0];
          int nextCol = col + d[1];
          if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && bests[nextRow][nextCol] < min(safeness, safenesses[nextRow][nextCol]))
          {
            bests[nextRow][nextCol] = min(safeness, safenesses[nextRow][nextCol]);
            cords.push({nextRow, nextCol});
          }
        }
      }
    }

    return bests[rows - 1][cols - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximumSafenessFactor(*new vector<vector<int>>{{1, 0, 0}, {0, 0, 0}, {0, 0, 1}});                        // 0
  int result2 = solution.maximumSafenessFactor(*new vector<vector<int>>{{0, 0, 1}, {0, 0, 0}, {0, 0, 0}});                        // 2
  int result3 = solution.maximumSafenessFactor(*new vector<vector<int>>{{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}}); // 2
  int result4 = solution.maximumSafenessFactor(*new vector<vector<int>>{{1, 1, 1}, {1, 1, 1}, {0, 0, 1}});                        // 0
  int result5 = solution.maximumSafenessFactor(*new vector<vector<int>>{{0, 0, 1}, {0, 1, 1}, {0, 0, 0}});                        // 1
  int result6 = solution.maximumSafenessFactor(*new vector<vector<int>>{{1, 1, 1}, {1, 1, 1}, {1, 0, 0}});                        // 0
}