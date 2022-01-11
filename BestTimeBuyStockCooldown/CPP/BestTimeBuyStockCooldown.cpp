#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    vector<LastAction> actions(prices.size(), Nothing);
    vector<int> dp(prices.size(), 0);

    for (int i = 1; i < prices.size(); i++)
    {
      if (prices[i] >= prices[i - 1])
      {
        int profit = prices[i] - prices[i - 1];
        if (actions[i - 1] == Cooldown)
        {
          int priorProfit = dp[i - 2] - dp[i - 3];
          if (profit > priorProfit)
          {
            dp[i - 2] = dp[i - 3];
            dp[i - 1] = dp[i - 2];
            dp[i] = profit + dp[i - 1];
            actions[i - 1] = Buy;
            actions[i] = Hold;
          }
        }
        else
        {
          dp[i] = profit + dp[i - 1];
          actions[i] = Hold;
        }
      }
      else
      {
        if (actions[i - 1] != Cooldown)
        {
          actions[i] = Cooldown;
        }
        dp[i] = dp[i - 1];
      }
    }

    return dp[prices.size() - 1];
  }

private:
  enum LastAction
  {
    Nothing,
    Buy,
    Sell,
    Cooldown,
    Hold
  };
};

int main()
{
  Solution solution;

  int result1 = solution.maxProfit(*new vector<int>{1, 2, 3, 0, 2});
  int result2 = solution.maxProfit(*new vector<int>{1});
  int result3 = solution.maxProfit(*new vector<int>{2, 1, 4});
}