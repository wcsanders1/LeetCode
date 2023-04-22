// https://leetcode.com/problems/maximum-width-of-binary-tree/
// NOT MINE: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/solutions/470706/java-c-python-longest-common-sequence/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int minInsertions(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int col = 0; col < n; col++)
    {
      for (int row = 0; row < n; row++)
      {
        dp[col + 1][row + 1] = s[col] == s[n - 1 - row] ? dp[col][row] + 1 : max(dp[col][row + 1], dp[col + 1][row]);
      }
    }

    return n - dp[n][n];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minInsertions("zzazz");
  int result2 = solution.minInsertions("mbadm");
  int result3 = solution.minInsertions("leetcode");
  int result4 = solution.minInsertions("tldjbqjdogipebqsohdypcxjqkrqltpgviqtqz");
}