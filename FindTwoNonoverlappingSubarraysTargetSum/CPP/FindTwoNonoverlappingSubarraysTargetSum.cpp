// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
#include <vector>

using namespace std;

class Solution
{
public:
  int minSumOfLengths(vector<int> &arr, int target)
  {
    vector<int> prefix(arr.size(), INT32_MAX);
    vector<int> suffix(arr.size(), INT32_MAX);

    int start = 0;
    int end = 0;
    int value = arr[0];
    while (end < arr.size())
    {
      if (value < target)
      {
        if (++end >= arr.size())
        {
          break;
        }

        value += arr[end];
      }
      else if (value > target)
      {
            }
    }
  }
};