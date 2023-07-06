// https://leetcode.com/problems/minimum-size-subarray-sum/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int answer = INT32_MAX;

    int start = 0;
    int curSum = 0;

    for (int end = 0; end < nums.size(); end++)
    {
      curSum += nums[end];
      while (curSum >= target && start <= end)
      {
        answer = min(answer, (end - start) + 1);
        curSum -= nums[start++];
      }
    }

    return answer == INT32_MAX ? 0 : answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSubArrayLen(7, *new vector<int>{2, 3, 1, 2, 4, 3});
  int result2 = solution.minSubArrayLen(4, *new vector<int>{1, 4, 4});
  int result3 = solution.minSubArrayLen(11, *new vector<int>{1, 1, 1, 1, 1, 1, 1, 1});
}