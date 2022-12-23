// https://leetcode.com/problems/is-subsequence/description/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    if (s.size() > t.size())
    {
      return false;
    }

    if (s.size() == 0)
    {
      return true;
    }

    int position = 0;
    for (int i = 0; i < t.size(); i++)
    {
      if (t[i] == s[position])
      {
        position++;
      }

      if (position >= s.size())
      {
        return true;
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isSubsequence("abc", "ahbgdc");
  bool result2 = solution.isSubsequence("axc", "ahbgdc");
}