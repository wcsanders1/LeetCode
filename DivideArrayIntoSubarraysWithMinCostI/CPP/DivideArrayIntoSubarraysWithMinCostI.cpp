// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minimumCost(vector<int> &nums)
  {
    int first = nums[0];
    nums.erase(nums.begin());
    sort(nums.begin(), nums.end());
    return first + nums[0] + nums[1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumCost(*new vector<int>{1, 2, 3, 12});
  int result2 = solution.minimumCost(*new vector<int>{5, 4, 3});
  int result3 = solution.minimumCost(*new vector<int>{10, 3, 1, 1});
}