// https://leetcode.com/problems/range-sum-query-2d-immutable/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class NumMatrix
{
public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    sums = vector<vector<vector<vector<int>>>>(rows, vector<vector<vector<int>>>(cols, vector<vector<int>>(rows, vector<int>(cols))));
    for (int startRow = 0; startRow < rows; startRow++)
    {
      for (int endRow = startRow; endRow < rows; endRow++)
      {
        for (int startCol = 0; startCol < cols; startCol++)
        {
          for (int endCol = startCol, rowTotal = 0; endCol < cols; endCol++)
          {
            rowTotal += matrix[endRow][endCol];
            if (startRow == endRow)
            {
              if (startCol == endCol)
              {
                sums[startRow][startCol][endRow][endCol] = matrix[startRow][startCol];
              }
              else
              {
                sums[startRow][startCol][endRow][endCol] = sums[startRow][startCol][endRow][endCol - 1] + matrix[startRow][endCol];
              }
            }
            else if (startCol == endCol)
            {
              sums[startRow][startCol][endRow][endCol] = sums[startRow][startCol][endRow - 1][endCol] + matrix[endRow][startCol];
            }
            else
            {
              sums[startRow][startCol][endRow][endCol] = sums[startRow][startCol][endRow - 1][endCol] + rowTotal;
            }
          }
        }
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sums[row1][col1][row2][col2];
  }

private:
  vector<vector<vector<vector<int>>>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
  auto matrix = new NumMatrix(*new vector<vector<int>>{
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}});

  int result1 = matrix->sumRegion(2, 1, 4, 3);
  int result2 = matrix->sumRegion(1, 1, 2, 2);
  int result3 = matrix->sumRegion(1, 2, 2, 4);
}