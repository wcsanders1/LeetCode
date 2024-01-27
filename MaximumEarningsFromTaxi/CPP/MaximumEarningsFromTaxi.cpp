// https://leetcode.com/problems/maximum-earnings-from-taxi/description/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

struct Trip
{
  int start;
  int end;
  int tip;
};

class Solution
{
public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
  {
    vector<Trip> trips;
    for (auto &r : rides)
    {
      Trip t;
      t.start = r[0];
      t.end = r[1];
      t.tip = r[2];
      trips.push_back(t);
    }

    auto sortByStart = [](const Trip &t1, const Trip &t2)
    {
      return t1.start < t2.start;
    };

    sort(trips.begin(), trips.end(), sortByStart);

    vector<long long> dp(rides.size() + 1, 0);
    for (int i = trips.size() - 1; i >= 0; i--)
    {
      auto &t = trips[i];
      long long current = (t.end - t.start) + t.tip;
      int nextBestIndex = getNextBestIndex(trips, i + 1, t.end, trips.size() - 1);
      if (nextBestIndex > -1)
      {
        current += dp[nextBestIndex];
      }

      dp[i] = max(dp[i + 1], current);
    }

    return dp[0];
  }

private:
  int getNextBestIndex(vector<Trip> &trips, int startIndex, int value, int endIndex)
  {
    if (startIndex > endIndex)
    {
      return -1;
    }

    int mid = (startIndex + endIndex) / 2;
    if (trips[mid].start < value)
    {
      return getNextBestIndex(trips, mid + 1, value, endIndex);
    }

    int v = getNextBestIndex(trips, startIndex, value, mid - 1);
    return v == -1 ? mid : v;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maxTaxiEarnings(5, *new vector<vector<int>>{{2, 5, 4}, {1, 5, 1}});                                                                                                // 7
  auto result2 = solution.maxTaxiEarnings(20, *new vector<vector<int>>{{1, 6, 1}, {3, 10, 2}, {10, 12, 3}, {11, 12, 2}, {12, 15, 2}, {13, 18, 1}});                                          // 20
  auto result3 = solution.maxTaxiEarnings(20, *new vector<vector<int>>{{2, 3, 6}, {8, 9, 8}, {5, 9, 7}, {8, 9, 1}, {2, 9, 2}, {9, 10, 6}, {7, 10, 10}, {6, 7, 9}, {4, 9, 7}, {2, 3, 1}});    // 33
  auto result4 = solution.maxTaxiEarnings(10, *new vector<vector<int>>{{5, 6, 10}, {1, 5, 3}, {7, 9, 6}, {2, 6, 2}, {5, 6, 4}, {4, 10, 8}, {8, 10, 9}, {5, 10, 1}, {9, 10, 5}, {1, 6, 10}}); // 32
}