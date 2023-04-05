// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
// NOT MINE: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/editorial/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  int ways(vector<string> &pizza, int k)
  {
    int rows = pizza.size();
    int cols = pizza[0].size();
    vector<vector<int>> appleSums(rows + 1, vector<int>(cols + 1, 0));
    vector<vector<vector<int>>> dp(k, vector<vector<int>>(rows, vector<int>(cols, 0)));
    for (int row = rows - 1; row >= 0; row--)
    {
      for (int col = cols - 1; col >= 0; col--)
      {
        appleSums[row][col] = (pizza[row][col] == 'A') + appleSums[row + 1][col] + appleSums[row][col + 1] - appleSums[row + 1][col + 1];
        dp[0][row][col] = appleSums[row][col] > 0;
      }
    }

    const int mod = 1000000007;
    for (int remain = 1; remain < k; remain++)
    {
      for (int row = 0; row < rows; row++)
      {
        for (int col = 0; col < cols; col++)
        {
          for (int nextRow = row + 1; nextRow < rows; nextRow++)
          {
            if (appleSums[row][col] - appleSums[nextRow][col] > 0)
            {
              (dp[remain][row][col] += dp[remain - 1][nextRow][col]) %= mod;
            }
          }

          for (int nextCol = col + 1; nextCol < cols; nextCol++)
          {
            if (appleSums[row][col] - appleSums[row][nextCol] > 0)
            {
              (dp[remain][row][col] += dp[remain - 1][row][nextCol]) %= mod;
            }
          }
        }
      }
    }

    return dp[k - 1][0][0];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.ways(*new vector<string>{"A..", "AAA", "..."}, 3);                         // 3
  int result2 = solution.ways(*new vector<string>{"A..", "AA.", "..."}, 3);                         // 1
  int result3 = solution.ways(*new vector<string>{"A..", "A..", "..."}, 1);                         // 1
  int result4 = solution.ways(*new vector<string>{".A..A", "A.A..", "A.AA.", "AAAA.", "A.AA."}, 5); // 153
}