// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minCost(int n, vector<int> &cuts)
  {
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));

    for (int j = 2; j < n; j++)
    {
      for (int i = j - 2; i >= 0; i--)
      {
        int m = INT32_MAX;
        for (int cut : cuts)
        {
          if (cut >= j - 1 || cut <= i)
          {
            break;
          }

          m = min(m, dp[i][cut + 1] + dp[cut + 1][j]);
        }

        if (m < INT32_MAX)
        {
          dp[i][j] = m + j - i;
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost(7, *new vector<int>{1, 3, 4, 5});
}