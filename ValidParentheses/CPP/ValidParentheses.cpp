// https://leetcode.com/problems/valid-parentheses/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;

    for (char &c : s)
    {
      if (c == '(' || c == '{' || c == '[')
      {
        st.push(c);
      }
      else if (st.empty())
      {
        return false;
      }
      else
      {
        char prev = st.top();
        st.pop();

        if (c == ')' && prev != '(')
        {
          return false;
        }

        if (c == '}' && prev != '{')
        {
          return false;
        }

        if (c == ']' && prev != '[')
        {
          return false;
        }
      }
    }

    return st.empty();
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isValid("()");
  bool result2 = solution.isValid("()[]{}");
  bool result3 = solution.isValid("(]");
}