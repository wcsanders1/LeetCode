// https://leetcode.com/problems/predict-the-winner/description/
// NOT MINE: https://leetcode.com/problems/predict-the-winner/solutions/155217/from-brute-force-to-top-down-dp-by-grace-wmy5/
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool predictTheWinner(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int winningTotal = getTotal(nums, memo, 0, n - 1);
    int total = 0;
    for (int &n : nums)
    {
      total += n;
    }

    return total - winningTotal <= winningTotal;
  }

private:
  int getTotal(vector<int> &nums, vector<vector<int>> &memo, int start, int end)
  {
    if (start > end)
    {
      return 0;
    }

    if (start == end)
    {
      return nums[start];
    }

    if (memo[start][end] != -1)
    {
      return memo[start][end];
    }

    int result = max(
        nums[start] + min(getTotal(nums, memo, start + 2, end), getTotal(nums, memo, start + 1, end - 1)),
        nums[end] + min(getTotal(nums, memo, start, end - 2), getTotal(nums, memo, start + 1, end - 1)));

    memo[start][end] = result;
    return result;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.predictTheWinner(*new vector<int>{1, 5, 2});
  bool result2 = solution.predictTheWinner(*new vector<int>{1, 5, 233, 7});
}