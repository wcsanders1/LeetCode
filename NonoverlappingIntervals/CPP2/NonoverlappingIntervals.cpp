// https://leetcode.com/problems/non-overlapping-intervals/submissions/868208810/
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
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    int total = 1;
    int n = intervals.size();
    int mn = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
      if (intervals[i][0] >= mn)
      {
        total++;
        mn = intervals[i][1];
      }
      else
      {
        mn = min(mn, intervals[i][1]);
      }
    }

    return n - total;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 2}, {2, 3}, {3, 4}, {1, 3}});
  int result2 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 2}, {1, 2}, {1, 2}});
  int result3 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 2}, {2, 3}});
}