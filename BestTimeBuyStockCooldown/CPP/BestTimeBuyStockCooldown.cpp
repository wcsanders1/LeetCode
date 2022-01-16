#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    vector<int> rest(prices.size(), 0);
    vector<int> sell(prices.size(), 0);
    vector<int> buy(prices.size(), 0);

    buy[0] = -prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
      buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
      rest[i] = max(buy[i - 1], max(rest[i - 1], sell[i - 1]));
    }

    return max(rest[prices.size() - 1], sell[prices.size() - 1]);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxProfit(*new vector<int>{1, 2, 3, 0, 2});
  int result2 = solution.maxProfit(*new vector<int>{1});
  int result3 = solution.maxProfit(*new vector<int>{2, 1, 4});
}