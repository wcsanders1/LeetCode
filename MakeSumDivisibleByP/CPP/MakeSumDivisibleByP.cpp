// https://leetcode.com/problems/make-sum-divisible-by-p/
// NOT MINE: https://leetcode.com/problems/make-sum-divisible-by-p/discuss/854174/C%2B%2BJava-O(n)
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minSubarray(vector<int> &nums, int p)
  {
    int modulo = 0;
    int recentModulo = 0;
    int minWindow = nums.size();

    for (int n : nums)
    {
      modulo = (modulo + n) % p;
    }

    if (modulo == 0)
    {
      return 0;
    }

    unordered_map<int, int> position = {{0, -1}};
    for (int i = 0; i < nums.size(); i++)
    {
      recentModulo = (recentModulo + nums[i]) % p;
      int complement = (p - modulo + recentModulo) % p;
      if (position.count(complement))
      {
        minWindow = min(minWindow, i - position[complement]);
      }
      position[recentModulo] = i;
    }

    return minWindow >= nums.size() ? -1 : minWindow;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSubarray(*new vector<int>{3, 1, 4, 2}, 6);
  int result2 = solution.minSubarray(*new vector<int>{6, 3, 5, 2}, 9);
  int result3 = solution.minSubarray(*new vector<int>{1, 2, 3}, 3);
  int result4 = solution.minSubarray(*new vector<int>{1, 2, 3}, 7);
  int result5 = solution.minSubarray(*new vector<int>{1000000000, 1000000000, 1000000000}, 3);
  int result6 = solution.minSubarray(*new vector<int>{26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3}, 26);
  int result7 = solution.minSubarray(*new vector<int>{3, 1, 4}, 6);
}