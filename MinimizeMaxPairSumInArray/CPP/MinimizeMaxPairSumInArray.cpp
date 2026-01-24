// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minPairSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int answer = 0;
    for (int u = n / 2, l = (n / 2) - 1; u < n; u++, l--)
    {
      answer = max(answer, nums[u] + nums[l]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minPairSum(*new vector<int>{3, 5, 2, 3});
  int result2 = solution.minPairSum(*new vector<int>{3, 5, 4, 2, 4, 6});
  int result3 = solution.minPairSum(*new vector<int>{5, 5, 5, 2, 5, 6});
}