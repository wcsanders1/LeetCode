// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> directions{-1, 0, 1};
    for (int row = rows - 2; row >= 0; row--)
    {
      for (int col = 0; col < cols; col++)
      {
        int cur = matrix[row][col];
        int _min = INT32_MAX;
        for (int d : directions)
        {
          int next = col + d;
          if (next >= 0 && next < cols)
          {
            _min = min(_min, cur + matrix[row + 1][next]);
          }
        }
        matrix[row][col] = _min;
      }
    }

    int answer = INT32_MAX;
    for (int col = 0; col < cols; col++)
    {
      answer = min(answer, matrix[0][col]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minFallingPathSum(*new vector<vector<int>>{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}});
  int result2 = solution.minFallingPathSum(*new vector<vector<int>>{{-19, 57}, {-40, -5}});
}