// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minTaps(int n, vector<int> &ranges)
  {
    int r_size = ranges.size();
    vector<vector<int>> intervals(r_size, vector<int>(2, 0));
    for (int i = 0; i < r_size; i++)
    {
      int num = ranges[i];
      int s = max(0, i - num);
      int e = min(i + num, n);
      if (s == e)
      {
        continue;
      }

      intervals[i] = {s, e};
    }

    auto comp = [](const vector<int> &a, const vector<int> &b)
    {
      if (a[0] == b[0])
      {
        return a[1] > b[1];
      }

      return a[0] < b[0];
    };

    sort(intervals.begin(), intervals.end(), comp);
    if (intervals[0][0] > 0)
    {
      return -1;
    }

    unordered_map<int, int> highests;
    for (auto &interval : intervals)
    {
      if (highests.count(interval[0]) == 0)
      {
        highests[interval[0]] = interval[1];
      }
    }

    int start = 0;
    int end = highests[0];
    int answer = 1;
    while (end <= n)
    {
      if (end == n)
      {
        return answer;
      }

      answer++;

      int next_highest = end;
      int prev_end = end;
      while (end >= start)
      {
        if (highests.count(end) > 0)
        {
          next_highest = max(next_highest, highests[end]);
        }
        end--;
      }
      if (start == next_highest)
      {
        return -1;
      }

      start = prev_end;
      end = next_highest;
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minTaps(5, *new vector<int>{3, 4, 1, 1, 0, 0});                                      // 1
  int result2 = solution.minTaps(3, *new vector<int>{0, 0, 0, 0});                                            // -1
  int result3 = solution.minTaps(7, *new vector<int>{1, 2, 1, 0, 2, 1, 0, 1});                                // 3
  int result4 = solution.minTaps(17, *new vector<int>{0, 3, 3, 2, 2, 4, 2, 1, 5, 1, 0, 1, 2, 3, 0, 3, 1, 1}); // 3
  int result5 = solution.minTaps(35,
                                 *new vector<int>{1, 0, 4, 0, 4, 1, 4, 3, 1, 1, 1, 2, 1, 4, 0, 3, 0, 3, 0, 3, 0, 5, 3, 0, 0, 1, 2, 1, 2, 4, 3, 0, 1, 0, 5, 2}); // 6
  int result6 = solution.minTaps(5, *new vector<int>{3, 0, 1, 1, 0, 0});
}