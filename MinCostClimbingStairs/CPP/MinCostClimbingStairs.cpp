// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <vector>

using namespace std;

class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    if (cost.size() == 2)
    {
      return min(cost[0], cost[1]);
    }

    for (int i = 2; i < cost.size(); i++)
    {
      int c = cost[i];
      cost[i] = min(c + cost[i - 1], c + cost[i - 2]);
    }

    return min(cost[cost.size() - 1], cost[cost.size() - 2]);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCostClimbingStairs(*new vector<int>{10, 15, 20});
  int result2 = solution.minCostClimbingStairs(*new vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
}