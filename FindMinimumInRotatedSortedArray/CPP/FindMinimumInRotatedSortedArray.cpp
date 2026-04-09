// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    return findMin(nums, 0, nums.size() - 1, INT32_MAX);
  }

private:
  int findMin(vector<int> &nums, int start, int end, int curmin)
  {
    if (start > end)
    {
      return curmin;
    }

    int mid = (end + start) / 2;
    curmin = min(curmin, nums[mid]);
    if (nums[mid] < nums[end])
    {
      return findMin(nums, start, mid - 1, curmin);
    }
    return findMin(nums, mid + 1, end, curmin);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findMin(*new vector<int>{3, 4, 5, 1, 2});
  int result2 = solution.findMin(*new vector<int>{4, 5, 6, 7, 0, 1, 2});
  int result3 = solution.findMin(*new vector<int>{11, 13, 15, 17});
  int result4 = solution.findMin(*new vector<int>{3, 1, 2});
  int result5 = solution.findMin(*new vector<int>{5, 1, 2, 3, 4});
  int result6 = solution.findMin(*new vector<int>{1});
  int result7 = solution.findMin(*new vector<int>{1, 2});
}