// https://leetcode.com/problems/score-after-flipping-matrix/
#include <vector>

using namespace std;

class Solution
{
public:
  int matrixScore(vector<vector<int>> &grid)
  {
    for (int row = 0; row < grid.size(); row++)
    {
      if (grid[row][0] == 0)
      {
        for (int col = 0; col < grid[row].size(); col++)
        {
          grid[row][col] = grid[row][col] == 0 ? 1 : 0;
        }
      }
    }

    for (int col = 1; col < grid[0].size(); col++)
    {
      int ones = 0;
      for (int row = 0; row < grid.size(); row++)
      {
        ones += grid[row][col];
      }

      if (ones <= grid.size() / 2)
      {
        for (int row = 0; row < grid.size(); row++)
        {
          grid[row][col] = grid[row][col] == 0 ? 1 : 0;
        }
      }
    }

    int answer = 0;
    for (int row = 0; row < grid.size(); row++)
    {
      int t = 0;
      for (int col = 0; col < grid[0].size(); col++)
      {
        if (col > 0)
        {
          t <<= 1;
        }
        t += grid[row][col];
      }
      answer += t;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.matrixScore(*new vector<vector<int>>{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}});
  int result2 = solution.matrixScore(*new vector<vector<int>>{{0}});
}