// https://leetcode.com/problems/longest-palindromic-subsequence/description/
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
  int longestPalindromeSubseq(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int col = 1; col <= n; col++)
    {
      int reverseIndex = n - 1;
      for (int row = 1; row <= n; row++)
      {
        if (s[col - 1] == s[reverseIndex--])
        {
          dp[col][row] = dp[col - 1][row - 1] + 1;
        }
        else
        {
          dp[col][row] = max(dp[col - 1][row], dp[col][row - 1]);
        }
      }
    }

    return dp[n][n];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestPalindromeSubseq("bbbab");
  int result2 = solution.longestPalindromeSubseq("cbbd");
}