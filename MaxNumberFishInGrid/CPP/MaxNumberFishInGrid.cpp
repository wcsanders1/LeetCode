// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int findMaxFish(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();

    int answer = 0;
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        answer = max(answer, getMax(grid, row, col, visited));
      }
    }

    return answer;
  }

private:
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int getMax(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited)
  {
    if (row >= grid.size() || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0)
    {
      return 0;
    }

    visited[row][col] = true;

    int answer = grid[row][col];
    for (auto dir : directions)
    {
      answer += getMax(grid, row + dir[0], col + dir[1], visited);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findMaxFish(*new vector<vector<int>>{{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}});
  int result2 = solution.findMaxFish(*new vector<vector<int>>{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}});
  int result3 = solution.findMaxFish(*new vector<vector<int>>{{10, 5}, {0, 8}});
  int result4 = solution.findMaxFish(*new vector<vector<int>>{{4, 5, 5}, {0, 10, 0}});
}