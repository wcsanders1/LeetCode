// https://leetcode.com/problems/two-city-scheduling/
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int twoCitySchedCost(vector<vector<int>> &costs)
  {
    for (int i = 1; i <= costs.size(); i++)
    {
      costs[i - 1].push_back(i);
    }

    vector<vector<int>> costs_b;
    for (auto c : costs)
    {
      costs_b.push_back({c[0], c[1], c[2]});
    }

    sort(costs.begin(), costs.end(), [](const auto &a, const auto &b)
         { return a[0] < b[0]; });

    sort(costs_b.begin(), costs_b.end(), [](const auto &a, const auto &b)
         { return a[1] < b[1]; });

    unordered_map<int, vector<int>> cache;
    for (int i = 1; i <= costs.size(); i++)
    {
      cache[i] = vector<int>();
    }

    int answer = 0;
    int half = costs.size() / 2;
    for (int i = 1; i <= costs.size(); i++)
    {
      if (i <= half)
      {
        int n = costs[i - 1][0];
        answer += n;
        cache[costs[i - 1][2]].push_back(n);
      }
      else
      {
        int n = costs_b[i - half - 1][1];
        answer += n;
        cache[costs_b[i - half - 1][2]].push_back(n);
      }
    }

    int a = half;
    int b = half;
    auto it = cache.begin();

    while (it != cache.end())
    {
      auto c = *it;
      if (c.second.size() < 2)
      {
        continue;
      }

      int diff_a = costs[a][0] - c.second[0];
      int diff_b = costs_b[b][1] - c.second[1];

      if (diff_a <= diff_b)
      {
      }
      else
      {
      }

      it = cache.begin();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.twoCitySchedCost(*new vector<vector<int>>{{10, 20}, {30, 200}, {400, 50}, {30, 20}});
}