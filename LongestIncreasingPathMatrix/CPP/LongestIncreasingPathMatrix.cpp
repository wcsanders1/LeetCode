#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    int answer = 0;
    if (matrix.size() == 0)
    {
      return answer;
    }

    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

    for (int row = 0; row < matrix.size(); row++)
    {
      for (int column = 0; column < matrix[row].size(); column++)
      {
        if (dp[row][column] == -1)
        {
          getGreatestIncrease(matrix, dp, row, column);
        }

        answer = max(answer, dp[row][column]);
      }
    }

    return answer;
  }

private:
  void getGreatestIncrease(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row, int column)
  {
    int greatestIncrease = 1;
    int num = matrix[row][column];
    if (column > 0 && matrix[row][column - 1] > num)
    {
      if (dp[row][column - 1] == -1)
      {
        getGreatestIncrease(matrix, dp, row, column - 1);
      }
      greatestIncrease = max(greatestIncrease, dp[row][column - 1] + 1);
    }

    if (column < matrix[row].size() - 1 && matrix[row][column + 1] > num)
    {
      if (dp[row][column + 1] == -1)
      {
        getGreatestIncrease(matrix, dp, row, column + 1);
      }
      greatestIncrease = max(greatestIncrease, dp[row][column + 1] + 1);
    }

    if (row > 0 && matrix[row - 1][column] > num)
    {
      if (dp[row - 1][column] == -1)
      {
        getGreatestIncrease(matrix, dp, row - 1, column);
      }
      greatestIncrease = max(greatestIncrease, dp[row - 1][column] + 1);
    }

    if (row < matrix.size() - 1 && matrix[row + 1][column] > num)
    {
      if (dp[row + 1][column] == -1)
      {
        getGreatestIncrease(matrix, dp, row + 1, column);
      }
      greatestIncrease = max(greatestIncrease, dp[row + 1][column] + 1);
    }
    dp[row][column] = greatestIncrease;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestIncreasingPath(vector<vector<int>>{vector<int>{9, 9, 4}, vector<int>{6, 6, 8}, vector<int>{2, 1, 1}});
  int result2 = solution.longestIncreasingPath(vector<vector<int>>{vector<int>{3, 4, 5}, vector<int>{3, 2, 6}, vector<int>{2, 2, 1}});
  int result3 = solution.longestIncreasingPath(vector<vector<int>>{vector<int>{1, 2}});
}