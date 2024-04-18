// https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int answer = 0;
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        if (grid[row][col] == 1)
        {
          for (auto &d : directions)
          {
            int nextRow = row + d[0];
            int nextCol = col + d[1];
            if (nextRow < 0 || nextCol < 0 || nextRow >= rows || nextCol >= cols || grid[nextRow][nextCol] == 0)
            {
              answer++;
            }
          }
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.islandPerimeter(*new vector<vector<int>>{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}});
  int result2 = solution.islandPerimeter(*new vector<vector<int>>{{1}});
  int result3 = solution.islandPerimeter(*new vector<vector<int>>{{1, 0}});
}