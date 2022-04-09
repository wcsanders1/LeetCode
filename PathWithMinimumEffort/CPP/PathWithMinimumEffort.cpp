// https://leetcode.com/problems/path-with-minimum-effort/
#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution
{
public:
  int minimumEffortPath(vector<vector<int>> &heights)
  {
    vector<vector<int>> efforts(heights.size(), vector<int>(heights[0].size(), INT_MAX));
    efforts[0][0] = 0;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<vector<int>> q;
    q.emplace(vector<int>{0, 0});
    while (!q.empty())
    {
      vector<int> node = q.front();
      q.pop();

      int row = node[0];
      int col = node[1];
      int height = heights[row][col];
      int priorEffort = efforts[row][col];
      for (vector<int> direction : directions)
      {
        int nRow = row + direction[0];
        int nCol = col + direction[1];
        if (nRow >= 0 && nRow < heights.size() && nCol >= 0 && nCol < heights[0].size())
        {
          int nHeight = heights[nRow][nCol];
          int effort = efforts[nRow][nCol];
          int nEffort = abs(nHeight - height);
          int curEffort = max(nEffort, priorEffort);
          if (curEffort < effort)
          {
            efforts[nRow][nCol] = curEffort;
            q.emplace(vector<int>{nRow, nCol});
          }
        }
      }
    }

    return efforts[efforts.size() - 1][efforts[0].size() - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumEffortPath(*new vector<vector<int>>{vector<int>{1, 2, 2}, vector<int>{3, 8, 2}, vector<int>{5, 3, 5}});
  int result2 = solution.minimumEffortPath(*new vector<vector<int>>{vector<int>{1, 2, 3}, vector<int>{3, 8, 4}, vector<int>{5, 3, 5}});
  int result3 = solution.minimumEffortPath(*new vector<vector<int>>{vector<int>{1, 2, 1, 1, 1}, vector<int>{1, 2, 1, 2, 1}, vector<int>{1, 2, 1, 2, 1}, vector<int>{1, 2, 1, 2, 1}, vector<int>{1, 1, 1, 2, 1}});
  int result4 = solution.minimumEffortPath(*new vector<vector<int>>{vector<int>{3}});
  int result5 = solution.minimumEffortPath(*new vector<vector<int>>{vector<int>{1, 10, 6, 7, 9, 10, 4, 9}});
}