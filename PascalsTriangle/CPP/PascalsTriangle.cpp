#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> result;

    for (int i = 0; i < numRows; i++)
    {
      if (i == 0)
      {
        result.push_back(vector<int>{1});
        continue;
      }

      vector<int> newRow;
      for (int j = 0; j <= i; j++)
      {
        if (j == 0)
        {
          newRow.push_back(result[i - 1][0]);
        }
        else if (j == i)
        {
          newRow.push_back(result[i - 1][j - 1]);
        }
        else
        {
          newRow.push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }

      result.push_back(newRow);
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> result1 = solution.generate(5);
  vector<vector<int>> result2 = solution.generate(1);
}