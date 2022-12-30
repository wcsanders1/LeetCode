// https://leetcode.com/problems/non-overlapping-intervals/description/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    auto sorter = [](const vector<int> &i1, const vector<int> &i2)
    {
      return i1[0] == i2[0] ? i1[1] < i2[1] : i1[0] < i2[0];
    };

    sort(intervals.begin(), intervals.end(), sorter);
    int answer = 0;
    vector<vector<int>> filtered;
    for (int i = 0; i < intervals.size(); i++)
    {
      int start = i;
      filtered.push_back(intervals[start]);

      while (start < intervals.size() - 1 && intervals[start][0] == intervals[start + 1][0])
      {
        start++;
      }

      answer += start - i;
      i = start;
    }

    int cur = filtered[filtered.size() - 1][0];
    for (int i = filtered.size() - 2; i >= 0; i--)
    {
      if (filtered[i][1] > cur)
      {
        answer++;
      }
      else
      {
        cur = filtered[i][0];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 5}, {1, 3}, {1, 2}, {2, 3}, {2, 4}, {3, 4}});
  int result2 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 2}, {2, 3}});
  int result3 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 2}, {1, 2}, {1, 2}});
  int result4 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{1, 100}, {11, 22}, {1, 11}, {2, 12}});
  int result5 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}});
  int result6 = solution.eraseOverlapIntervals(*new vector<vector<int>>{{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}}); // 7
}