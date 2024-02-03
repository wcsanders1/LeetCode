// https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k)
  {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      int cur = arr[i - 1];
      for (int j = 1; j <= k && ((i - j) >= 0); j++)
      {
        cur = max(cur, arr[i - j]);
        dp[i] = max(dp[i], dp[i - j] + (cur * j));
      }
    }

    return dp[n];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSumAfterPartitioning(*new vector<int>{1, 15, 7, 9, 2, 5, 10}, 3);
  int result2 = solution.maxSumAfterPartitioning(*new vector<int>{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3}, 4);
  int result3 = solution.maxSumAfterPartitioning(*new vector<int>{1}, 1);
}