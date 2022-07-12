// https://leetcode.com/problems/convert-1d-array-into-2d-array/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    if (m * n != original.size())
    {
      return vector<vector<int>>(0);
    }

    vector<vector<int>> answer;
    for (int row = 0; row < m; row++)
    {
      vector<int> newRow;
      for (int col = 0; col < n; col++)
      {
        int index = col + (row * n);
        newRow.push_back(original[index]);
      }

      answer.push_back(newRow);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.construct2DArray(*new vector<int>{1, 2, 3, 4}, 2, 2);
  auto result2 = solution.construct2DArray(*new vector<int>{1, 2, 3}, 1, 3);
  auto result3 = solution.construct2DArray(*new vector<int>{1, 2}, 1, 1);
}