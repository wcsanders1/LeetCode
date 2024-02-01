// https://leetcode.com/problems/string-compression-ii/?envType=daily-question&envId=2023-12-28
// NOT MINE: https://leetcode.com/problems/string-compression-ii/solutions/757506/detailed-explanation-two-ways-of-dp-from-33-to-100/?envType=daily-question&envId=2023-12-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int getLengthOfOptimalCompression(string s, int k)
  {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT32_MAX));
    for (int i = 0; i <= k; i++)
    {
      dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= k; j++)
      {
        if (j > 0)
        {
          dp[i][j] = dp[i - 1][j - 1];
        }

        int removed = 0;
        int cnt = 0;
        for (int p = i; p > 0; p--)
        {
          if (s[p - 1] == s[i - 1])
          {
            cnt++;
          }
          else if (++removed > j)
          {
            break;
          }

          dp[i][j] = min(dp[i][j], dp[p - 1][j - removed] + getCount(cnt));
        }
      }
    }

    return dp[n][k];
  }

private:
  int getCount(int len)
  {
    if (len == 0)
    {
      return 0;
    }
    if (len == 1)
    {
      return 1;
    }
    if (len < 10)
    {
      return 2;
    }
    if (len < 100)
    {
      return 3;
    }
    return 4;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.getLengthOfOptimalCompression("aaabcccd", 2);
  // int result2 = solution.getLengthOfOptimalCompression("aabbaa", 2);
  // int result3 = solution.getLengthOfOptimalCompression("aaaaaaaaaaa", 0);
  int result4 = solution.getLengthOfOptimalCompression("aaa", 3);
}