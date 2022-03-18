// https://leetcode.com/problems/path-with-maximum-probability/
#include <vector>
#include <string>

using namespace std;

struct Node
{
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
    vector<vector<Node>> graph(n, vector<Node>(0));
    for (int i = 0; i < edges.size(); i++)
    {
      vector<int> edge = edges[i];
      double probability = succProb[i];
      graph[edge[0]].push_back(Node(edge[1], probability));
      graph[edge[1]].push_back(Node(edge[0], probability));
    }

    vector<double> dp(n, -1);
    double maxPath = findMaxPath(graph, dp, start, end);

    return maxPath;
  }

private:
  double findMaxPath(vector<vector<Node>> &graph, vector<double> &dp, int start, int end)
  {
    double maxPath = 0;
    for (Node node : graph[start])
    {
      if (node.connection == end)
      {
        maxPath = max(maxPath, node.probability);
      }
      else if (dp[node.connection] != -1)
      {
        dp[node.connection] = findMaxPath(graph, dp, node.connection, end);
        maxPath = max(maxPath, dp[node.connection]);
      }
    }

    return maxPath;
  }
};