// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minCost(int n, vector<vector<int>> &edges)
  {
    unordered_map<int, vector<vector<int>>> graph;
    for (auto &e : edges)
    {
      graph[e[0]].push_back({e[1], e[2]});
      graph[e[1]].push_back({e[0], e[2] * 2});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> distances(n, INT32_MAX);
    distances[0] = 0;

    pq.push({0, 0});
    while (!pq.empty())
    {
      auto cur = pq.top();
      pq.pop();

      int node = cur[1];
      int distance = cur[0];

      if (distances[node] < distance)
      {
        continue;
      }

      for (auto &neighbor : graph[node])
      {
        int nextDistance = distance + neighbor[1];
        int nextNode = neighbor[0];
        if (distances[nextNode] > nextDistance)
        {
          distances[nextNode] = nextDistance;
          pq.push({nextDistance, nextNode});
        }
      }
    }

    return distances[n - 1] == INT32_MAX ? -1 : distances[n - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost(4, *new vector<vector<int>>{{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}});
  int result2 = solution.minCost(4, *new vector<vector<int>>{{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}});
}