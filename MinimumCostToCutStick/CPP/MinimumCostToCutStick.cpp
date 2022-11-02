// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// NOT MINE: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/781074/JavaC%2B%2BPython-Merge-Stones
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
  int minCost(int n, vector<int> &cuts)
  {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int size = cuts.size();
    vector<vector<int>> dp = vector<vector<int>>(size, vector<int>(size, 0));

    for (int d = 2; d < size; d++)
    {
      for (int i = 0; i < size - d; i++)
      {
        dp[i][i + d] = INT32_MAX;
        for (int m = i + 1; m < i + d; m++)
        {
          dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + cuts[i + d] - cuts[i]);
        }
      }
    }

    return dp[0][size - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost(7, *new vector<int>{1, 3, 4, 5});
  int result2 = solution.minCost(9, *new vector<int>{5, 6, 1, 4, 2});
}