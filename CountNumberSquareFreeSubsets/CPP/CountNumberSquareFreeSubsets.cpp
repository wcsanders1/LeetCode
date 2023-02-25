// https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
// NOT MINE: https://leetcode.com/problems/count-the-number-of-square-free-subsets/solutions/3203755/o-n-1024-memoization-bitmask/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
  int squareFreeSubsets(vector<int> &nums)
  {
    vector<vector<int>> dp(1001, vector<int>(1024, -1));
    return 1LL * (getAnswer(dp, nums, 0, 0) - 1 + mod) % mod;
  }

private:
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  long long mod = 1e9 + 7;
  long long getAnswer(vector<vector<int>> &dp, vector<int> &nums, int i, int mask)
  {
    if (i == nums.size())
    {
      return 1;
    }

    if (dp[i][mask] != -1)
    {
      return dp[i][mask];
    }

    int temp = mask;
    int flag = 1;

    for (int j = 0; j < primes.size(); j++)
    {
      int num = nums[i];
      int count = 0;
      while (num % primes[j] == 0)
      {
        num /= primes[j];
        count++;
      }

      if (count >= 2 || ((count == 1) && ((mask >> j) & 1) == 1))
      {
        flag = 0;
        break;
      }

      if (count > 0)
      {
        temp = temp | (1 << j);
      }
    }

    if (flag > 0)
    {
      return dp[i][mask] = (getAnswer(dp, nums, i + 1, mask) + getAnswer(dp, nums, i + 1, temp)) % mod;
    }
    else
    {
      return dp[i][mask] = getAnswer(dp, nums, i + 1, mask);
    }
  }
};

int main()
{
  Solution solution;

  int result1 = solution.squareFreeSubsets(*new vector<int>{3, 4, 4, 5});
  int result2 = solution.squareFreeSubsets(*new vector<int>{1});
}