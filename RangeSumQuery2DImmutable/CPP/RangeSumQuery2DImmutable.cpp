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
    sums = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

    for (int row = 1; row <= rows; row++)
    {
      int rowTotal = 0;
      for (int col = 1; col <= cols; col++)
      {
        rowTotal += matrix[row - 1][col - 1];
        sums[row][col] = sums[row - 1][col] + rowTotal;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int total = sums[row2 + 1][col2 + 1];
    int topRemove = sums[row1][col2 + 1];
    int leftRemove = sums[row2 + 1][col1];
    int dup = sums[row1][col1];

    return total - ((topRemove + leftRemove) - dup);
  }

private:
  vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
  auto matrix1 = new NumMatrix(*new vector<vector<int>>{
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}});

  int result1 = matrix1->sumRegion(2, 1, 4, 3);
  int result2 = matrix1->sumRegion(1, 1, 2, 2);
  int result3 = matrix1->sumRegion(1, 2, 2, 4);

  auto matrix2 = new NumMatrix(*new vector<vector<int>>{{1}, {-7}});

  int result4 = matrix2->sumRegion(0, 0, 0, 0);
  int result5 = matrix2->sumRegion(1, 0, 1, 0);
  int result6 = matrix2->sumRegion(0, 0, 1, 0);
}