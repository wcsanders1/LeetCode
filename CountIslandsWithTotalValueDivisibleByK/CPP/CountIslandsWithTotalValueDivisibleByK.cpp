// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/?envType=daily-question&envId=2026-10-26
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int countIslands(vector<vector<int>> &grid, int k)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<long long> islands;
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        if (grid[row][col] > 0)
        {
          islands.push_back(getIsland(grid, row, col));
        }
      }
    }

    int answer = 0;
    for (long long i : islands)
    {
      if (i % k == 0)
      {
        answer++;
      }
    }

    return answer;
  }

private:
  vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  long long getIsland(vector<vector<int>> &grid, int row, int col)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0)
    {
      return 0;
    }

    long long island = grid[row][col];
    grid[row][col] = 0;
    for (auto &d : directions)
    {
      island += getIsland(grid, row + d[0], col + d[1]);
    }

    return island;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countIslands(*new vector<vector<int>>{{0, 2, 1, 0, 0}, {0, 5, 0, 0, 5}, {0, 0, 1, 0, 0}, {0, 1, 4, 7, 0}, {0, 2, 0, 0, 8}}, 5);
  int result2 = solution.countIslands(*new vector<vector<int>>{{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}}, 3);
}