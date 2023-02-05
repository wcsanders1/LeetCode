// 6346
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
  int minCapability(vector<int> &nums, int k)
  {
    if (nums.size() == 1)
    {
      return nums[0];
    }

    vector<int> best(nums.size(), 0);
    best[nums.size() - 1] = nums[nums.size() - 1];
    best[nums.size() - 2] = nums[nums.size() - 2];
    for (int i = nums.size() - 3; i >= 0; i--)
    {
      int t = INT32_MAX;
      for (int j = i + 2; j < nums.size(); j++)
      {
        int m = max(nums[i], nums[j]);
        t = min(t, m);
      }
      best[i] = t;
    }
  }
};