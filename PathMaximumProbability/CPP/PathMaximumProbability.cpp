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

    return findMaxPath(n, graph, start, end);
  }

private:
  double findMaxPath(int n, vector<vector<Node>> &graph, int start, int end)
  {
    vector<double> dp(n, 0);
    dp[start] = 1;
    vector<int> q{start};
    while (!q.empty())
    {
      vector<int> subQ;
      for (int n : q)
      {
        for (Node node : graph[n])
        {
          if (dp[node.connection] < dp[n] * node.probability)
          {
            dp[node.connection] = dp[n] * node.probability;
            subQ.push_back(node.connection);
          }
        }
      }
      swap(q, subQ);
    }

    return dp[end];
  }
};

int main()
{
  Solution solution;

  double result1 = solution.maxProbability(3, *new vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{0, 2}}, *new vector<double>{.5, .5, .2}, 0, 2);
  double result2 = solution.maxProbability(3, *new vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{0, 2}}, *new vector<double>{.5, .5, .3}, 0, 2);
  double result3 = solution.maxProbability(3, *new vector<vector<int>>{vector<int>{0, 1}}, *new vector<double>{.5}, 0, 2);
  double result4 = solution.maxProbability(4, *new vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{0, 2}, vector<int>{0, 3}, vector<int>{1, 3}},
                                           *new vector<double>{.4, .5, .2, .5, .9}, 0, 2);
}