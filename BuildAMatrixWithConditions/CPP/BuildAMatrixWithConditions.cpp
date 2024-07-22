// https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
  {
    vector<int> sortedRows = topologicalSort(k, rowConditions);
    vector<int> sortedCols = topologicalSort(k, colConditions);
    if (sortedRows.empty() || sortedCols.empty())
    {
      return {};
    }

    vector<vector<int>> matrix(k, vector<int>(k, 0));
    for (int row = 0; row < k; row++)
    {
      for (int col = 0; col < k; col++)
      {
        if (sortedRows[row] == sortedCols[col])
        {
          matrix[row][col] = sortedRows[row];
        }
      }
    }

    return matrix;
  }

private:
  vector<int> topologicalSort(int k, vector<vector<int>> &edges)
  {
    vector<vector<int>> adjacencyList(k + 1);
    for (auto &edge : edges)
    {
      adjacencyList[edge[0]].push_back(edge[1]);
    }

    vector<int> order;
    vector<int> visited(k + 1, 0);
    bool hasCycle = false;
    for (int i = 1; i <= k; i++)
    {
      if (visited[i] == 0)
      {
        dfs(i, adjacencyList, order, visited, hasCycle);
        if (hasCycle)
        {
          return {};
        }
      }
    }

    reverse(order.begin(), order.end());
    return order;
  }

  void dfs(int node, vector<vector<int>> &adjacencyList, vector<int> &order, vector<int> &visited, bool &hasCycle)
  {
    visited[node] = 1;
    for (int adjacent : adjacencyList[node])
    {
      if (visited[adjacent] == 0)
      {
        dfs(adjacent, adjacencyList, order, visited, hasCycle);
        if (hasCycle)
        {
          return;
        }
      }
      else if (visited[adjacent] == 1)
      {
        hasCycle = true;
        return;
      }
    }

    visited[node] = 2;
    order.push_back(node);
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.buildMatrix(3, *new vector<vector<int>>{{1, 2}, {3, 2}}, *new vector<vector<int>>{{2, 1}, {3, 2}});
  auto result2 = solution.buildMatrix(3, *new vector<vector<int>>{{1, 2}, {2, 3}, {3, 1}, {2, 3}}, *new vector<vector<int>>{{2, 1}});
}