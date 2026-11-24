// https://leetcode.com/problems/maximum-subarray-with-equal-products/description/?envType=daily-question&envId=2026-11-24
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
  int maxLength(vector<int> &nums)
  {
    int len = 1;
    int greatest = 1;
    int prod = nums[0];
    int gd = nums[0];
    int lm = nums[0];
    int last = 1;
    for (int i = 1; i < nums.size(); i++)
    {
      if (prod * nums[i] == lcm(lm, nums[i]) * gcd(gd, nums[i]))
      {
        greatest = max(greatest, ++len);
        prod = prod * nums[i];
        lm = lcm(lm, nums[i]);
        gd = gcd(gd, nums[i]);
      }
      else
      {
        len = 1;
        i = last++;
        prod = nums[i];
        gd = nums[i];
        lm = nums[i];
      }
    }

    return greatest;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxLength(*new vector<int>{1, 2, 1, 2, 1, 1, 1});
  int result2 = solution.maxLength(*new vector<int>{2, 3, 4, 5, 6});
  int result3 = solution.maxLength(*new vector<int>{1, 2, 3, 1, 4, 5, 1});
}