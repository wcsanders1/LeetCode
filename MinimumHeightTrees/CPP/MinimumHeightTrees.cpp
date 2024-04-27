// https://leetcode.com/problems/minimum-height-trees/description/?envType=daily-question&envId=2024-04-23
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
  {
    if (n == 1)
    {
      return {0};
    };

    unordered_map<int, unordered_set<int>> graph;
    for (auto &edge : edges)
    {
      graph[edge[0]].insert(edge[1]);
      graph[edge[1]].insert(edge[0]);
    }

    vector<int> leaves;
    for (auto &[node, e] : graph)
    {
      if (e.size() == 1)
      {
        leaves.push_back(node);
      }
    }

    while (n > 2)
    {
      n -= leaves.size();
      vector<int> newLeaves;
      for (int leaf : leaves)
      {
        int next = *graph[leaf].begin();
        graph[next].erase(leaf);
        if (graph[next].size() == 1)
        {
          newLeaves.push_back(next);
        }
      }
      leaves = newLeaves;
    }

    return leaves;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findMinHeightTrees(4, *new vector<vector<int>>{{1, 0}, {1, 2}, {1, 3}});
  auto result2 = solution.findMinHeightTrees(6, *new vector<vector<int>>{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}});
  auto result3 = solution.findMinHeightTrees(15, *new vector<vector<int>>{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}, {4, 6}, {0, 7}, {4, 8}, {5, 9}, {7, 10}, {6, 11}, {0, 12}, {0, 13}, {3, 14}});
}