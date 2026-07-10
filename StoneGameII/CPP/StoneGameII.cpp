// https://leetcode.com/problems/stone-game-ii/?envType=daily-question&envId=2024-08-20
// NOT MINE: https://leetcode.com/problems/stone-game-ii/solutions/345247/c-dp-tabulation-by-sure4love-o5rx/?envType=daily-question&envId=2024-08-20
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int stoneGameII(vector<int> &piles)
  {
    int n = piles.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> suffixSum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      suffixSum[i] = piles[i] + suffixSum[i + 1];
    }

    for (int i = 0; i <= n; i++)
    {
      dp[i][n] = suffixSum[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 1; j--)
      {
        for (int X = 1; X <= 2 * j && i + X <= n; X++)
        {
          dp[i][j] = max(dp[i][j], suffixSum[i] - dp[i + X][max(j, X)]);
        }
      }
    }

    return dp[0][1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.stoneGameII(*new vector<int>{2, 7, 9, 4, 4});
}