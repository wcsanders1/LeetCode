// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    auto midptr = nums.end() - k;
    nth_element(nums.begin(), midptr, nums.end());
    return *midptr;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findKthLargest(*new vector<int>{3, 2, 1, 5, 6, 4}, 2);
  int result2 = solution.findKthLargest(*new vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4);
}