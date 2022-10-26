// https://leetcode.com/problems/greatest-sum-divisible-by-three/
#include <vector>

using namespace std;

class Solution
{
public:
  int maxSumDivThree(vector<int> &nums)
  {
    vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1, vector<int>(3, 0));
    for (int i = 1; i <= nums.size(); i++)
    {
      int n = nums[i - 1];
      vector<int> prev = dp[i - 1];
      for (int j = 0; j < prev.size(); j++)
      {
        int p = prev[j];
        int sum = n + p;
        int mod = sum % 3;
        dp[i][mod] = max(dp[i][mod], sum);
        dp[i][j] = max(p, dp[i][j]);
      }
    }

    return dp[nums.size()][0];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSumDivThree(*new vector<int>{3, 6, 5, 1, 8});
  int result2 = solution.maxSumDivThree(*new vector<int>{4});
  int result3 = solution.maxSumDivThree(*new vector<int>{1, 2, 3, 4, 4});
}