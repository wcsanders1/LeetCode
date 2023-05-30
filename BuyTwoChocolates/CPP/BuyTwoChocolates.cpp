// https://leetcode.com/problems/buy-two-chocolates/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int buyChoco(vector<int> &prices, int money)
  {
    sort(prices.begin(), prices.end());
    int left = money - (prices[0] + prices[1]);
    return left >= 0 ? left : money;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.buyChoco(*new vector<int>{1, 2, 2}, 3);
  int result2 = solution.buyChoco(*new vector<int>{3, 2, 3}, 3);
}