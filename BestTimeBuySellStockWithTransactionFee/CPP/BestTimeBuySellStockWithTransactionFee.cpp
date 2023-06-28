// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// NOT MINE: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    int s0 = 0, s1 = INT_MIN;
    for (int p : prices)
    {
      int tmp = s0;
      s0 = max(s0, s1 + p);
      s1 = max(s1, tmp - p - fee);
    }
    return s0;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxProfit(*new vector<int>{1, 3, 2, 8, 4, 9}, 2);
  int result2 = solution.maxProfit(*new vector<int>{1, 3, 7, 5, 10, 3}, 3);
}