// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int countNegatives(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();

    int positives = 0;
    int col = 0;
    int row = rows - 1;

    while (row >= 0)
    {
      while (col < cols && grid[row][col] >= 0)
      {
        col++;
      }
      row--;
      positives += col;
    }

    return (rows * cols) - positives;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countNegatives(*new vector<vector<int>>{{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}});
  int result2 = solution.countNegatives(*new vector<vector<int>>{{3, 2}, {1, 0}});
}