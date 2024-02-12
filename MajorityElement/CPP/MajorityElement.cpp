// https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.majorityElement(*new vector<int>{3, 2, 3});
  int result2 = solution.majorityElement(*new vector<int>{2, 2, 1, 1, 1, 2, 2});
}