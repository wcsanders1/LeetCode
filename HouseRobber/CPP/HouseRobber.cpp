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

    nums[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
      nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
    }

    return nums[n - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.rob(*new vector<int>{1, 2, 3, 1});
  int result2 = solution.rob(*new vector<int>{2, 7, 9, 3, 1});
  int result3 = solution.rob(*new vector<int>{2, 1, 1, 2});
}