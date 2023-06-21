// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long minCost(vector<int> &nums, vector<int> &cost)
  {
    int n = nums.size();
    long long answer = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
      int curNum = nums[i];
      long long curTotal = 0;

      for (int j = 0; j < n; j++)
      {
        long long diff = abs(nums[j] - curNum);
        curTotal += diff * cost[j];
      }

      answer = min(answer, curTotal);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.minCost(*new vector<int>{1, 3, 5, 2}, *new vector<int>{2, 3, 1, 14});
  auto result2 = solution.minCost(*new vector<int>{2, 2, 2, 2, 2}, *new vector<int>{4, 2, 8, 1, 3});
}