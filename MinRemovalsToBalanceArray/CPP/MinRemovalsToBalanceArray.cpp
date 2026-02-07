// https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minRemoval(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());
    int mn = 0;
    int mx = 0;
    int greatest = 0;
    while (mx < nums.size() && mn <= mx)
    {
      long long d = (long long)nums[mn] * (long long)k;
      if ((long long)nums[mx] > d)
      {
        mn++;
      }
      else
      {
        mx++;
      }
      greatest = max(greatest, mx - mn);
    }

    return nums.size() - greatest;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minRemoval(*new vector<int>{2, 1, 5}, 2);           // 1
  int result2 = solution.minRemoval(*new vector<int>{1, 6, 2, 9}, 3);        // 2
  int result3 = solution.minRemoval(*new vector<int>{4, 6}, 2);              // 0
  int result4 = solution.minRemoval(*new vector<int>{20, 5, 11}, 2);         // 1
  int result5 = solution.minRemoval(*new vector<int>{8, 99, 65, 16, 39}, 3); // 2
}