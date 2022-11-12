// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
#include <vector>

using namespace std;

class Solution
{
public:
  int minSumOfLengths(vector<int> &arr, int target)
  {
    vector<int> prefix(arr.size() + 1, INT32_MAX);
    vector<int> suffix(arr.size() + 1, INT32_MAX);

    int start = 0;
    int end = 0;
    int value = arr[end];
    prefix[1] = value == target ? 1 : INT32_MAX;
    while (end < arr.size() - 1)
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
        prefix[end + 1] = min(prefix[end], end - start + 1);
      }
      else
      {
        prefix[end + 1] = prefix[end];
      }
    }

    start = arr.size() - 1;
    end = arr.size() - 1;
    value = arr[end];
    suffix[end] = value == target ? 1 : INT32_MAX;
    while (end > 0)
    {
      end--;
      value += arr[end];
      if (value > target)
      {
        while (value > target && start >= end)
        {
          value -= arr[start--];
        }
      }

      if (value == target)
      {
        suffix[end] = min(suffix[end + 1], start - end + 1);
      }
      else
      {
        suffix[end] = suffix[end + 1];
      }
    }

    int answer = INT32_MAX;
    for (int i = 0; i < prefix.size(); i++)
    {
      if (prefix[i] == INT32_MAX || suffix[i] == INT32_MAX)
      {
        continue;
      }
      answer = min(answer, prefix[i] + suffix[i]);
    }

    return answer == INT32_MAX ? -1 : answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSumOfLengths(*new vector<int>{3, 2, 2, 4, 3}, 3);       // 2
  int result2 = solution.minSumOfLengths(*new vector<int>{1, 1, 1, 2, 2, 1, 1}, 4); // 6
  int result3 = solution.minSumOfLengths(*new vector<int>{4, 3, 2, 6, 2, 3, 4}, 6); // -1
}