// https://leetcode.com/problems/find-peak-element/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    vector<bool> visited(nums.size(), false);
    return getIndex(nums, visited, nums.size() / 2);
  }

private:
  int getIndex(vector<int> &nums, vector<bool> &visited, int index)
  {
    if (nums.size() == 1)
    {
      return 0;
    }

    if (index == 0)
    {
      if (nums[0] > nums[1])
      {
        return index;
      }

      return getIndex(nums, visited, index + 1);
    }

    if (index == nums.size() - 1)
    {
      if (nums[nums.size() - 1] > nums[nums.size() - 2])
      {
        return index;
      }

      return getIndex(nums, visited, index - 1);
    }

    if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1])
    {
      return index;
    }

    if (visited[index])
    {
      int i = nums[index + 1] > nums[index] ? index + 1 : index - 1;
      return getIndex(nums, visited, i);
    }

    visited[index] = true;

    if (nums[index] < nums[index + 1])
    {
      return getIndex(nums, visited, (nums.size() + index) / 2);
    }

    return getIndex(nums, visited, index / 2);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findPeakElement(*new vector<int>{1, 2, 3, 1});
  int result2 = solution.findPeakElement(*new vector<int>{1, 2, 1, 3, 5, 6, 4});
  int result3 = solution.findPeakElement(*new vector<int>{2, 3, 4, 3, 2, 1});
  int result4 = solution.findPeakElement(*new vector<int>{9, 7, 3, 7, 8});
}