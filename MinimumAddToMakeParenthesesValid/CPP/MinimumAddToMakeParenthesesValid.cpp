// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int minAddToMakeValid(string s)
  {
    int opens = 0;
    int closeds = 0;
    for (char &c : s)
    {
      if (c == '(')
      {
        opens++;
      }
      else
      {
        if (opens > 0)
        {
          opens--;
        }
        else
        {
          closeds++;
        }
      }
    }

    return opens + closeds;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minAddToMakeValid("())");    // 1
  int result2 = solution.minAddToMakeValid("(((");    // 3
  int result3 = solution.minAddToMakeValid("()))(("); // 4
}