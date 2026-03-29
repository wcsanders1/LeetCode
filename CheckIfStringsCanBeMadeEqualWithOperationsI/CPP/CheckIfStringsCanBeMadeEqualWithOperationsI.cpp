// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool canBeEqual(string s1, string s2)
  {
    for (int i = 0; i < 4; i++)
    {
      if (i < 2)
      {
        if (s1[i] != s2[i] && s1[i] != s2[i + 2])
        {
          return false;
        }
      }
      else
      {
        if (s1[i] != s2[i] && s1[i] != s2[i - 2])
        {
          return false;
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canBeEqual("abcd", "cdab");
  bool result2 = solution.canBeEqual("abcd", "dacb");
}