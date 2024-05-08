// https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  bool checkValidString(string s)
  {
    int mn = 0;
    int mx = 0;
    for (char &c : s)
    {
      if (c == '(')
      {
        mn++;
        mx++;
      }
      else if (c == ')')
      {
        mn--;
        mx--;
      }
      else
      {
        mn--;
        mx++;
      }

      if (mx < 0)
      {
        return false;
      }

      if (mn < 0)
      {
        mn = 0;
      }
    }

    return mn == 0;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.checkValidString("()");                                                                                                   // true
  bool result2 = solution.checkValidString("(*)");                                                                                                  // true
  bool result3 = solution.checkValidString("(*))");                                                                                                 // true
  bool result4 = solution.checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"); // false
  bool result5 = solution.checkValidString("**(");                                                                                                  // false
  bool result6 = solution.checkValidString("(((((*)))**");                                                                                          // true
}