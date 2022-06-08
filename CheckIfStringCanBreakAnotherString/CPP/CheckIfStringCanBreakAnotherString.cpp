// https://leetcode.com/problems/check-if-a-string-can-break-another-string/
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
  bool checkIfCanBreak(string s1, string s2)
  {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i <= s1.size(); i++)
    {
      if (i == s1.size())
      {
        return true;
      }

      if (s1[i] < s2[i])
      {
        break;
      }
    }

    for (int i = 0; i <= s1.size(); i++)
    {
      if (i == s1.size())
      {
        return true;
      }

      if (s1[i] > s2[i])
      {
        break;
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.checkIfCanBreak("abc", "xya");
  bool result2 = solution.checkIfCanBreak("abe", "acd");
  bool result3 = solution.checkIfCanBreak("leetcodee", "interview");
}