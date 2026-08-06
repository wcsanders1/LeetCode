// https://leetcode.com/problems/smallest-divisible-digit-product-i/description/?envType=daily-question&envId=2026-08-06
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
  int smallestNumber(int n, int t)
  {
    while (n <= INT32_MAX)
    {
      int i = n;
      int p = 1;
      while (i > 0)
      {
        p *= i % 10;
        i /= 10;
      }

      if (p % t == 0)
      {
        return n;
      }

      n++;
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.smallestNumber(10, 2);
  int result2 = solution.smallestNumber(15, 3);
}