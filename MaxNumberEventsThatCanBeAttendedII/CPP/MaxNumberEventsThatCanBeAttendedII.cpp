// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Event
{
  int startDay;
  int endDay;
  int value;
};

class Solution
{
public:
  int maxValue(vector<vector<int>> &events, int k)
  {
    vector<Event> _events;
    for (auto &e : events)
    {
      Event event;
      event.startDay = e[0];
      event.endDay = e[1];
      event.value = e[2];
      _events.push_back(event);
    }

    auto sortByStart = [](const Event &e1, const Event &e2)
    {
      return e1.startDay < e2.startDay;
    };

    sort(_events.begin(), _events.end(), sortByStart);
    int n = _events.size();
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int _k = 1; _k <= k; _k++)
    {
      dp[_k][n - 1] = _events[n - 1].value;
      for (int i = n - 2; i >= 0; i--)
      {
        int currentValue = _events[i].value;
        int nextIndex = getClosestIndex(_events[i].endDay + 1, _events, i, n - 1);
        int temp = 0;
        if (nextIndex > -1)
        {
          temp = currentValue + dp[_k - 1][nextIndex];
        }

        if (temp > dp[_k][i + 1])
        {
          dp[_k][i] = temp;
        }
        else if (currentValue > dp[_k][i + 1])
        {
          dp[_k][i] = currentValue;
        }
        else
        {
          dp[_k][i] = dp[_k][i + 1];
        }
      }
    }

    return dp[k][0];
  }

private:
  int getClosestIndex(int endDay, vector<Event> &events, int start, int end)
  {
    if (start > end)
    {
      return -1;
    }

    int mid = (start + end) / 2;
    if (events[mid].startDay == endDay)
    {
      return mid;
    }

    if (events[mid].startDay < endDay)
    {
      return getClosestIndex(endDay, events, mid + 1, end);
    }

    int index = getClosestIndex(endDay, events, start, mid - 1);

    return index > -1 ? index : mid;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxValue(*new vector<vector<int>>{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}}, 2);                                     // 7
  int result2 = solution.maxValue(*new vector<vector<int>>{{1, 2, 4}, {3, 4, 3}, {2, 3, 10}}, 2);                                    // 10
  int result3 = solution.maxValue(*new vector<vector<int>>{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}}, 3);                          // 9
  int result4 = solution.maxValue(*new vector<vector<int>>{{11, 17, 56}, {24, 40, 53}, {5, 62, 67}, {66, 69, 84}, {56, 89, 15}}, 2); // 151
  int result5 = solution.maxValue(*new vector<vector<int>>{{69, 83, 61}, {44, 90, 19}, {26, 87, 9}}, 3);                             // 61
}