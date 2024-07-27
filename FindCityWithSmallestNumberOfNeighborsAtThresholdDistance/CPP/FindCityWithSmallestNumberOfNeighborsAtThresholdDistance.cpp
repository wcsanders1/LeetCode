// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=daily-question&envId=2024-07-26
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    unordered_map<int, vector<vector<int>>> graph;
    for (auto &edge : edges)
    {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<vector<int>> shortestPaths(n, vector<int>(n, INT32_MAX));
    for (int i = 0; i < n; i++)
    {
      shortestPaths[i][i] = 0;
      dykstra(i, graph, shortestPaths[i]);
    }

    int answer = 0;
    int minCount = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
      vector<int> &paths = shortestPaths[i];
      int count = 0;
      for (int j = 0; j < n; j++)
      {
        if (j == i)
        {
          continue;
        }

        if (paths[j] <= distanceThreshold)
        {
          count++;
        }
      }

      if (count <= minCount)
      {
        minCount = count;
        answer = i;
      }
    }

    return answer;
  }

private:
  void dykstra(int source, unordered_map<int, vector<vector<int>>> &graph, vector<int> &shortestPaths)
  {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, source});
    while (!q.empty())
    {
      int distance = q.top()[0];
      int node = q.top()[1];
      q.pop();

      if (distance > shortestPaths[node])
      {
        continue;
      }

      for (auto &edge : graph[node])
      {
        if (distance + edge[1] < shortestPaths[edge[0]])
        {
          shortestPaths[edge[0]] = distance + edge[1];
          q.push({shortestPaths[edge[0]], edge[0]});
        }
      }
    }
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findTheCity(4, *new vector<vector<int>>{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 4);                          // 3
  int result2 = solution.findTheCity(5, *new vector<vector<int>>{{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}}, 2);    // 0
  int result3 = solution.findTheCity(6, *new vector<vector<int>>{{0, 3, 7}, {2, 4, 1}, {0, 1, 5}, {2, 3, 10}, {1, 3, 6}, {1, 2, 1}}, 417); // 5
  int result4 = solution.findTheCity(6, *new vector<vector<int>>{{0, 1, 10}, {0, 2, 1}, {2, 3, 1}, {1, 3, 1}, {1, 4, 1}, {4, 5, 10}}, 20); // 5
}