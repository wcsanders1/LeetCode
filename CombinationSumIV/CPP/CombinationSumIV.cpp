// https://leetcode.com/problems/combination-sum-iv/description/
// NOT MINE: https://leetcode.com/problems/combination-sum-iv/solutions/85036/1ms-java-dp-solution-with-detailed-explanation/?orderBy=most_votes
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1, -1);
    dp[0] = 1;
    return getCombinations(nums, target, dp);
  }

private:
  int getCombinations(vector<int> &nums, int target, vector<int> &dp)
  {
    if (dp[target] != -1)
    {
      return dp[target];
    }

    int answer = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (target >= nums[i])
      {
        answer += getCombinations(nums, target - nums[i], dp);
      }
    }

    dp[target] = answer;
    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.combinationSum4(*new vector<int>{1, 2, 3}, 4);                                                                              // 7
  int result2 = solution.combinationSum4(*new vector<int>{9}, 3);                                                                                    // 0
  int result3 = solution.combinationSum4(*new vector<int>{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, 10); // 9
}