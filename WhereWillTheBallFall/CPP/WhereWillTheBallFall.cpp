#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> findBall(vector<vector<int>> &grid)
  {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    vector<int> answer(grid[0].size(), 0);

    for (int column = 0; column < grid[0].size(); column++)
    {
      answer[column] = findPath(grid, dp, column);
    }

    return answer;
  }

private:
  int findPath(vector<vector<int>> &grid, vector<vector<int>> &dp, int column, int row = 0)
  {
    if (dp[row][column] != 0)
    {
      return dp[row][column];
    }

    if (isBlocked(grid, column, row))
    {
      dp[row][column] = -1;

      return -1;
    }

    if (row >= grid.size() - 1)
    {
      return column + grid[row][column];
    }

    dp[row][column] = findPath(grid, dp, column + grid[row][column], row + 1);

    return dp[row][column];
  }

  bool isBlocked(vector<vector<int>> &grid, int column, int row)
  {
    int nextColumn = column + grid[row][column];
    if (nextColumn < 0 || nextColumn >= grid[row].size() || grid[row][nextColumn] != grid[row][column])
    {
      return true;
    }

    return false;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.findBall(*new vector<vector<int>>{vector<int>{1, 1, 1, -1, -1}, vector<int>{1, 1, 1, -1, -1}, vector<int>{-1, -1, -1, 1, 1}, vector<int>{1, 1, 1, 1, -1}, vector<int>{-1, -1, -1, -1, -1}});
  vector<int> result2 = solution.findBall(*new vector<vector<int>>{vector<int>{-1}});
  vector<int> result3 = solution.findBall(*new vector<vector<int>>{vector<int>{1, 1, 1, 1, 1, 1}, vector<int>{-1, -1, -1, -1, -1, -1}, vector<int>{1, 1, 1, 1, 1, 1}, vector<int>{-1, -1, -1, -1, -1, -1}});
}