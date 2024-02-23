// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    vector<vector<long long>> dp(k + 1, vector<long long>(n, INT32_MAX));
    for (auto f : flights)
    {
      long long d = f[1] == dst ? f[2] : INT32_MAX;
      dp[0][f[0]] = min(dp[0][f[0]], d);
    }

    for (int stop = 1; stop <= k; stop++)
    {
      for (int flight = 0; flight < flights.size(); flight++)
      {
        int s = flights[flight][0];
        int d = flights[flight][1];
        int c = flights[flight][2];

        dp[stop][s] = min(dp[stop - 1][s], min(dp[stop - 1][d] + c, dp[stop][s]));
      }
    }

    return dp[k][src] >= INT32_MAX ? -1 : dp[k][src];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findCheapestPrice(4, *new vector<vector<int>>{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}}, 0, 3, 1);
  int result2 = solution.findCheapestPrice(3, *new vector<vector<int>>{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 1);
  int result3 = solution.findCheapestPrice(3, *new vector<vector<int>>{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 0);
}