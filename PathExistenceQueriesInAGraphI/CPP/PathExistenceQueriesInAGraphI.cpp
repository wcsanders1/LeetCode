// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
  {
    vector<int> distances(n, 0);
    int start = 0;
    int end = 0;
    while (start < n)
    {
      int num = nums[start];
      while (end < n && nums[end] - num <= maxDiff)
      {
        num = nums[end];
        distances[start] = end++;
      }

      start++;
      while (start < n && start < end)
      {
        distances[start++] = end - 1;
      }
    }

    vector<bool> answer;
    for (auto &q : queries)
    {
      int mn = min(q[0], q[1]);
      int mx = max(q[0], q[1]);
      answer.push_back(distances[mn] >= mx);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.pathExistenceQueries(2, *new vector<int>{1, 3}, 1, *new vector<vector<int>>{{0, 0}, {0, 1}});
  auto result2 = solution.pathExistenceQueries(4, *new vector<int>{2, 5, 6, 8}, 2, *new vector<vector<int>>{{0, 1}, {0, 2}, {1, 3}, {2, 3}});
  auto result3 = solution.pathExistenceQueries(3, *new vector<int>{11746, 13962, 40560}, 6182, *new vector<vector<int>>{{1, 2}, {1, 2}});
}