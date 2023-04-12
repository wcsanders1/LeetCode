// https://leetcode.com/problems/simplify-path/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    stack<string> dirs;

    int start = 0;
    int end = 0;

    while (start < path.size())
    {
      while (end < path.size() && path[end] == '/')
      {
        end++;
      }

      if (start < end)
      {
        start = end;
        continue;
      }

      string dots = "";
      while (end < path.size() && path[end] == '.')
      {
        dots += '.';
        end++;
      }

      if (start < end && (end >= path.size() || path[end] == '/'))
      {
        if (end - start == 2 && !dirs.empty())
        {
          dirs.pop();
        }
        else if (end - start > 2)
        {
          dirs.push(dots);
        }

        start = end;
        continue;
      }

      string dir = dots;
      while (end < path.size() && path[end] != '/')
      {
        dir += path[end++];
      }

      start = end;

      dirs.push(dir);
    }

    stack<string> rev;
    while (!dirs.empty())
    {
      rev.push(dirs.top());
      dirs.pop();
    }

    string answer = "";
    while (!rev.empty())
    {
      answer += "/" + rev.top();
      rev.pop();
    }

    return answer.size() > 0 ? answer : "/";
  }
};

int main()
{
  Solution solution;

  string result1 = solution.simplifyPath("/home/");
  string result2 = solution.simplifyPath("/../");
  string result3 = solution.simplifyPath("/home//foo/");
  string result4 = solution.simplifyPath("/a/./b/../../c/");
  string result5 = solution.simplifyPath("/a/..");
  string result6 = solution.simplifyPath("/a/../");
  string result7 = solution.simplifyPath("/../../../../../a");
  string result8 = solution.simplifyPath("/a/./b/./c/./d/");
  string result9 = solution.simplifyPath("/a/../.././../../.");
  string result10 = solution.simplifyPath("/a//b//c//////d");
  string result11 = solution.simplifyPath("/..hidden");
  string result12 = solution.simplifyPath("/hello../world");
}