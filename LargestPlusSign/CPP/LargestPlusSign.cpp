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

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int row = 0; row < numMatrix.size(); row++)
    {
      for (int column = 0; column < numMatrix[row].size(); column++)
      {
        int num = numMatrix[row][column];
        result = max(result, num);

        if (row == 0 && column == 0)
        {
          dp[row][column][0] = 0;
          dp[row][column][1] = 0;
        }
        else if (row == 0)
        {
          dp[row][column][0] = num == 0 ? 0 : dp[row][column - 1][0] + num;
          dp[row][column][1] = 0;
        }
        else if (column == 0)
        {
          dp[row][column][0] = 0;
          dp[row][column][1] = num == 0 ? 0 : dp[row - 1][column][1] + num;
        }
        else
        {
          dp[row][column][0] = num == 0 ? 0 : dp[row][column - 1][0] + num;
          dp[row][column][1] = num == 0 ? 0 : dp[row - 1][column][1] + num;
        }
      }
    }

    if (n < 3)
    {
      return result;
    }

    for (int row = 1; row < numMatrix.size(); row++)
    {
      for (int column = 1; column < numMatrix[row].size(); column++)
      {
        int least = min(dp[row][column][0], dp[row][column][1]);
        while (least > result)
        {
          int advance = least - 1;
          if (advance + row >= n || advance + column >= n)
          {
            least--;
          }
          else
          {
          }
        }

        result = max(result, least);
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