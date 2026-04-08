// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    return search(nums, target, 0, nums.size() - 1);
  }

private:
  int search(vector<int> &nums, int target, int start, int end)
  {
    if (start > end)
    {
      return -1;
    }

    int mid = (end + start) / 2;
    int num = nums[mid];
    if (num == target)
    {
      return mid;
    }

    if (nums[start] <= num)
    {
      if (target >= nums[start] && target < num)
      {
        return search(nums, target, start, end - 1);
      }
      return search(nums, target, mid + 1, end);
    }
    if (target > num && target <= nums[end])
    {
      return search(nums, target, mid + 1, end);
    }
    return search(nums, target, start, end - 1);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.search(*new vector<int>{4, 5, 6, 7, 0, 1, 2}, 0);
  int result2 = solution.search(*new vector<int>{4, 5, 6, 7, 0, 1, 2}, 3);
  int result3 = solution.search(*new vector<int>{1}, 0);
  int result4 = solution.search(*new vector<int>{3, 5, 1}, 3);
  int result5 = solution.search(*new vector<int>{5, 1, 3}, 3);
  int result6 = solution.search(*new vector<int>{5, 1, 3}, 5);
  int result7 = solution.search(*new vector<int>{4, 5, 6, 7, 8, 1, 2, 3}, 8);
}