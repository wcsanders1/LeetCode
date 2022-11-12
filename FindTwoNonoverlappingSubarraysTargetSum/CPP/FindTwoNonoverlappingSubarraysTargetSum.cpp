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
    prefix[0] = value == target ? 1 : INT32_MAX;
    while (end < arr.size())
    {
      end++;
      value += arr[end];
      if (value > target)
      {
        while (value > target && start <= end)
        {
          value -= arr[start++];
        }
      }

      if (value == target)
      {
        prefix[end] = min(prefix[end - 1], end - start + 1);
      }
      else
      {
        prefix[end] = prefix[end - 1];
      }
    }

    return 0;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSumOfLengths(*new vector<int>{3, 2, 2, 4, 3}, 3);       // 2
  int result2 = solution.minSumOfLengths(*new vector<int>{1, 1, 1, 2, 2, 1, 1}, 4); // 6
}