// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#include <vector>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    int start = 0;
    int end = nums.size() - 1;
    bool isSorted = true;

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] < nums[i - 1])
      {
        isSorted = false;

        int n = nums[i];
        int k = i + 1;
        while (k < nums.size() && nums[k] <= n)
        {
          k++;
        }

        start = k;
        while (start >= 0 && nums[start] > nums[i])
        {
          start--;
        }
        start++;
        break;
      }
    }

    if (isSorted)
    {
      return 0;
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
      if (nums[i] > nums[i + 1])
      {
        end = i + 1;
        while (end < nums.size() && nums[end] < nums[i])
        {
          end++;
        }
        break;
      }
    }

    return end - start;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.findUnsortedSubarray(*new vector<int>{2, 6, 4, 8, 10, 9, 15}); // 5
  // int result2 = solution.findUnsortedSubarray(*new vector<int>{2, 4, 6, 8, 10, 9, 15}); // 2
  // int result3 = solution.findUnsortedSubarray(*new vector<int>{1, 2, 3, 4});            // 0
  // int result4 = solution.findUnsortedSubarray(*new vector<int>{1});                     // 0
  // int result5 = solution.findUnsortedSubarray(*new vector<int>{2, 3, 3, 2, 4});         // 3
  int result6 = solution.findUnsortedSubarray(*new vector<int>{1, 3, 5, 4, 2}); // 4
}