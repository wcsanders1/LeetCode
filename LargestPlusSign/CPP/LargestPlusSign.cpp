#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
  {
    if (n == 0)
    {
      return 0;
    }

    vector<vector<int>> numMatrix(n, vector<int>(n, 1));

    for (vector<int> mine : mines)
    {
      numMatrix[mine[0]][mine[1]] = 0;
    }

    int result = 0;
    vector<vector<int>> left(n, vector<int>(n, 0));
    vector<vector<int>> right(n, vector<int>(n, 0));
    vector<vector<int>> up(n, vector<int>(n, 0));
    vector<vector<int>> down(n, vector<int>(n, 0));

    for (int row = 0; row < n; row++)
    {
      for (int column = 0; column < n; column++)
      {
        right[row][column] = (column == 0 || numMatrix[row][column] == 0) ? numMatrix[row][column] : numMatrix[row][column] + right[row][column - 1];
        left[row][(n - 1) - column] = (column == 0 || numMatrix[row][(n - 1) - column] == 0) ? numMatrix[row][(n - 1) - column] : numMatrix[row][(n - 1) - column] + left[row][n - column];
        down[row][column] = (row == 0 || numMatrix[row][column] == 0) ? numMatrix[row][column] : numMatrix[row][column] + down[row - 1][column];
        up[(n - 1) - row][column] = (row == 0 || numMatrix[(n - 1) - row][column] == 0) ? numMatrix[(n - 1) - row][column] : numMatrix[(n - 1) - row][column] + up[n - row][column];
      }
    }

    for (int row = 0; row < numMatrix.size(); row++)
    {
      for (int column = 0; column < numMatrix[row].size(); column++)
      {
        int tempResult = min(right[row][column], min(left[row][column], min(up[row][column], down[row][column])));
        result = max(result, tempResult);
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.orderOfLargestPlusSign(5, *new vector<vector<int>>{vector<int>{4, 2}});                                       // 2
  int result2 = solution.orderOfLargestPlusSign(1, *new vector<vector<int>>{vector<int>{0, 0}});                                       // 0
  int result3 = solution.orderOfLargestPlusSign(2, *new vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 0}, vector<int>{1, 1}}); // 1
  int result4 = solution.orderOfLargestPlusSign(2, *new vector<vector<int>>{vector<int>{0, 0}, vector<int>{1, 1}});                    // 1
  int result5 = solution.orderOfLargestPlusSign(3, *new vector<vector<int>>{vector<int>{0, 0}});                                       // 2
  int result6 = solution.orderOfLargestPlusSign(3, *new vector<vector<int>>{vector<int>{0, 1}});                                       // 1
}