// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
#include <vector>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int x)
  {
    vector<int> leftTotals(nums.size(), 0);
    vector<int> rightTotals(nums.size(), 0);

    leftTotals[0] = nums[0];
    rightTotals[0] = nums[nums.size() - 1];

    int leftLimit = 0;
    int rightLimit = 0;

    for (int i = 1; i < nums.size(); i++)
    {
      int start = i;
      int end = (nums.size() - 1) - i;

      leftTotals[i] = nums[start] + nums[start - 1];
      rightTotals[i] = nums[end] + nums[end + 1];

      if (leftTotals[i] <= x)
      {
        leftLimit = i;
      }

      if (rightTotals[i] <= x)
      {
        rightLimit = i;
      }
    }

    int answer = INT32_MAX;

    while (leftLimit >= 0 || rightLimit >= 0)
    {
      if (leftLimit >= 0)
      {
      }
    }

    return answer == INT32_MAX ? -1 : answer;
  }

private:
  int binarySearch(vector<int> &collection, int goal, int start, int end)
  {
    if (start >= end)
    {
      return collection[start] == goal ? start : -1;
    }

    int index = (end + start) / 2;
    int result = collection[index];

    if (result == goal)
    {
      return index;
    }

    if (result < goal)
    {
      return binarySearch(collection, goal, start, index);
    }

    return binarySearch(collection, goal, index, end);
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