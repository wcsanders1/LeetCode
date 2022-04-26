// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
#include <vector>

using namespace std;

struct Point
{
  int Column;
  int Row;
};

class Solution
{
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
  {
  }

private:
  int getLargest(vector<vector<int>> &matrix)
  {
    int largest = 0;
    vector<vector<int>> prior;

    for (int row = 0; row < matrix.size(); row++)
    {
      for (int col = 0; col < matrix[row].size(); col++)
      {
        int total = 0;
        for (int i = col; i < matrix[row].size(); i++)
        {
          total += matrix[row][i];
          if (row == 0)
          {
            prior.push_back({col, i, total});
            largest = max(largest, total);
          }
          else
          {
            // check dp
          }
        }
      }
    }
  }
};