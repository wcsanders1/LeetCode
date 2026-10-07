// https://leetcode.com/problems/score-of-parentheses/description/?envType=daily-question&envId=2026-10-05
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
  int scoreOfParentheses(string s)
  {
    return score(0, s.size() - 1, s);
  }

private:
  int score(int start, int end, string &s)
  {
    int lefts = 0;
    int total = 0;
    int begin = start;
    for (int i = start; i <= end; i++)
    {
      if (s[i] == '(')
      {
        lefts++;
      }
      else
      {
        if (--lefts == 0)
        {
          if (i - begin == 1)
          {
            total++;
          }
          else
          {
            total += 2 * score(begin + 1, i - 1, s);
          }
          begin = i + 1;
        }
      }
    }
    return total;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.scoreOfParentheses("()");
  int result2 = solution.scoreOfParentheses("(())");
  int result3 = solution.scoreOfParentheses("()()");
  int result4 = solution.scoreOfParentheses("(()(()))"); // 6
}