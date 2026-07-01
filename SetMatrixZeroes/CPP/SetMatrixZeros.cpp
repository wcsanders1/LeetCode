// https://leetcode.com/problems/set-matrix-zeroes/description/
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
  void setZeroes(vector<vector<int>> &matrix)
  {
    bool setFirstCol = false;
    bool setFirstRow = false;
    for (int row = 0; row < matrix.size(); row++)
    {
      for (int col = 0; col < matrix[0].size(); col++)
      {
        if (matrix[row][col] == 0)
        {
          if (row == 0)
          {
            setFirstRow = true;
          }
          else
          {
            matrix[row][0] = 0;
          }

          if (col == 0)
          {
            setFirstCol = true;
          }
          else
          {
            matrix[0][col] = 0;
          }
        }
      }
    }

    for (int col = 1; col < matrix[0].size(); col++)
    {
      if (matrix[0][col] == 0)
      {
        for (int row = 1; row < matrix.size(); row++)
        {
          matrix[row][col] = 0;
        }
      }
    }

    for (int row = 1; row < matrix.size(); row++)
    {
      if (matrix[row][0] == 0)
      {
        for (int col = 1; col < matrix[0].size(); col++)
        {
          matrix[row][col] = 0;
        }
      }
    }

    if (setFirstCol)
    {
      for (int row = 0; row < matrix.size(); row++)
      {
        matrix[row][0] = 0;
      }
    }

    if (setFirstRow)
    {
      for (int col = 0; col < matrix[0].size(); col++)
      {
        matrix[0][col] = 0;
      }
    }
  }
};

int main()
{
  Solution solution;

  auto matrix1 = vector<vector<int>>{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  solution.setZeroes(matrix1);

  auto matrix2 = vector<vector<int>>{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  solution.setZeroes(matrix2);
}