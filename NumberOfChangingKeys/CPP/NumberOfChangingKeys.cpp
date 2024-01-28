// https://leetcode.com/problems/number-of-changing-keys/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int countKeyChanges(string s)
  {
    int changes = 0;
    for (int i = 1; i < s.size(); i++)
    {
      if (towlower(s[i]) != towlower(s[i - 1]))
      {
        changes++;
      }
    }

    return changes;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countKeyChanges("aAbBcC");
  int result2 = solution.countKeyChanges("AaAaAaaA");
}