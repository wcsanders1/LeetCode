#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    unordered_set<int> travel(begin(days), end(days));
    int dp[30] = {};

    for (int i = days.front(); i <= days.back(); i++)
    {
      if (travel.find(i) == travel.end())
      {
        dp[i % 30] = dp[(i - 1) % 30];
      }
      else
      {
        dp[i % 30] = min({dp[(i - 1) % 30] + costs[0], dp[max(0, i - 7) % 30] + costs[1], dp[max(0, i - 30) % 30] + costs[2]});
      }
    }

    return dp[days.back() % 30];
  }
};

int main()
{
  Solution solution;
  int result1 = solution.mincostTickets(*new vector<int>{1, 4, 6, 7, 8, 20}, *new vector<int>{2, 7, 15});
}