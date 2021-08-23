#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    int max = amount + 1;
    vector<int> dp(max, max);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
      for (int j = 0; j < coins.size(); j++)
      {
        if (coins[j] <= i)
        {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.coinChange(*new vector<int>{1, 2, 5}, 11);
  int result2 = solution.coinChange(*new vector<int>{2, 5}, 11);
  int result3 = solution.coinChange(*new vector<int>{1}, 0);
  int result4 = solution.coinChange(*new vector<int>{1}, 1);
  int result5 = solution.coinChange(*new vector<int>{2147483647}, 2);
  int result6 = solution.coinChange(*new vector<int>{2}, 3);
}