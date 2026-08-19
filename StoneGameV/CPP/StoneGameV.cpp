// https://leetcode.com/problems/stone-game-v/description/?envType=daily-question&envId=2026-08-17
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
  int stoneGameV(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    vector<int> sums;
    sums.push_back(stoneValue[0]);
    for (int i = 1; i < n; i++)
    {
      sums.push_back(stoneValue[i] + sums[i - 1]);
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int start = n - 1; start >= 0; start--)
    {
      for (int end = start + 1; end < n; end++)
      {
        for (int i = start; i < end; i++)
        {
          int leftSum = stoneValue[start] + sums[i] - sums[start];
          int rightSum = sums[end] - sums[i];
          int total = 0;
          if (leftSum > rightSum)
          {
            total = rightSum + dp[i + 1][end];
          }
          else if (leftSum < rightSum)
          {
            total = leftSum + dp[start][i];
          }
          else
          {
            total = max(rightSum + dp[i + 1][end], leftSum + dp[start][i]);
          }
          dp[start][end] = max(dp[start][end], total);
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.stoneGameV(*new vector<int>{6, 2, 3, 4, 5, 5});
  int result2 = solution.stoneGameV(*new vector<int>{7, 7, 7, 7, 7, 7, 7});
  int result3 = solution.stoneGameV(*new vector<int>{4});
}