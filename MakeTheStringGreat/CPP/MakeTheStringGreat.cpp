// https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  string makeGood(string s)
  {
    queue<char> q1;
    queue<char> q2;
    for (char &c : s)
    {
      q1.push(c);
    }

    int diffs = INT32_MAX;
    while (diffs > 0)
    {
      diffs = 0;
      while (!q2.empty())
      {
        q1.push(q2.front());
        q2.pop();
      }

      while (!q1.empty())
      {
        char a = q1.front();
        q1.pop();
        if (q1.empty())
        {
          q2.push(a);
          break;
        }

        char b = q1.front();

        if (a != b && tolower(a) == tolower(b))
        {
          diffs++;
          q1.pop();
        }
        else
        {
          q2.push(a);
        }
      }
    }

    string answer = "";
    while (!q2.empty())
    {
      answer += q2.front();
      q2.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.makeGood("leEeetcode");
  string result2 = solution.makeGood("abBAcC");
  string result3 = solution.makeGood("s");
}