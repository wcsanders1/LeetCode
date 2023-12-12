// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2023-12-12
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxProduct(*new vector<int>{3, 4, 5, 2});
  int result2 = solution.maxProduct(*new vector<int>{1, 5, 4, 5});
  int result3 = solution.maxProduct(*new vector<int>{3, 7});
}