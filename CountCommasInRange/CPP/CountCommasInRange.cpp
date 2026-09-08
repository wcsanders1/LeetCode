// https://leetcode.com/problems/count-commas-in-range/description/?envType=daily-question&envId=2026-09-08
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
  int countCommas(int n)
  {
    return max(0, n - 999);
  }
};