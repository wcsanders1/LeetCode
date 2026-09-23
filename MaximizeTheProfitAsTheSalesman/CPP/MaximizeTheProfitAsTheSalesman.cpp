// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/
// NOT MINE: https://leetcode.com/problems/maximize-the-profit-as-the-salesman/solutions/3934188/javacpython-dp-on-m-by-lee215-t41d/
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
  int maximizeTheProfit(int n, vector<vector<int>> &offers)
  {
    vector<int> dp(n + 1, 0);
    vector<vector<vector<int>>> ends(n);
    for (auto &offer : offers)
    {
      ends[offer[1]].push_back(offer);
    }

    for (int i = 1; i <= n; i++)
    {
      dp[i] = dp[i - 1];
      for (auto &e : ends[i - 1])
      {
        dp[i] = max(dp[i], e[2] + dp[e[0]]);
      }
    }
    return dp[n];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximizeTheProfit(5, *new vector<vector<int>>{{0, 0, 1}, {0, 2, 2}, {1, 3, 2}});
  int result2 = solution.maximizeTheProfit(5, *new vector<vector<int>>{{0, 0, 1}, {0, 2, 10}, {1, 3, 2}});
}