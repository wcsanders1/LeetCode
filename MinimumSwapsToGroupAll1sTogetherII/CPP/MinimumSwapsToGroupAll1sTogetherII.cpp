// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minSwaps(vector<int> &nums)
  {
    int ones = 0;
    for (int &n : nums)
    {
      ones = n == 1 ? ones + 1 : ones;
    }

    if (ones == 0)
    {
      return 0;
    }

    vector<int> nums2 = nums;

    nums.insert(nums.end(), nums2.begin(), nums2.end());

    int index = 0;
    int zeros = 0;

    for (int i = 0; i < ones; i++)
    {
      zeros = nums[i] == 0 ? zeros + 1 : zeros;
    }

    int swaps = zeros;

    for (int start = 0, end = ones; end < nums.size(); start++, end++)
    {
      if (nums[start] == 0)
      {
        zeros--;
      }

      if (nums[end] == 0)
      {
        zeros++;
      }

      swaps = min(swaps, zeros);
    }

    return swaps;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSwaps(*new vector<int>{0, 1, 0, 1, 1, 0, 0});
  int result2 = solution.minSwaps(*new vector<int>{0, 1, 1, 1, 0, 0, 1, 1, 0});
  int result3 = solution.minSwaps(*new vector<int>{1, 1, 0, 0, 1});
  int result4 = solution.minSwaps(*new vector<int>{1, 1, 1, 0, 0, 1, 0, 1, 1, 0});
}