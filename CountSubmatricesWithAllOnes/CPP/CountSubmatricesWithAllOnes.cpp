// https://leetcode.com/problems/count-submatrices-with-all-ones/
// NOT MINE: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/720265/Java-Detailed-Explanation-From-O(MNM)-to-O(MN)-by-using-Stack
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int numSubmat(vector<vector<int>> &mat)
  {
    int answer = 0;

    vector<int> temp = vector<int>(mat[0].size(), 0);

    for (int row = 0; row < mat.size(); row++)
    {
      for (int col = 0; col < mat[0].size(); col++)
      {
        temp[col] = mat[row][col] == 0 ? 0 : temp[col] + 1;
      }

      answer += calculate(temp);
    }

    return answer;
  }

private:
  int calculate(vector<int> &row)
  {
    vector<int> sum = vector<int>(row.size(), 0);
    stack<int> s;

    for (int col = 0; col < row.size(); col++)
    {
      while (!s.empty() && row[s.top()] >= row[col])
      {
        s.pop();
      }

      if (!s.empty())
      {
        int preIndex = s.top();
        sum[col] = sum[preIndex];
        sum[col] += row[col] * (col - preIndex);
      }
      else
      {
        sum[col] = row[col] * (col + 1);
      }

      s.push(col);
    }

    int result = 0;
    for (int s : sum)
    {
      result += s;
    }

    return result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numSubmat(*new vector<vector<int>>{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}});
  int result2 = solution.numSubmat(*new vector<vector<int>>{{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}});
}