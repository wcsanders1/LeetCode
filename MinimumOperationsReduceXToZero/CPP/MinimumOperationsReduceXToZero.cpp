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

      leftTotals[i] = nums[start] + leftTotals[start - 1];
      rightTotals[i] = nums[end] + rightTotals[start - 1];

      if (leftTotals[i] <= x)
      {
        leftLimit = i;
      }

      if (rightTotals[i] <= x)
      {
        rightLimit = i;
      }
    }

    if (leftTotals[leftTotals.size() - 1] < x)
    {
      return -1;
    }

    int answer = INT32_MAX;

    while (leftLimit >= 0 || rightLimit >= 0)
    {
      if (leftLimit >= 0 && leftTotals[leftLimit] == x)
      {
        answer = min(answer, leftLimit + 1);
      }

      if (rightLimit >= 0 && rightTotals[rightLimit] == x)
      {
        answer = min(answer, rightLimit + 1);
      }

      if (leftLimit >= 0 && rightLimit >= 0)
      {
        int needRight = x - leftTotals[leftLimit];
        if (needRight > 0)
        {
          int rightIndex = binarySearch(rightTotals, needRight, 0, rightLimit);
          if (rightIndex < INT32_MAX)
          {
            answer = min(answer, leftLimit + rightIndex + 2);
          }
        }

        int needLeft = x - rightTotals[rightLimit];
        if (needLeft > 0)
        {
          int leftIndex = binarySearch(leftTotals, needLeft, 0, leftLimit);

          if (leftIndex < INT32_MAX)
          {
            answer = min(answer, rightLimit + leftIndex + 2);
          }
        }
      }

      leftLimit = leftLimit < 0 ? leftLimit : leftLimit - 1;
      rightLimit = rightLimit < 0 ? rightLimit : rightLimit - 1;
    }

    return answer == INT32_MAX ? -1 : answer;
  }

private:
  int binarySearch(vector<int> &collection, int goal, int start, int end)
  {
    if (start >= end)
    {
      return collection[start] == goal ? start : INT32_MAX;
    }

    int index = (end + start) / 2;
    int result = collection[index];

    if (result == goal)
    {
      return index;
    }

    if (result >= goal)
    {
      return binarySearch(collection, goal, start, index);
    }

    return binarySearch(collection, goal, index + 1, end);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(*new vector<int>{1, 1, 4, 2, 3}, 5);
  int result2 = solution.minOperations(*new vector<int>{5, 6, 7, 8, 9}, 4);      // -1
  int result3 = solution.minOperations(*new vector<int>{3, 2, 20, 1, 1, 3}, 10); // 5
  int result4 = solution.minOperations(*new vector<int>{10, 1, 1, 1, 1, 1}, 5);
  int result5 = solution.minOperations(*new vector<int>{1, 1}, 3); // -1
}