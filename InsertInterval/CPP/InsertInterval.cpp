// https://leetcode.com/problems/insert-interval/description/
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
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    vector<vector<int>> answer;
    int n = intervals.size();
    if (n == 0)
    {
      return {newInterval};
    }
    int start = 0;
    int end = 0;

    if (newInterval[1] < intervals[0][0])
    {
      answer.push_back(newInterval);
    }

    while (start < n)
    {
      int mn = intervals[start][0];
      int mx = intervals[start][1];
      if (newInterval[0] > mx || newInterval[1] < mn)
      {
        answer.push_back({mn, mx});
        if (newInterval[0] > mx && start < n - 1 && newInterval[1] < intervals[start + 1][0])
        {
          answer.push_back(newInterval);
        }
      }
      else
      {
        mn = min(mn, newInterval[0]);
        mx = max(mx, newInterval[1]);
        while (end < n - 1 && newInterval[1] >= intervals[end + 1][0])
        {
          end++;
          mx = max(mx, intervals[end][1]);
        }
        answer.push_back({mn, mx});
      }

      end++;
      start = end;
    }

    if (newInterval[0] > intervals[n - 1][1])
    {
      answer.push_back(newInterval);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.insert(*new vector<vector<int>>{{1, 3}, {6, 9}}, *new vector<int>{2, 5});
  auto result2 = solution.insert(*new vector<vector<int>>{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, *new vector<int>{4, 8});
  auto result3 = solution.insert(*new vector<vector<int>>{{1, 2}, {3, 5}}, *new vector<int>{6, 8});
  auto result4 = solution.insert(*new vector<vector<int>>{{3, 5}, {6, 9}}, *new vector<int>{1, 2});
  auto result5 = solution.insert(*new vector<vector<int>>{{3, 5}, {6, 9}}, *new vector<int>{1, 4});
  auto result6 = solution.insert(*new vector<vector<int>>{{3, 5}, {6, 9}}, *new vector<int>{1, 10});
  auto result7 = solution.insert(*new vector<vector<int>>{{3, 5}, {12, 15}}, *new vector<int>{6, 6});
}