// https://leetcode.com/problems/remove-k-digits/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    if (k == num.size())
    {
      return "0";
    }

    stack<char> s;
    s.push(num[0]);

    int i = 1;
    for (; i < num.size() && k > 0; i++)
    {
      char n = num[i];
      while (!s.empty() && n < s.top() && k > 0)
      {
        s.pop();
        k--;
      }
      s.push(n);
    }

    for (; i < num.size(); i++)
    {
      s.push(num[i]);
    }

    while (k-- > 0 && s.size() > 1)
    {
      s.pop();
    }

    stack<char> r;
    while (!s.empty())
    {
      r.push(s.top());
      s.pop();
    }

    string answer;
    while (r.size() > 1 && r.top() == '0')
    {
      r.pop();
    }

    while (!r.empty())
    {
      answer += r.top();
      r.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.removeKdigits("1432219", 3); // 1219
  string result2 = solution.removeKdigits("10200", 1);   // 200
  string result3 = solution.removeKdigits("10", 2);      // 0
  string result4 = solution.removeKdigits("112", 1);     // 11
}