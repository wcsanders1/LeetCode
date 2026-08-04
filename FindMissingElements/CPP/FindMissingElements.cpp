// https://leetcode.com/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> findMissingElements(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<int> missing;
    for (int i = 1; i < nums.size(); i++)
    {
      int cur = nums[i - 1];
      while (nums[i] - cur > 1)
      {
        missing.push_back(++cur);
      }
    }

    return missing;
  }
};