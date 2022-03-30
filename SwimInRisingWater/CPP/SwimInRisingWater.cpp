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
    unordered_map<int, vector<vector<int>>> graph;
    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[row].size(); col++)
      {
        int num = grid[row][col];
        graph[num] = vector<vector<int>>(0);

        if (row > 0)
        {
          int nextNum = grid[row - 1][col];
          graph[num].push_back(vector<int>{nextNum, nextNum == 0 ? 0 : INT_MAX});
        }

        if (row < grid.size() - 1)
        {
          int nextNum = grid[row + 1][col];
          graph[num].push_back(vector<int>{nextNum, nextNum == 0 ? 0 : INT_MAX});
        }

        if (col > 0)
        {
          int nextNum = grid[row][col - 1];
          graph[num].push_back(vector<int>{nextNum, nextNum == 0 ? 0 : INT_MAX});
        }

        if (col < grid[row].size() - 1)
        {
          int nextNum = grid[row][col + 1];
          graph[num].push_back(vector<int>{nextNum, nextNum == 0 ? 0 : INT_MAX});
        }
      }
    }

    queue<vector<vector<int>> *> q;
    q.emplace(graph[0]);
    while (!q.empty())
    {
      vector<vector<int>> *node = q.front();
      q.pop();
      for (vector<int> n : *node)
      {
            }
    }
  }
};