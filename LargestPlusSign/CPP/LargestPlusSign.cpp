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

    for (int row = 1; row < numMatrix.size(); row++)
    {
      for (int column = 1; column < numMatrix[row].size(); column++)
      {
        int current = numMatrix[row][column];
        int above = numMatrix[row - 1][column];
        int left = numMatrix[row][column - 1];
        int aboveLeft = numMatrix[row - 1][column - 1];

        int least = min(above, min(left, aboveLeft));

        if (current > 0)
        {
          numMatrix[row][column] = current + least;
        }

        result = max(result, numMatrix[row][column]);
      }
    }

    result = max(result, numMatrix[numMatrix.size() - 1][numMatrix[0].size() - 1]);

    int rem = result % 2;

    return (result / 2) + rem;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.orderOfLargestPlusSign(5, *new vector<vector<int>>{vector<int>{4, 2}});                                       // 2
  // int result2 = solution.orderOfLargestPlusSign(1, *new vector<vector<int>>{vector<int>{0, 0}});                                       // 0
  // int result3 = solution.orderOfLargestPlusSign(2, *new vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 0}, vector<int>{1, 1}}); // 1
  int result4 = solution.orderOfLargestPlusSign(2, *new vector<vector<int>>{vector<int>{0, 0}, vector<int>{1, 1}}); // 1
}