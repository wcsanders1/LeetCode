#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int result = 0;
    vector<vector<int>> numMatrix;
    for (vector<char> row : matrix)
    {
      vector<int> numRow;
      for (char c : row)
      {
        int num = c == '0' ? 0 : 1;
        result = max(result, num);
        numRow.push_back(num);
      }
      numMatrix.push_back(numRow);
    }

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

    return result * result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'1', '0', '1', '0', '0'}, vector<char>{'1', '0', '1', '1', '1'}, vector<char>{'1', '1', '1', '1', '1'}, vector<char>{'1', '0', '0', '1', '0'}});
  int result2 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'0', '1'}, vector<char>{'1', '0'}});
  int result3 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'1', '1'}, vector<char>{'1', '1'}});
  int result4 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'1', '1', '1', '1', '1'}, vector<char>{'1', '1', '1', '1', '1'}, vector<char>{'0', '0', '0', '0', '0'}, vector<char>{'1', '1', '1', '1', '1'}, vector<char>{'1', '1', '1', '1', '1'}});
  int result5 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'1', '1', '1', '1', '0'}, vector<char>{'1', '1', '1', '1', '0'}, vector<char>{'1', '1', '1', '1', '1'}, vector<char>{'1', '1', '1', '1', '1'}, vector<char>{'0', '0', '1', '1', '1'}});
  int result6 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'0', '0', '0', '1'}, vector<char>{'1', '1', '0', '1'}, vector<char>{'1', '1', '1', '1'}, vector<char>{'0', '1', '1', '1'}, vector<char>{'0', '1', '1', '1'}});                                                                                               // 9
  int result7 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'1', '0', '1', '1', '0', '1'}, vector<char>{'1', '1', '1', '1', '1', '1'}, vector<char>{'0', '1', '1', '0', '1', '1'}, vector<char>{'1', '1', '1', '0', '1', '0'}, vector<char>{'0', '1', '1', '1', '1', '1'}, vector<char>{'1', '1', '0', '1', '1', '1'}}); // 4
  int result8 = solution.maximalSquare(*new vector<vector<char>>{vector<char>{'1', '1'}, vector<char>{'1', '1'}, vector<char>{'0', '1'}});                                                                                                                                                                                                 // 4
}