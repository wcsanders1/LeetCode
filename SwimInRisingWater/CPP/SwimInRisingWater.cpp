// https://leetcode.com/problems/swim-in-rising-water/
#include <vector>

using namespace std;

class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    distances[0][0] = 0;

    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[row].size(); col++)
      {
        if (row == 0 && col == 0)
        {
          continue;
        }

        int cost = grid[row][col];

        if (row > 0)
        {
          int sourceCost = grid[row - 1][col];
          distances[row][col] = min(distances[row][col], cost + sourceCost);
        }

        if (row < grid.size() - 1)
        {
          int sourceCost = grid[row + 1][col];
          distances[row][col] = min(distances[row][col], cost + sourceCost);
        }

        if (col > 0)
        {
          int sourceCost = grid[row][col - 1];
          distances[row][col] = min(distances[row][col], cost + sourceCost);
        }

        if (col < grid[row].size() - 1)
        {
          int sourceCost = grid[row][col + 1];
          distances[row][col] = min(distances[row][col], cost + sourceCost);
        }
      }
    }
  }
};