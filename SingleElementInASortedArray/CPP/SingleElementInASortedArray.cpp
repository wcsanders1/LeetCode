// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// NOT O(log n)
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    return getNonDuplicate(nums, 0, nums.size() - 1);
  }

private:
  int getNonDuplicate(vector<int> &nums, int start, int end)
  {
    if (start >= end)
    {
      return nums[start];
    }

    if (nums[start] != nums[start + 1])
    {
      return nums[start];
    }
    else
    {
      start += 2;
    }

    if (nums[end] != nums[end - 1])
    {
      return nums[end];
    }
    else
    {
      end -= 2;
    }

    return getNonDuplicate(nums, start, end);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.singleNonDuplicate(*new vector<int>{1, 1, 2, 3, 3, 4, 4, 8, 8});
  int result2 = solution.singleNonDuplicate(*new vector<int>{3, 3, 7, 7, 10, 11, 11});
  int result3 = solution.singleNonDuplicate(*new vector<int>{1});
}