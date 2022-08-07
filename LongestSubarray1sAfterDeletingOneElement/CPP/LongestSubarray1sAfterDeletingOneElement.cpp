// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// NOT MINE: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708112/JavaC%2B%2BPython-Sliding-Window-at-most-one-0
#include <vector>

using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums)
  {
    int i = 0;
    int j = 0;
    int k = 1;

    for (j = 0; j < nums.size(); ++j)
    {
      if (nums[j] == 0)
      {
        k--;
      }

      if (k < 0 && nums[i++] == 0)
      {
        k++;
      }
    }

    return nums.size() - i - 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestSubarray(*new vector<int>{1, 1, 0, 1});                                                 // 3
  int result2 = solution.longestSubarray(*new vector<int>{0, 1, 1, 1, 0, 1, 1, 0});                                     // 5
  int result3 = solution.longestSubarray(*new vector<int>{1, 1, 1});                                                    // 2
  int result4 = solution.longestSubarray(*new vector<int>{0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0}); // 9
  int result5 = solution.longestSubarray(*new vector<int>{0, 0, 0, 1, 1, 1, 0, 0, 1});                                  // 3
  int result6 = solution.longestSubarray(*new vector<int>{0, 0, 0, 1, 1, 1, 0, 1});                                     // 4
  int result7 = solution.longestSubarray(*new vector<int>{0, 0, 0});                                                    // 0
  int result8 = solution.longestSubarray(*new vector<int>{0, 1, 0});                                                    // 1
  int result9 = solution.longestSubarray(*new vector<int>{0, 0, 1});                                                    // 1
  int result10 = solution.longestSubarray(*new vector<int>{1, 0, 0});                                                   // 1
  int result11 = solution.longestSubarray(*new vector<int>{1, 0, 1});                                                   // 2
  int result12 = solution.longestSubarray(*new vector<int>{0, 0, 1, 1});                                                // 2
}