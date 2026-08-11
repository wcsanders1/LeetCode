// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int missingInteger(vector<int> &nums)
  {
    unordered_set<int> exist;
    exist.insert(nums[0]);
    int curLen = 1;
    int curSum = nums[0];
    bool seq = true;
    for (int i = 1; i < nums.size(); i++)
    {
      exist.insert(nums[i]);
      if ((nums[i - 1] + 1 == nums[i]) && seq)
      {
        curLen++;
        curSum += nums[i];
      }
      else
      {
        seq = false;
      }
    }

    while (curSum <= INT32_MAX)
    {
      if (exist.find(curSum) == exist.end())
      {
        return curSum;
      }

      curSum++;
    }

    return INT32_MAX;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.missingInteger(*new vector<int>{1, 2, 3, 2, 5});
  int result2 = solution.missingInteger(*new vector<int>{3, 4, 5, 1, 12, 14, 13});
  int result3 = solution.missingInteger(*new vector<int>{14, 9, 6, 9, 7, 9, 10, 4, 9, 9, 4, 4}); // 15
}