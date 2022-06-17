// https://leetcode.com/problems/power-of-two/
#include <limits.h>

using namespace std;

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    if (n <= 0)
    {
      return false;
    }

    return (n & (n - 1)) == 0;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isPowerOfTwo(1);
  bool result2 = solution.isPowerOfTwo(16);
  bool result3 = solution.isPowerOfTwo(3);
  bool result4 = solution.isPowerOfTwo(0);
  bool result5 = solution.isPowerOfTwo(-4);
}