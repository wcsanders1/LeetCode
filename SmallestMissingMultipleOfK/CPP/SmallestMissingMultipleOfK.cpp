// https://leetcode.com/problems/smallest-missing-multiple-of-k/description/?envType=daily-question&envId=2026-08-25
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
  int missingMultiple(vector<int> &nums, int k)
  {
    unordered_set<int> s(nums.begin(), nums.end());
    int i = 1;
    while (s.find(k * i) != s.end())
    {
      i++;
    }

    return k * i;
  }
};