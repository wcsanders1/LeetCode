// https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description/?envType=daily-question&envId=2026-10-30
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
  int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
  {
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<int>> dist(n, vector<int>(k, INT32_MAX));
    using State = tuple<int, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    for (auto &e : edges)
    {
      graph[e[0]].push_back({e[1], e[2]});
    }

    dist[0][0] = 0;
    pq.push({0, 0, 1});
    while (!pq.empty())
    {
      auto [weight, node, consec] = pq.top();
      pq.pop();

      if (weight != dist[node][consec - 1])
      {
        continue;
      }

      char lastChar = labels[node];
      for (auto &e : graph[node])
      {
        int nxt = labels[e.first] == lastChar ? consec + 1 : 1;
        if (nxt <= k && e.second + weight < dist[e.first][nxt - 1])
        {
          dist[e.first][nxt - 1] = e.second + weight;
          pq.push({e.second + weight, e.first, nxt});
        }
      }
    }

    int answer = INT32_MAX;
    for (int i = 0; i < k; i++)
    {
      answer = min(answer, dist[n - 1][i]);
    }

    return answer == INT32_MAX ? -1 : answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.shortestPath(3, *new vector<vector<int>>{{0, 1, 1}, {1, 2, 1}, {0, 2, 3}}, "aab", 1);
  int result2 = solution.shortestPath(3, *new vector<vector<int>>{{0, 1, 1}, {1, 2, 1}, {0, 2, 3}}, "aab", 2);
  int result3 = solution.shortestPath(3, *new vector<vector<int>>{{0, 1, 1}, {1, 2, 1}}, "aaa", 2);
  int result4 = solution.shortestPath(4, *new vector<vector<int>>{{0, 1, 3}, {0, 2, 1}, {1, 2, 4}, {2, 3, 1}}, "abaa", 2);
}