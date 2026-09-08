// https://leetcode.com/problems/smallest-stable-index-i/?envType=daily-question&envId=2026-09-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int firstStableIndex(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> mx(n, 0);
    vector<int> mn(n, 0);
    mx[0] = nums[0];
    mn[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
      mx[i] = max(nums[i], mx[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
      mn[i] = min(nums[i], mn[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
      if (mx[i] - mn[i] <= k)
      {
        return i;
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.firstStableIndex(*new vector<int>{5, 0, 1, 4}, 3);
  int result2 = solution.firstStableIndex(*new vector<int>{3, 2, 1}, 1);
  int result3 = solution.firstStableIndex(*new vector<int>{0}, 0);
  int result4 = solution.firstStableIndex(*new vector<int>{1, 1}, 0);
}