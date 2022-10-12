// https://leetcode.com/problems/open-the-lock/
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int openLock(vector<string> &deadends, string target)
  {
    unordered_set<string> visited(deadends.begin(), deadends.end());
    if (visited.find("0000") != visited.end())
    {
      return -1;
    }

    visited.insert("0000");
    queue<string> q;
    q.emplace("0000");
    int depth = 0;

    while (!q.empty())
    {
      int count = q.size();

      while (count-- > 0)
      {
        string value = q.front();
        q.pop();
        if (value == target)
        {
          return depth;
        }

        for (int i = 0; i < value.size(); i++)
        {
          string s = value;
          char c = s[i];
          s[i] = c == '9' ? '0' : c + 1;
          if (visited.find(s) == visited.end())
          {
            q.emplace(s);
            visited.insert(s);
          }

          s[i] = c == '0' ? '9' : c - 1;
          if (visited.find(s) == visited.end())
          {
            q.emplace(s);
            visited.insert(s);
          }
        }
      }
      depth++;
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.openLock(*new vector<string>{"0201", "0101", "0102", "1212", "2002"}, "0202");
  int result2 = solution.openLock(*new vector<string>{"8888"}, "0009");
  int result3 = solution.openLock(*new vector<string>{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888");
}