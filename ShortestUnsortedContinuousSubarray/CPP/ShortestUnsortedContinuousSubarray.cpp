// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    vector<int> c = nums;
    sort(c.begin(), c.end());

    int start = 0;
    while (start < nums.size() && nums[start] == c[start])
    {
      start++;
    }

    if (start >= nums.size())
    {
      return 0;
    }

    int end = nums.size() - 1;
    while (end >= 0 && nums[end] == c[end])
    {
      end--;
    }

    return end - start + 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findUnsortedSubarray(*new vector<int>{2, 6, 4, 8, 10, 9, 15}); // 5
  int result2 = solution.findUnsortedSubarray(*new vector<int>{2, 4, 6, 8, 10, 9, 15}); // 2
  int result3 = solution.findUnsortedSubarray(*new vector<int>{1, 2, 3, 4});            // 0
  int result4 = solution.findUnsortedSubarray(*new vector<int>{1});                     // 0
  int result5 = solution.findUnsortedSubarray(*new vector<int>{2, 3, 3, 2, 4});         // 3
  int result6 = solution.findUnsortedSubarray(*new vector<int>{1, 3, 5, 4, 2});         // 4
  int result7 = solution.findUnsortedSubarray(*new vector<int>{1, 3, 2, 2, 2});         // 4
  int result8 = solution.findUnsortedSubarray(*new vector<int>{1, 2, 5, 3, 4});         // 3
}