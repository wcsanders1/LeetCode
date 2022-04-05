// https://leetcode.com/problems/swim-in-rising-water/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    distances[0][0] = grid[0][0];

    queue<vector<int>> q;
    q.emplace(vector<int>{0, 0});
    while (!q.empty())
    {
      vector<int> node = q.front();
      q.pop();

      int row = node[0];
      int col = node[1];
      int parentDistance = distances[row][col];

      if (row > 0)
      {
        int childDistance = distances[row - 1][col];
        int childValue = grid[row - 1][col];
        if (childDistance > childValue && childDistance > parentDistance)
        {
          distances[row - 1][col] = max(childValue, parentDistance);
          q.emplace(vector<int>{row - 1, col});
        }
      }

      if (row < grid.size() - 1)
      {
        int childDistance = distances[row + 1][col];
        int childValue = grid[row + 1][col];
        if (childDistance > childValue && childDistance > parentDistance)
        {
          distances[row + 1][col] = max(childValue, parentDistance);
          q.emplace(vector<int>{row + 1, col});
        }
      }

      if (col > 0)
      {
        int childDistance = distances[row][col - 1];
        int childValue = grid[row][col - 1];
        if (childDistance > childValue && childDistance > parentDistance)
        {
          distances[row][col - 1] = max(childValue, parentDistance);
          q.emplace(vector<int>{row, col - 1});
        }
      }

      if (col < grid[row].size() - 1)
      {
        int childDistance = distances[row][col + 1];
        int childValue = grid[row][col + 1];
        if (childDistance > childValue && childDistance > parentDistance)
        {
          distances[row][col + 1] = max(childValue, parentDistance);
          q.emplace(vector<int>{row, col + 1});
        }
      }
    }

    return distances[grid.size() - 1][grid[0].size() - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.swimInWater(vector<vector<int>>{
      vector<int>{0, 1, 2, 3, 4},
      vector<int>{24, 23, 22, 21, 5},
      vector<int>{12, 13, 14, 15, 16},
      vector<int>{11, 17, 18, 19, 20},
      vector<int>{10, 9, 8, 7, 6}});

  int result2 = solution.swimInWater(vector<vector<int>>{
      vector<int>{0, 2}, vector<int>{1, 3}});

  int result3 = solution.swimInWater(vector<vector<int>>{
      vector<int>{3, 2}, vector<int>{0, 1}});
}