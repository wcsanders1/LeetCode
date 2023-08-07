// https://leetcode.com/problems/account-balance-after-rounded-purchase/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int accountBalanceAfterPurchase(int purchaseAmount)
  {
    int first = purchaseAmount % 10;
    if (first < 5)
    {
      return 100 - (purchaseAmount - first);
    }

    return 100 - (purchaseAmount + (10 - first));
  }
};

int main()
{
  Solution solution;

  int result1 = solution.accountBalanceAfterPurchase(9);  // 90
  int result2 = solution.accountBalanceAfterPurchase(15); // 80
  int result3 = solution.accountBalanceAfterPurchase(13); // 90
  int result4 = solution.accountBalanceAfterPurchase(0);  // 100
  int result5 = solution.accountBalanceAfterPurchase(99); // 0
}