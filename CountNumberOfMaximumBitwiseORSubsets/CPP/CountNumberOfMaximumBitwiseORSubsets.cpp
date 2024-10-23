// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int countMaxOrSubsets(vector<int> &nums)
  {
    int maxPossible = 0;
    for (int &n : nums)
    {
      maxPossible |= n;
    }

    return countMaxOrSubsets(nums, maxPossible, 0, 0);
  }

private:
  int countMaxOrSubsets(vector<int> &nums, int maxPossible, int start, int current)
  {
    if (start == nums.size())
    {
      return 0;
    }

    int result = 0;
    for (int i = start; i < nums.size(); i++)
    {
      int nextCurrent = current | nums[i];
      if (nextCurrent == maxPossible)
      {
        result++;
      }
      result += countMaxOrSubsets(nums, maxPossible, i + 1, nextCurrent);
    }

    return result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countMaxOrSubsets(*new vector<int>{3, 1});
  int result2 = solution.countMaxOrSubsets(*new vector<int>{2, 2, 2});
  int result3 = solution.countMaxOrSubsets(*new vector<int>{3, 2, 1, 5});
}