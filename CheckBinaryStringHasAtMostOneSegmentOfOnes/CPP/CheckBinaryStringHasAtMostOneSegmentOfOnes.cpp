// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool checkOnesSegment(string s)
  {
    bool hasSegment = false;
    bool hadSegment = false;
    for (char &c : s)
    {
      if (c == '1')
      {
        if (hadSegment)
        {
          return false;
        }
        hasSegment = true;
      }
      else
      {
        hadSegment = hadSegment || hasSegment;
        hasSegment = false;
      }
    }

    return hasSegment || hadSegment;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.checkOnesSegment("1001");
  bool result2 = solution.checkOnesSegment("110");
  bool result3 = solution.checkOnesSegment("1");
}