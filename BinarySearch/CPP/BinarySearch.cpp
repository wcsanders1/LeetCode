// https://leetcode.com/problems/binary-search/description/
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

    if (num < target)
    {
      return search(nums, target, mid + 1, end);
    }

    return search(nums, target, start, mid - 1);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.search(*new vector<int>{-1, 0, 3, 5, 9, 12}, 9);
  int result2 = solution.search(*new vector<int>{-1, 0, 3, 5, 9, 12}, 5);
  int result3 = solution.search(*new vector<int>{-1, 0, 3, 5, 9, 12}, 12);
  int result4 = solution.search(*new vector<int>{-1, 0, 3, 5, 9, 12}, -1);
  int result5 = solution.search(*new vector<int>{-1, 0, 3, 5, 9, 12}, 2);
}