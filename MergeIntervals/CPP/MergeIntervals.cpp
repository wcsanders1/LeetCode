// https://leetcode.com/problems/merge-intervals/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> answer;
    int n = intervals.size();
    int start = 0;
    int end = 0;
    while (start < n)
    {
      int mx = intervals[start][1];
      while (end < n - 1 && intervals[end + 1][0] <= mx)
      {
        end++;
        mx = max(mx, intervals[end][1]);
      }
      answer.push_back({intervals[start][0], mx});
      end++;
      start = end;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.merge(*new vector<vector<int>>{{1, 3}, {2, 6}, {8, 10}, {15, 18}});
  auto result2 = solution.merge(*new vector<vector<int>>{{1, 4}, {4, 5}});
  auto result3 = solution.merge(*new vector<vector<int>>{{4, 7}, {1, 4}});
  auto result4 = solution.merge(*new vector<vector<int>>{{1, 4}, {2, 3}});
  auto result5 = solution.merge(*new vector<vector<int>>{{1, 4}, {0, 2}, {3, 5}});
}