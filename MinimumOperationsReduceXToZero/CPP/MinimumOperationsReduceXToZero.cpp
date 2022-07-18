// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
#include <vector>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int x)
  {
    return getMinOperations(nums, x, 0, nums.size() - 1);
  }

private:
  int getMinOperations(vector<int> &nums, int goal, int left, int right, int currentSum = 0)
  {
    if (left > right)
    {
      return -1;
    }

    int operations = (nums.size() - 1) - (right - left);
    int leftSum = currentSum + nums[left];
    int rightSum = currentSum + nums[right];

    if (leftSum == goal || rightSum == goal)
    {
      return operations + 1;
    }

    int deepLeft = leftSum > goal ? -1 : getMinOperations(nums, goal, left + 1, right, leftSum);
    int deepRight = rightSum > goal ? -1 : getMinOperations(nums, goal, left, right - 1, rightSum);

    if (deepLeft == -1)
    {
      return deepRight;
    }
    else if (deepRight == -1)
    {
      return deepLeft;
    }

    return min(deepLeft, deepRight);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(*new vector<int>{1, 1, 4, 2, 3}, 5);
  int result2 = solution.minOperations(*new vector<int>{5, 6, 7, 8, 9}, 4);
  int result3 = solution.minOperations(*new vector<int>{3, 2, 20, 1, 1, 3}, 10);
  int result4 = solution.minOperations(*new vector<int>{10, 1, 1, 1, 1, 1}, 5);
}