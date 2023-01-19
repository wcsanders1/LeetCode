// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
#include <vector>

using namespace std;

class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int answer = nums[0];
    int n = nums.size();
    if (n == 1)
    {
      return answer;
    }

    int start = 0;
    int end = 0;
    int cur = nums[0];
    nums.insert(nums.end(), nums.begin(), nums.end());

    while (end < nums.size())
    {
      while (end - start >= n - 1)
      {
        cur -= nums[start++];
      }
      answer = max(answer, cur);

      while (nums[start] <= 0 && end < nums.size())
      {
        cur -= nums[start++];
        if (start > end)
        {
          if (end >= nums.size() - 1)
          {
            break;
          }
          cur += nums[++end];
          answer = max(answer, cur);
        }
      }

      if (end < nums.size() - 1)
      {
        end++;
        if (nums[end] >= cur + nums[end])
        {
          cur = nums[end];
          start = end;
        }
        else
        {
          cur += nums[end];
        }
        answer = max(answer, cur);
      }
      else
      {
        end++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSubarraySumCircular(*new vector<int>{1, -2, 3, -2});              // 3
  int result2 = solution.maxSubarraySumCircular(*new vector<int>{5, -3, 5});                  // 10
  int result3 = solution.maxSubarraySumCircular(*new vector<int>{-3, -2, -3});                // -2
  int result4 = solution.maxSubarraySumCircular(*new vector<int>{2, 2});                      // 4
  int result5 = solution.maxSubarraySumCircular(*new vector<int>{2});                         // 2
  int result6 = solution.maxSubarraySumCircular(*new vector<int>{0, 5, 8, -9, 9, -7, 3, -2}); // 16
}