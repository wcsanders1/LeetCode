// https://leetcode.com/problems/domino-and-tromino-tiling/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int numTilings(int n)
  {
    int mod = 1000000007;
    if (n == 1)
    {
      return 1;
    }

    if (n == 2)
    {
      return 2;
    }

    long long s1 = 1;
    long long s2 = 2;
    long long s3 = 5;

    int i = n - 3;
    while (i-- > 0)
    {
      long long t = (2 * s3 + s1) % mod;
      s1 = s2 % mod;
      s2 = s3 % mod;
      s3 = t % mod;
    }

    return s3;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numTilings(1);
  int result2 = solution.numTilings(2);
  int result3 = solution.numTilings(3);
  int result4 = solution.numTilings(4);
  int result5 = solution.numTilings(5);
  int result6 = solution.numTilings(30);
}