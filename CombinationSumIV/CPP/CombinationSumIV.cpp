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

    if (nums[nums.size() - 1] < target)
    {
      nums.push_back(target);
    }

    dp[nums[0]] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
      int num = nums[i];
      dp[num] = 1;

      vector<bool> visited(1001, false);

      for (int j = i - 1; j >= 0; j--)
      {
        int res = num % nums[j];
        int a = visited[nums[j]] ? 0 : dp[nums[j]];
        int b = visited[res] ? 0 : dp[res];

        dp[num] += a + b;

        visited[nums[j]] = true;
        visited[res] = true;
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