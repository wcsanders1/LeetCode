// https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    nums.push_back(0);
    for (int i = 0; i < nums.size(); i++)
    {
      replace(nums, nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != i)
      {
        return i;
      }
    }

    return 0;
  }

private:
  void replace(vector<int> &nums, int i)
  {
    if (nums[i] == i)
    {
      return;
    }

    int t = nums[i];
    nums[i] = i;
    replace(nums, t);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.missingNumber(*new vector<int>{3, 0, 1});
  int result2 = solution.missingNumber(*new vector<int>{0, 1});
  int result3 = solution.missingNumber(*new vector<int>{9, 6, 4, 2, 3, 5, 7, 0, 1});
}