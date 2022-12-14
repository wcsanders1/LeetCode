//  https://leetcode.com/problems/combination-sum-iv/description/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    vector<int> dp(1001, 0);

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];
      dp[num] = 1;

      for (int j = i - 1; j >= 0; j--)
      {
        int div = num / nums[j];
        int res = num % nums[j];
        dp[num] += dp[div] + dp[res];
      }
    }

    if (target > nums[nums.size() - 1])
    {
      for (int j = nums.size() - 1; j >= 0; j--)
      {
        int div = target / nums[j];
        int res = target % nums[j];
        dp[target] += dp[div] + dp[res];
      }
    }

    return dp[target];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.combinationSum4(*new vector<int>{1, 2, 3}, 4);
  int result2 = solution.combinationSum4(*new vector<int>{9}, 3);
}