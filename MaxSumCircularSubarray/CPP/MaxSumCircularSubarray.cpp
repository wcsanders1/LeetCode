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
    int end = 1;
    int cur = nums[0];
    int iterations = 0;

    while (iterations++ <= n * 2)
    {
      if (nums[end] + cur <= 0)
      {
        end = (end + 1) % n;
        start = end;
        cur = nums[end];
        answer = max(answer, cur);
      }
      else if (iterations >= n)
      {
        while (start <= end)
        {
          cur -= nums[start++];
        }
        answer = max(answer, cur);
      }
      else
      {
        cur += nums[end];
        answer = max(answer, cur);
        end = (end + 1) % n;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSubarraySumCircular(*new vector<int>{1, -2, 3, -2}); // 3
  int result2 = solution.maxSubarraySumCircular(*new vector<int>{5, -3, 5});     // 10
  int result3 = solution.maxSubarraySumCircular(*new vector<int>{-3, -2, -3});   // -2
}