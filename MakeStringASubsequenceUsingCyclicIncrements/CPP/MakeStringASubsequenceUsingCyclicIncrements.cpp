// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  bool canMakeSubsequence(string str1, string str2)
  {
    int index = 0;
    for (char &c : str1)
    {
      if (charCanBeEqual(c, str2[index]))
      {
        index++;
        if (index == str2.size())
        {
          return true;
        }
      }
    }

    return !(index < str2.size());
  }

private:
  bool charCanBeEqual(char c1, char c2)
  {
    if (c1 == c2)
    {
      return true;
    }

    if (c1 == 'z' && c2 == 'a')
    {
      return true;
    }

    if ((c1 + 1) == c2)
    {
      return true;
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canMakeSubsequence("abc", "ad");
  bool result2 = solution.canMakeSubsequence("zc", "ad");
  bool result3 = solution.canMakeSubsequence("ab", "d");
}