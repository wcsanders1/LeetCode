// https://leetcode.com/problems/generate-parentheses/description/?envType=daily-question&envId=2026-10-02
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
  vector<string> generateParenthesis(int n)
  {
    vector<string> lst;
    for (int i = 1; i <= n; i++)
    {
      vector<string> nxt;
      string s = "";
      for (int j = 0; j < i; j++)
      {
        s += "()";
      }
      nxt.push_back(s);

      for (string &prev : lst)
      {
        string t = "";
        for (int x = 0; x < prev.size(); x++)
        {
          t += prev[x];
          if (prev[x] == '(')
          {
            nxt.push_back(t + "()" + prev.substr(x + 1));
          }
        }
      }

      lst = nxt;
    }

    unordered_set<string> st;
    for (string &s : lst)
    {
      st.insert(s);
    }

    vector<string> answer(st.begin(), st.end());
    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.generateParenthesis(3);
  auto result2 = solution.generateParenthesis(1);
}