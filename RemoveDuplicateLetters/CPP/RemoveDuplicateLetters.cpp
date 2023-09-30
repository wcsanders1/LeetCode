// https://leetcode.com/problems/remove-duplicate-letters/?envType=daily-question&envId=2023-09-26
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    int n = s.size();
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++)
    {
      m[s[i]] = i;
    }

    vector<bool> visited(n, false);
    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
      if (visited[s[i] - 'a'])
      {
        continue;
      }

      while (!stk.empty() && stk.top() > s[i] && m[stk.top()] > i)
      {
        visited[stk.top() - 'a'] = false;
        stk.pop();
      }

      stk.push(s[i]);
      visited[s[i] - 'a'] = true;
    }

    string answer = "";
    while (!stk.empty())
    {
      answer += stk.top();
      stk.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.removeDuplicateLetters("bcabc");
  string result2 = solution.removeDuplicateLetters("cdacdcbc");
}