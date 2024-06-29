// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
  {
    unordered_map<int, vector<int>> graph;
    for (auto &edge : edges)
    {
      graph[edge[1]].push_back(edge[0]);
    }

    vector<vector<int>> ancestors(n);
    for (int i = 0; i < n; i++)
    {
      vector<bool> visited(n, false);
      getAncestors(i, i, graph, ancestors, visited);
    }

    for (int j = 0; j < n; j++)
    {
      sort(ancestors[j].begin(), ancestors[j].end());
    }

    return ancestors;
  }

private:
  void getAncestors(int node, int child, unordered_map<int, vector<int>> &graph, vector<vector<int>> &ancestors, vector<bool> &visited)
  {
    for (int a : graph[node])
    {
      if (!visited[a])
      {
        visited[a] = true;
        ancestors[child].push_back(a);
        getAncestors(a, child, graph, ancestors, visited);
      }
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.getAncestors(8, *new vector<vector<int>>{{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}});
  auto result2 = solution.getAncestors(5, *new vector<vector<int>>{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}});
  auto result3 = solution.getAncestors(9, *new vector<vector<int>>{{3, 6}, {2, 4}, {8, 6}, {7, 4}, {1, 4}, {2, 1}, {7, 2}, {0, 4}, {5, 0}, {4, 6}, {3, 2}, {5, 6}, {1, 6}});
}