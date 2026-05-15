// https://leetcode.com/problems/pacific-atlantic-water-flow/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
    queue<vector<int>> pacificq;
    queue<vector<int>> atlanticq;

    for (int c = 0; c < cols; c++)
    {
      pacific[0][c] = true;
      atlantic[rows - 1][c] = true;
      pacificq.push({0, c});
      atlanticq.push({rows - 1, c});
    }

    for (int r = 0; r < rows; r++)
    {
      pacific[r][0] = true;
      atlantic[r][cols - 1] = true;
      pacificq.push({r, 0});
      atlanticq.push({r, cols - 1});
    }

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while (!pacificq.empty())
    {
      auto cur = pacificq.front();
      pacificq.pop();
      for (auto dir : directions)
      {
        int x = cur[0] + dir[0];
        int y = cur[1] + dir[1];
        if (x >= 0 && x < rows && y >= 0 && y < cols)
        {
          if (heights[x][y] >= heights[cur[0]][cur[1]] && !pacific[x][y])
          {
            pacific[x][y] = true;
            pacificq.push({x, y});
          }
        }
      }
    }

    while (!atlanticq.empty())
    {
      auto cur = atlanticq.front();
      atlanticq.pop();
      for (auto dir : directions)
      {
        int x = cur[0] + dir[0];
        int y = cur[1] + dir[1];
        if (x >= 0 && x < rows && y >= 0 && y < cols)
        {
          if (heights[x][y] >= heights[cur[0]][cur[1]] && !atlantic[x][y])
          {
            atlantic[x][y] = true;
            atlanticq.push({x, y});
          }
        }
      }
    }

    vector<vector<int>> answer;
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        if (pacific[r][c] && atlantic[r][c])
        {
          answer.push_back({r, c});
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.pacificAtlantic(*new vector<vector<int>>{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}});
  auto result2 = solution.pacificAtlantic(*new vector<vector<int>>{{1}});
  auto result3 = solution.pacificAtlantic(*new vector<vector<int>>{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
}