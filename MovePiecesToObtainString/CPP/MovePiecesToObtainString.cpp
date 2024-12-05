// https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  bool canChange(string start, string target)
  {
    int n = start.size();
    int startIndex = 0;
    for (int targetIndex = 0; targetIndex < n; targetIndex++)
    {
      if (target[targetIndex] == 'L')
      {
        while (startIndex < n && start[startIndex] == '_')
        {
          startIndex++;
        }

        if (startIndex >= n)
        {
          return false;
        }

        if (start[startIndex] != 'L' || startIndex < targetIndex)
        {
          return false;
        }

        startIndex++;
      }

      if (target[targetIndex] == 'R')
      {
        while (startIndex < n && start[startIndex] == '_')
        {
          startIndex++;
        }

        if (startIndex >= n)
        {
          return false;
        }

        if (start[startIndex] != 'R' || startIndex > targetIndex)
        {
          return false;
        }

        startIndex++;
      }
    }

    while (startIndex < n)
    {
      if (start[startIndex] != '_')
      {
        return false;
      }
      startIndex++;
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canChange("_L__R__R_", "L______RR");   // true
  bool result2 = solution.canChange("R_L_", "__LR");             // false
  bool result3 = solution.canChange("_R", "R_");                 // false
  bool result4 = solution.canChange("_LL__R__R_", "L___L___RR"); // false
  bool result5 = solution.canChange("_L__R__R_L", "L______RR_"); // false
}