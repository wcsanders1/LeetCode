// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/?envType=daily-question&envId=2026-11-03
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
  int minMoves(vector<int> &nums)
  {
    int mx = 0;
    for (int n : nums)
    {
      mx = max(mx, n);
    }

    int answer = 0;
    for (int n : nums)
    {
      answer += mx - n;
    }

    return answer;
  }
};