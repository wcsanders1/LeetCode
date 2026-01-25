// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minimumDifference(vector<int> &nums, int k)
  {
    if (k < 2)
    {
      return 0;
    }

    int n = nums.size();
    sort(nums.begin(), nums.end());

    int answer = INT32_MAX;
    for (int b = 0, e = k - 1; e < n; b++, e++)
    {
      answer = min(answer, nums[e] - nums[b]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumDifference(*new vector<int>{90}, 1);
  int result2 = solution.minimumDifference(*new vector<int>{9, 4, 1, 7}, 2);
}