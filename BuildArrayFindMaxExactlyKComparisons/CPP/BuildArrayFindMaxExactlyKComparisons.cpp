// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/?envType=daily-question&envId=2023-10-07
// NOT MINE: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/solutions/586576/c-bottom-up-dynamic-programming-with-explanation/?envType=daily-question&envId=2023-10-07
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int numOfArrays(int n, int m, int k)
  {
    int mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));

    for (int j = 1; j <= m; j++)
    {
      dp[1][j][1] = 1;
    }

    for (int a = 1; a <= n; a++)
    {
      for (int b = 1; b <= m; b++)
      {
        for (int c = 1; c <= k; c++)
        {
          long long s = (b * dp[a - 1][b][c]) % mod;
          for (int x = 1; x < b; x++)
          {
            s = (s + dp[a - 1][x][c - 1]) % mod;
          }

          dp[a][b][c] = (dp[a][b][c] + s) % mod;
        }
      }
    }

    long long answer = 0;
    for (int j = 1; j <= m; j++)
    {
      answer = (answer + dp[n][j][k]) % mod;
    }

    return (int)answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numOfArrays(2, 3, 1);
  int result2 = solution.numOfArrays(5, 2, 3);
  int result3 = solution.numOfArrays(9, 1, 1);
  int result4 = solution.numOfArrays(1, 2, 2);
}