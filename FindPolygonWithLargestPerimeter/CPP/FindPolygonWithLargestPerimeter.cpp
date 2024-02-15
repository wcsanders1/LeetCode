// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  long long largestPerimeter(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> pre(n, 0);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      pre[i] = pre[i - 1] + nums[i];
    }

    for (int i = n - 1; i >= 2; i--)
    {
      if (nums[i] < pre[i - 1])
      {
        return pre[i];
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.largestPerimeter(*new vector<int>{5, 5, 5});
  long long result2 = solution.largestPerimeter(*new vector<int>{1, 12, 1, 2, 5, 50, 3});
  long long result3 = solution.largestPerimeter(*new vector<int>{5, 5, 50});
}