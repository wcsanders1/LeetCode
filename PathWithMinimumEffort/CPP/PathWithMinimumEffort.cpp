// https://leetcode.com/problems/path-with-minimum-effort/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int minimumEffortPath(vector<vector<int>> &heights)
  {
    vector<vector<int>> efforts(heights.size(), vector<int>(heights[0].size(), INT_MAX));
    efforts[0][0] = heights[0][0];
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<vector<int>> q;
    q.emplace(vector<int>{0, 0});
    while (!q.empty())
    {
      vector<int> node = q.front();
      q.pop();

      int height = heights[node[0]][node[1]];
      for (vector<int> direction : directions)
      {
      }
    }

    return efforts[efforts.size() - 1][efforts[0].size() - 1];
  }
};