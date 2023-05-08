// https://leetcode.com/problems/matrix-diagonal-sum/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int diagonalSum(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int answer = 0;

    for (int row = 0, end = n - 1; row < n && end >= 0; row++, end--)
    {
      answer += mat[row][row];
      if (row != end)
      {
        answer += mat[row][end];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.diagonalSum(*new vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  int result2 = solution.diagonalSum(*new vector<vector<int>>{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}});
  int result3 = solution.diagonalSum(*new vector<vector<int>>{{5}});
  int result4 = solution.diagonalSum(*new vector<vector<int>>{{7, 3, 1, 9}, {3, 4, 6, 9}, {6, 9, 6, 6}, {9, 5, 8, 5}});
}