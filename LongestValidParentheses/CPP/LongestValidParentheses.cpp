// https://leetcode.com/problems/longest-valid-parentheses/description/?envType=daily-question&envId=2026-10-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int n = s.size();
    vector<int> dp(n, 0);
    stack<int> stk;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      char c = s[i];
      if (c == ')')
      {
        if (!stk.empty())
        {
          int idx = max(0, stk.top() - 1);
          dp[i] = dp[idx] + dp[i - 1] + 2;
          mx = max(mx, dp[i]);
          stk.pop();
        }
      }
      else
      {
        stk.push(i);
      }
    }

    return mx;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestValidParentheses("(()");
  int result2 = solution.longestValidParentheses(")()())");
  int result3 = solution.longestValidParentheses("");
  int result4 = solution.longestValidParentheses("((()))");
  int result5 = solution.longestValidParentheses("(()())");
  int result6 = solution.longestValidParentheses("()");
  int result7 = solution.longestValidParentheses("()(())");
  int result8 = solution.longestValidParentheses("()(()");
}