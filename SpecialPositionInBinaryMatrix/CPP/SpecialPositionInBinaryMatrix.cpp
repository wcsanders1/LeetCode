// https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2023-12-13
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int numSpecial(vector<vector<int>> &mat)
  {
    vector<int> rows(mat.size(), -1);
    vector<int> cols(mat[0].size(), -1);

    for (int row = 0; row < mat.size(); row++)
    {
      int pos = -1;
      for (int col = 0; col < mat[row].size(); col++)
      {
        if (mat[row][col] == 1)
        {
          if (pos == -1)
          {
            pos = col;
          }
          else
          {
            pos = -1;
            break;
          }
        }
      }
      rows[row] = pos;
    }

    for (int col = 0; col < mat[0].size(); col++)
    {
      int pos = -1;
      for (int row = 0; row < mat.size(); row++)
      {
        if (mat[row][col] == 1)
        {
          if (pos == -1)
          {
            pos = row;
          }
          else
          {
            pos = -1;
            break;
          }
        }
      }
      cols[col] = pos;
    }

    int answer = 0;
    for (int i = 0; i < rows.size(); i++)
    {
      if (rows[i] > -1 && cols[rows[i]] > -1)
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numSpecial(*new vector<vector<int>>{{1, 0, 0}, {0, 0, 1}, {1, 0, 0}});
  int result2 = solution.numSpecial(*new vector<vector<int>>{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
}