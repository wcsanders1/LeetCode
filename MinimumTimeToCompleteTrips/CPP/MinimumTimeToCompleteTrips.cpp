// https://leetcode.com/problems/minimum-time-to-complete-trips/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  long long minimumTime(vector<int> &time, int totalTrips)
  {
    unsigned long long start = 1;
    unsigned long long end = 1e14;

    while (start < end)
    {
      auto mid = (end + start) / 2;
      unsigned long long total = 0;
      for (int t : time)
      {
        unsigned long long val = t;
        total += mid / val;
      }
      if (total < totalTrips)
      {
        start = mid + 1;
      }
      else
      {
        end = mid;
      }
    }

    return (long long)start;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.minimumTime(*new vector<int>{1, 2, 3}, 5);
  auto result2 = solution.minimumTime(*new vector<int>{2}, 1);
}