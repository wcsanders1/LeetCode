// https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

struct Edge
{
  int vert;
  int cost;
};

class Solution
{
public:
  vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
  {
    unordered_map<int, vector<Edge>> m;
    for (auto &edge : edges)
    {
      Edge e;
      e.vert = edge[1];
      e.cost = edge[2];
      m[edge[0]].push_back(e);

      Edge r;
      r.vert = edge[0];
      r.cost = edge[2];
      m[edge[1]].push_back(r);
    }

    vector<int> answer(edges.size() + 1, 0);
    for (int i = 0; i <= edges.size(); i++)
    {
      vector<vector<int>> conns;
      for (auto &edge : m[i])
      {
        vector<int> c;
        vector<bool> visited(edges.size() + 1, false);
        visited[i] = true;
        getConn(m, signalSpeed, edge.cost, edge.vert, c, visited);
        if (c.size() > 0)
        {
          conns.push_back(c);
        }
      }

      for (int x = 0; x < conns.size(); x++)
      {
        for (int y = x + 1; y < conns.size(); y++)
        {
          answer[i] += conns[x].size() * conns[y].size();
        }
      }
    }

    return answer;
  }

private:
  void getConn(unordered_map<int, vector<Edge>> &m, int signalSpeed, int currentSpeed, int currentVert, vector<int> &conns, vector<bool> &visited)
  {
    if (currentSpeed >= signalSpeed && currentSpeed % signalSpeed == 0)
    {
      conns.push_back(currentVert);
    }

    visited[currentVert] = true;

    for (auto &edge : m[currentVert])
    {
      if (!visited[edge.vert])
      {
        getConn(m, signalSpeed, edge.cost + currentSpeed, edge.vert, conns, visited);
      }
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.countPairsOfConnectableServers(*new vector<vector<int>>{{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}}, 1);
  auto result2 = solution.countPairsOfConnectableServers(*new vector<vector<int>>{{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}}, 3);
}