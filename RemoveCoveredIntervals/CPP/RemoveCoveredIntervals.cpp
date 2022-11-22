// https://leetcode.com/problems/remove-covered-intervals/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

    for (vector<int> &i : intervals)
    {
      i.push_back(0);
    }

    int covered = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
      vector<int> &a = intervals[i];
      if (a[2] == 1)
      {
        continue;
      }

      for (int j = i + 1; j < intervals.size(); j++)
      {
        vector<int> &b = intervals[j];
        if (b[2] == 0 && b[0] < a[1] && b[1] <= a[1])
        {
          b[2] = 1;
          covered++;
        }
      }
    }

    return intervals.size() - covered;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.removeCoveredIntervals(*new vector<vector<int>>{{1, 4}, {3, 6}, {2, 8}}); // 2
  int result2 = solution.removeCoveredIntervals(*new vector<vector<int>>{{1, 4}, {2, 3}});         // 1
  int result3 = solution.removeCoveredIntervals(*new vector<vector<int>>{{1, 2}, {1, 4}, {3, 4}}); // 1
  int result4 = solution.removeCoveredIntervals(*new vector<vector<int>>{
      {34335, 39239}, {15875, 91969}, {29673, 66453}, {53548, 69161}, {40618, 93111}}); // 2
}