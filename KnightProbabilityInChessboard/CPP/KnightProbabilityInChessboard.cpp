// https://leetcode.com/problems/knight-probability-in-chessboard/description/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  double knightProbability(int n, int k, int row, int column)
  {
    if (k == 0)
    {
      return 1;
    }

    vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
    for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < n; c++)
      {
        dp[0][r][c] = 1;
      }
    }

    for (int m = 1; m <= k; m++)
    {
      for (int r = 0; r < n; r++)
      {
        for (int c = 0; c < n; c++)
        {
          for (auto &d : directions)
          {
            int nR = r + d[0];
            int nC = c + d[1];
            if (isOnBoard(nR, nC, n))
            {
              dp[m][r][c] += dp[m - 1][nR][nC];
            }
          }
        }
      }
    }

    return dp[k][row][column] / pow(8.0, k);
  }

private:
  vector<vector<int>> directions =
      {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

  bool isOnBoard(int row, int column, int n)
  {
    return row >= 0 && column >= 0 && row < n && column < n;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.knightProbability(3, 2, 0, 0);
  auto result2 = solution.knightProbability(1, 0, 0, 0);
  auto result3 = solution.knightProbability(8, 30, 6, 4);
  auto result4 = solution.knightProbability(3, 3, 0, 0); // .01562
}