// https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land)
  {
    vector<vector<int>> answer;
    int rows = land.size();
    int cols = land[0].size();
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        if (land[row][col] == 1)
        {
          vector<int> end = getEnd(land, row, col);
          answer.push_back({row, col, end[0], end[1]});
        }
      }
    }

    return answer;
  }

private:
  vector<int> getEnd(vector<vector<int>> &land, int startRow, int startCol)
  {
    int rows = land.size();
    int cols = land[0].size();
    int endRow = startRow;
    int endCol = startCol;

    while (endCol < cols - 1 && land[startRow][endCol + 1] == 1)
    {
      endCol++;
    }

    while (endRow < rows - 1 && land[endRow + 1][startCol] == 1)
    {
      endRow++;
    }

    for (int row = startRow; row <= endRow; row++)
    {
      for (int col = startCol; col <= endCol; col++)
      {
        land[row][col] = 0;
      }
    }

    return {endRow, endCol};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findFarmland(*new vector<vector<int>>{{1, 0, 0}, {0, 1, 1}, {0, 1, 1}});
  auto result2 = solution.findFarmland(*new vector<vector<int>>{{1, 1}, {1, 1}});
  auto result3 = solution.findFarmland(*new vector<vector<int>>{{0}});
  auto result4 = solution.findFarmland(*new vector<vector<int>>{{0}, {0}, {1}, {1}, {1}, {0}, {1}, {1}});
}