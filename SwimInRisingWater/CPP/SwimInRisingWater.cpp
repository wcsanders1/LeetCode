// https://leetcode.com/problems/swim-in-rising-water/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    unordered_map<int, vector<int>> graph;
    vector<int> distances(grid.size() * grid[0].size(), INT_MAX);
    distances[0] = 0;

    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[row].size(); col++)
      {
        int num = grid[row][col];
        graph[num] = vector<int>(0);

        if (row > 0)
        {
          int nextNum = grid[row - 1][col];
          graph[num].push_back(nextNum);
        }

        if (row < grid.size() - 1)
        {
          int nextNum = grid[row + 1][col];
          graph[num].push_back(nextNum);
        }

        if (col > 0)
        {
          int nextNum = grid[row][col - 1];
          graph[num].push_back(nextNum);
        }

        if (col < grid[row].size() - 1)
        {
          int nextNum = grid[row][col + 1];
          graph[num].push_back(nextNum);
        }
      }
    }

    queue<pair<int, vector<int>>> q;
    q.emplace(pair<int, vector<int>>(0, graph[0]));
    while (!q.empty())
    {
      auto const &[source, nodes] = q.front();
      q.pop();

      for (int node : nodes)
      {
      }
    }
  }
};