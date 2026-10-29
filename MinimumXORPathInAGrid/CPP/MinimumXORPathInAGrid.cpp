// https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/?envType=daily-question&envId=2026-10-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minCost(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<unordered_set<int>>> dp(rows, vector<unordered_set<int>>(cols));
    dp[0][0].insert(grid[0][0]);
    vector<vector<int>> directions{{1, 0}, {0, 1}};
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        for (auto &d : directions)
        {
          int nr = row + d[0];
          int nc = col + d[1];
          if (nr >= rows || nc >= cols)
          {
            continue;
          }

          for (int p : dp[row][col])
          {
            dp[nr][nc].insert(p ^ grid[nr][nc]);
          }
        }
      }
    }

    int answer = INT32_MAX;
    for (int p : dp[rows - 1][cols - 1])
    {
      answer = min(answer, p);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost(*new vector<vector<int>>{{1, 2}, {3, 4}});
  int result2 = solution.minCost(*new vector<vector<int>>{{6, 7}, {5, 8}});
  int result3 = solution.minCost(*new vector<vector<int>>{{2, 7, 5}});
  int result4 = solution.minCost(*new vector<vector<int>>{{11, 10, 4}, {19, 9, 13}}); // 5
}