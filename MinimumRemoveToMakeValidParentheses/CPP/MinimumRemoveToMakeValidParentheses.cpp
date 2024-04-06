// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    int openeds = 0;
    stack<int> indeces;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        indeces.push(i);
        openeds++;
      }

      if (s[i] == ')')
      {
        if (openeds == 0)
        {
          s[i] = ' ';
        }
        else
        {
          openeds--;
        }
      }
    }

    while (openeds-- > 0)
    {
      s[indeces.top()] = ' ';
      indeces.pop();
    }

    string answer;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != ' ')
      {
        answer += s[i];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.minRemoveToMakeValid("lee(t(c)o)de)");
  string result2 = solution.minRemoveToMakeValid("a)b(c)d");
  string result3 = solution.minRemoveToMakeValid("))((");
}