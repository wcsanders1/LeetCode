// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long minCost(vector<int> &nums, vector<int> &cost)
  {
    int n = nums.size();
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
      pairs.push_back({nums[i], cost[i]});
    }

    sort(pairs.begin(), pairs.end());
    long long answer = INT64_MAX;
    int mid = n / 2;

    int start = mid;
    while (start >= 0)
    {
      int target = pairs[start].first;
      long long cur = 0;
      for (int i = 0; i < n; i++)
      {
        long long diff = abs(target - pairs[i].first);
        cur += diff * pairs[i].second;
      }
      if (cur > answer)
      {
        break;
      }
      start--;
      answer = cur;
    }

    start = mid + 1;
    while (start < n)
    {
      int target = pairs[start].first;
      long long cur = 0;
      for (int i = 0; i < n; i++)
      {
        long long diff = abs(target - pairs[i].first);
        cur += diff * pairs[i].second;
      }
      if (cur > answer)
      {
        break;
      }
      start++;
      answer = cur;
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