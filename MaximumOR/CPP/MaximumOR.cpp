// https://leetcode.com/problems/maximum-or/
// NOT MINE: https://leetcode.com/problems/maximum-or/solutions/3520285/easiest-solution-prefix-suffix-c/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long maximumOr(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    vector<long long> post(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
      pre[i] = pre[i - 1] | nums[i - 1];
    }

    for (int i = n; i > 0; i--)
    {
      post[i - 1] = post[i] | nums[i - 1];
    }

    k = 1 << k;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
      res = max(res, pre[i] | ((long long)nums[i] * k) | post[i + 1]);
    }

    return res;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maximumOr(*new vector<int>{12, 9}, 1);
  auto result2 = solution.maximumOr(*new vector<int>{8, 1, 2}, 2);
}