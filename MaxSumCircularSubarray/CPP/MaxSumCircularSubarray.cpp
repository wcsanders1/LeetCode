// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
// NOT MINE: https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/178422/one-pass/?orderBy=most_votes
#include <vector>

using namespace std;

class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int curMax = 0;
    int maxSum = nums[0];
    int curMin = 0;
    int minSum = nums[0];
    int total = 0;

    for (int n : nums)
    {
      curMax = max(curMax + n, n);
      maxSum = max(curMax, maxSum);
      curMin = min(curMin + n, n);
      minSum = min(curMin, minSum);
      total += n;
    }

    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSubarraySumCircular(*new vector<int>{1, -2, 3, -2});                  // 3
  int result2 = solution.maxSubarraySumCircular(*new vector<int>{5, -3, 5});                      // 10
  int result3 = solution.maxSubarraySumCircular(*new vector<int>{-3, -2, -3});                    // -2
  int result4 = solution.maxSubarraySumCircular(*new vector<int>{2, 2});                          // 4
  int result5 = solution.maxSubarraySumCircular(*new vector<int>{2});                             // 2
  int result6 = solution.maxSubarraySumCircular(*new vector<int>{0, 5, 8, -9, 9, -7, 3, -2});     // 16
  int result7 = solution.maxSubarraySumCircular(*new vector<int>{-5, -2, 5, 6, -2, -7, 0, 2, 8}); // 14
}