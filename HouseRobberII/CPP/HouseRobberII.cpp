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
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
    {
      return nums[0];
    }

    if (n == 2)
    {
      return max(nums[0], nums[1]);
    }

    auto nums2 = nums;
    nums.erase(nums.begin());
    nums2.erase(nums2.begin() + n - 1);
    nums[1] = max(nums[0], nums[1]);
    nums2[1] = max(nums2[0], nums2[1]);
    for (int i = 2; i < n - 1; i++)
    {
      nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
      nums2[i] = max(nums2[i - 2] + nums2[i], nums2[i - 1]);
    }

    return max(nums[n - 2], nums2[n - 2]);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.rob(*new vector<int>{2, 3, 2});
  int result2 = solution.rob(*new vector<int>{1, 2, 3, 1});
  int result3 = solution.rob(*new vector<int>{1, 2, 3});
}