// https://leetcode.com/problems/count-distinct-numbers-on-board/description/
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
  int distinctIntegers(int n)
  {
    if (n == 1)
    {
      return 1;
    }

    return n - 1;
  }
};