// https://leetcode.com/problems/path-with-maximum-probability/
#include <vector>
#include <string>

using namespace std;

struct Node
{
public:
  int connection;
  double probability;
  Node(int c, double p)
  {
    connection = c;
    probability = p;
  }
};

class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {
    vector<vector<Node>> graph(n, vector<Node>());
    for (int i = 0; i < edges.size(); i++)
    {
      vector<int> edge = edges[i];
      double probability = succProb[i];
      graph[edge[0]].push_back(Node(edge[1], probability));
      graph[edge[1]].push_back(Node(edge[0], probability));
    }

    vector<double> dp(n, 0);
    vector<bool> traveled(n, false);
    double maxPath = findMaxPath(graph, dp, start, end, traveled);

    return maxPath;
  }

private:
  double findMaxPath(vector<vector<Node>> &graph, vector<double> &dp, int start, int end, vector<bool> &traveled)
  {
    double maxPath = 0;
    for (Node node : graph[start])
    {
      if (traveled[node.connection])
      {
        continue;
      }

      if (node.connection == end)
      {
        maxPath = max(maxPath, node.probability);
        continue;
      }

      else if (dp[node.connection] == 0)
      {
        traveled[start] = true;
        dp[node.connection] = findMaxPath(graph, dp, node.connection, end, traveled);
        traveled[start] = false;
      }
      maxPath = max(maxPath, dp[node.connection] * node.probability);
    }

    return maxPath;
  }
};

int main()
{
  Solution solution;

  double result1 = solution.maxProbability(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{0, 2}}, vector<double>{.5, .5, .2}, 0, 2);
  double result2 = solution.maxProbability(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{0, 2}}, vector<double>{.5, .5, .3}, 0, 2);
  double result3 = solution.maxProbability(3, vector<vector<int>>{vector<int>{0, 1}}, vector<double>{.5}, 0, 2);
  double result4 = solution.maxProbability(4, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{0, 2}, vector<int>{0, 3}, vector<int>{1, 3}},
                                           vector<double>{.4, .5, .2, .5, .9}, 0, 2);
}