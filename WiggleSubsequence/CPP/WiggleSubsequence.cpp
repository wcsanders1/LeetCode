// https://leetcode.com/problems/wiggle-subsequence/description/
#include <vector>

using namespace std;

enum Diff
{
  Equal = 0,
  Lesser = 1,
  Greater = 2,
};

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    int answer = 0;
    vector<vector<int>> dp(nums.size(), vector<int>(3, 0));
    for (int i = 0; i < nums.size(); i++)
    {
      dp[i][0] = nums[i];
      for (int j = 0; j < i; j++)
      {
        Diff lastDiff = (Diff)dp[j][1];
        Diff curDiff = getDiff(nums[i], dp[j][0]);
        dp[j][0] = nums[i];

        if (curDiff != Equal && lastDiff != curDiff)
        {
          dp[j][1] = curDiff;
          answer = max(answer, ++dp[j][2]);
        }
      }
    }

    return answer + 1;
  }

private:
  Diff getDiff(int num1, int num2)
  {
    int d = num1 - num2;
    if (d == 0)
    {
      return Equal;
    }

    if (d < 0)
    {
      return Greater;
    }

    return Lesser;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.wiggleMaxLength(*new vector<int>{1, 7, 4, 9, 2, 5});
  int result2 = solution.wiggleMaxLength(*new vector<int>{1, 17, 5, 10, 13, 15, 10, 5, 16, 8});
  int result3 = solution.wiggleMaxLength(*new vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
  int result4 = solution.wiggleMaxLength(*new vector<int>{1});
}