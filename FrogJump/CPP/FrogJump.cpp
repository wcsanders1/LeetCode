// https://leetcode.com/problems/frog-jump/
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  bool canCross(vector<int> &stones)
  {
    vector<int> changes{-1, 0, 1};
    vector<set<int>> dp(stones.size(), set<int>());
    dp[stones.size() - 1].insert(0);

    for (int i = stones.size() - 2; i >= 0; i--)
    {
      for (int j = i + 1; j < stones.size(); j++)
      {
        int requiredJumps = stones[j] - stones[i];
        if (requiredJumps > stones[i] + 1)
        {
          break;
        }

        if (dp[j].find(0) != dp[j].end())
        {
          dp[i].insert(requiredJumps);
          break;
        }

        for (int change : changes)
        {
          if (dp[j].find(requiredJumps + change) != dp[j].end())
          {
            dp[i].insert(requiredJumps);
          }
        }
      }
    }

    return dp[0].find(1) != dp[0].end();
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canCross(*new vector<int>{0, 1, 3, 5, 6, 8, 12, 17}); // true
  bool result2 = solution.canCross(*new vector<int>{0, 1, 2, 3, 4, 8, 9, 11});  // false
  bool result3 = solution.canCross(*new vector<int>{0, 1, 3, 6, 7});            // false
}