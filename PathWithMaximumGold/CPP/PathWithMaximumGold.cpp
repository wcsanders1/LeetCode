// https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution
{
public:
  int getMaximumGold(vector<vector<int>> &grid)
  {
    int answer = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[0].size(); col++)
      {
        answer = max(answer, getMax(grid, visited, row, col));
      }
    }

    return answer;
  }

private:
  int getMax(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col)
  {
    int m = 0;
    visited[row][col] = true;
    for (auto &d : directions)
    {
      int nextRow = row + d[0];
      int nextCol = col + d[1];
      if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size() && !visited[nextRow][nextCol] && grid[nextRow][nextCol] != 0)
      {
        m = max(m, getMax(grid, visited, nextRow, nextCol));
      }
    }
    visited[row][col] = false;

    return grid[row][col] + m;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.getMaximumGold(*new vector<vector<int>>{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}});
  int result2 = solution.getMaximumGold(*new vector<vector<int>>{{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}});
  int result3 = solution.getMaximumGold(*new vector<vector<int>>{{5, 3, 36, 26, 27}, {11, 31, 23, 30, 4}, {5, 7, 21, 38, 10}, {39, 30, 10, 17, 13}, {16, 0, 0, 26, 1}, {25, 0, 10, 0, 0}});
}