// https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points)
  {
    int total = 0;
    for (int i = 1; i < points.size(); i++)
    {
      total += max(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
    }

    return total;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minTimeToVisitAllPoints(*new vector<vector<int>>{{1, 1}, {3, 4}, {-1, 0}});
  int result2 = solution.minTimeToVisitAllPoints(*new vector<vector<int>>{{3, 2}, {-2, 2}});
}