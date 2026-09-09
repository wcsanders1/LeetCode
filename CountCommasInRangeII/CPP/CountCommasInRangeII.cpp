// https://leetcode.com/problems/count-commas-in-range-ii/description/?envType=daily-question&envId=2026-09-09
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long countCommas(long long n)
  {
    long long mx = 999999999999999;
    long long commas = 0;
    while (mx > 0)
    {
      commas += max((long long)0, n - mx);
      mx /= 1000;
    }

    return commas;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.countCommas(1002);
  long long result2 = solution.countCommas(0);
  long long result3 = solution.countCommas(1000001);
}