// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/
// NOT MINE: https://leetcode.com/problems/minimum-time-to-complete-all-tasks/solutions/3286244/number-line/?orderBy=most_votes
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findMinimumTime(vector<vector<int>> &tasks)
  {
    auto sortByDuration = [](const vector<int> &v1, const vector<int> &v2)
    {
      return v1[1] < v2[1];
    };

    sort(tasks.begin(), tasks.end(), sortByDuration);

    vector<bool> line(2001, false);

    for (auto &task : tasks)
    {
      int start = task[0];
      int end = task[1];
      int duration = task[2];

      duration -= count(line.begin() + start, line.begin() + end + 1, true);
      for (int i = end; duration > 0; i--)
      {
        duration = line[i] ? duration : duration - 1;
        line[i] = true;
      }
    }

    return count(line.begin(), line.end(), true);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findMinimumTime(*new vector<vector<int>>{{2, 3, 1}, {4, 5, 1}, {1, 5, 2}});     // 2
  int result2 = solution.findMinimumTime(*new vector<vector<int>>{{1, 3, 2}, {2, 5, 3}, {5, 6, 2}});     // 4
  int result3 = solution.findMinimumTime(*new vector<vector<int>>{{2, 13, 2}, {6, 18, 5}, {2, 13, 3}});  // 5
  int result4 = solution.findMinimumTime(*new vector<vector<int>>{{15, 20, 1}, {3, 18, 2}, {4, 12, 6}}); // 7
}