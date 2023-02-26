// https://leetcode.com/problems/left-and-right-sum-differences/
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
  vector<int> leftRigthDifference(vector<int> &nums)
  {
    vector<int> leftSum(nums.size(), 0);
    vector<int> rightSum(nums.size(), 0);

    for (int i = 1; i < nums.size(); i++)
    {
      leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
      rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }

    vector<int> answer(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
      answer[i] = abs(leftSum[i] - rightSum[i]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.leftRigthDifference(*new vector<int>{10, 4, 8, 3});
  auto result2 = solution.leftRigthDifference(*new vector<int>{1});
}