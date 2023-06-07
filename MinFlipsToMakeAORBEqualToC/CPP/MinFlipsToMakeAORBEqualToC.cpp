// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minFlips(int a, int b, int c)
  {
    int answer = 0;
    while (a > 0 || b > 0 || c > 0)
    {
      int a1 = a & 1;
      int b1 = b & 1;
      int c1 = c & 1;

      if (c1 == 1 && b1 == 0 && a1 == 0)
      {
        answer++;
      }

      if (c1 == 0)
      {
        if (b1 == 1)
        {
          answer++;
        }

        if (a1 == 1)
        {
          answer++;
        }
      }

      a >>= 1;
      b >>= 1;
      c >>= 1;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minFlips(2, 6, 5);
  int result2 = solution.minFlips(4, 2, 7);
  int result3 = solution.minFlips(1, 2, 3);
}