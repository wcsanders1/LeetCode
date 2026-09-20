// https://leetcode.com/problems/two-best-non-overlapping-events/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxTwoEvents(vector<vector<int>> &events)
  {
    int n = events.size();
    sort(events.begin(), events.end());
    vector<int> mx(n, 0);
    mx[n - 1] = events[n - 1][2];
    for (int i = n - 2; i >= 0; i--)
    {
      mx[i] = max(events[i][2], mx[i + 1]);
    }

    int most = 0;
    for (int i = 0; i < n; i++)
    {
      int idx = getIndex(events, i + 1, n - 1, events[i][1] + 1);
      if (idx == -1)
      {
        most = max(most, events[i][2]);
      }
      else
      {
        most = max(most, events[i][2] + mx[idx]);
      }
    }

    return most;
  }

private:
  int getIndex(vector<vector<int>> &events, int start, int end, int target)
  {
    if (start >= end)
    {
      if (start >= events.size() || events[start][0] < target)
      {
        return -1;
      }
      return start;
    }

    int mid = (end + start) / 2;
    if (events[mid][0] >= target)
    {
      if (events[mid - 1][0] < target)
      {
        return mid;
      }
      return getIndex(events, start, mid - 1, target);
    }
    return getIndex(events, mid + 1, end, target);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxTwoEvents(*new vector<vector<int>>{{1, 3, 2}, {4, 5, 2}, {2, 4, 3}});
  int result2 = solution.maxTwoEvents(*new vector<vector<int>>{{1, 3, 2}, {4, 5, 2}, {1, 5, 5}});
  int result3 = solution.maxTwoEvents(*new vector<vector<int>>{{1, 5, 3}, {1, 5, 1}, {6, 6, 5}});
  int result4 = solution.maxTwoEvents(*new vector<vector<int>>{{66, 97, 90}, {98, 98, 68}, {38, 49, 63}, {91, 100, 42}, {92, 100, 22}, {1, 77, 50}, {64, 72, 97}});
}