// https://leetcode.com/problems/two-city-scheduling/
// NOT MINE: https://leetcode.com/problems/two-city-scheduling/discuss/278716/C%2B%2B-O(n-log-n)-sort-by-savings
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int twoCitySchedCost(vector<vector<int>> &costs)
  {
    sort(costs.begin(), costs.end(), [](vector<int> &v1, vector<int> &v2)
         { return (v1[0] - v1[1] < v2[0] - v2[1]); });

    int answer = 0;
    for (int i = 0; i < costs.size() / 2; i++)
    {
      answer += costs[i][0] + costs[i + costs.size() / 2][1];
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.twoCitySchedCost(*new vector<vector<int>>{{10, 20}, {30, 200}, {400, 50}, {30, 20}});
}