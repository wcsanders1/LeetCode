// https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18
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
  int findGCD(vector<int> &nums)
  {
    int smallest = INT32_MAX;
    int greatest = 0;
    for (int &n : nums)
    {
      smallest = min(smallest, n);
      greatest = max(greatest, n);
    }

    while ((greatest % smallest) > 0)
    {
      int t = greatest;
      greatest = smallest;
      smallest = t % smallest;
    }

    return smallest;
  }
};