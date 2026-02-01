// https://leetcode.com/problems/decode-ways/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int numDecodings(string s)
  {
    int n = s.size();
    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      dp[i] = s[i] == '0' ? 0 : 1;
      if (dp[i] > 0 && i < n - 1)
      {
        int num = stoi(s.substr(i, 2));
        if (num < 27)
        {
          if (i < n - 2)
          {
            dp[i] = dp[i + 1] + dp[i + 2];
          }
          else
          {
            dp[i] = dp[i + 1] + 1;
          }
        }
        else
        {
          dp[i] = dp[i + 1];
        }
      }
    }

    return dp[0];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numDecodings("12");
  int result2 = solution.numDecodings("226");
  int result3 = solution.numDecodings("06");
  int result4 = solution.numDecodings("1201234"); // 3
  int result5 = solution.numDecodings("10");      // 1
  int result6 = solution.numDecodings("1123");    // 5
  int result7 = solution.numDecodings("10011");   // 0
  int result8 = solution.numDecodings("2101");    // 1
  int result9 = solution.numDecodings("123123");  // 9
}