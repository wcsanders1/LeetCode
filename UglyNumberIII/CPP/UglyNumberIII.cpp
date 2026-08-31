// https://leetcode.com/problems/ugly-number-iii/description/
// NOT MINE: https://leetcode.com/problems/ugly-number-iii/solutions/387539/cpp-binary-search-with-picture-binary-se-1up8/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution
{
public:
  int nthUglyNumber(int n, int a, int b, int c)
  {
    long long start = 1;
    long long end = 2 * 1e9;
    long long al = (long)a;
    long long bl = (long)b;
    long long cl = (long)c;

    long long ab = (al * bl) / gcd(al, bl);
    long long bc = (bl * cl) / gcd(bl, cl);
    long long ac = (al * cl) / gcd(al, cl);
    long long abc = (al * bc) / gcd(al, bc);
    while (start < end)
    {
      long long mid = start + (end - start) / 2;
      int cnt = mid / al + mid / bl + mid / cl - mid / ab - mid / bc - mid / ac + mid / abc;
      if (cnt < n)
      {
        start = mid + 1;
      }
      else
      {
        end = mid;
      }
    }

    return start;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.nthUglyNumber(3, 2, 3, 5);
  int result2 = solution.nthUglyNumber(4, 2, 3, 4);
  int result3 = solution.nthUglyNumber(5, 2, 11, 13);
  int result4 = solution.nthUglyNumber(3, 18, 12, 5);
}