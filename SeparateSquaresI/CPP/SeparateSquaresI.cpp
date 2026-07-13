// https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13
// NOT MINE: https://leetcode.com/problems/separate-squares-i/solutions/6426084/binary-search-by-fahad_mubeen-k83n/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  double helper(double line, vector<vector<int>> &squares)
  {
    double aAbove = 0, aBelow = 0;
    int n = squares.size();
    for (int i = 0; i < n; i++)
    {
      int x = squares[i][0], y = squares[i][1];
      int l = squares[i][2];
      double total = (double)l * l;

      if (line <= y)
      {
        aAbove += total;
      }
      else if (line >= y + l)
      {
        aBelow += total;
      }
      else
      {
        // The line intersects the square.
        double aboveHeight = (y + l) - line;
        double belowHeight = line - y;
        aAbove += l * aboveHeight;
        aBelow += l * belowHeight;
      }
    }
    return aAbove - aBelow;
  }

  double separateSquares(vector<vector<int>> &squares)
  {
    double lo = 0, hi = 2 * 1e9;

    for (int i = 0; i < 60; i++)
    {
      double mid = (lo + hi) / 2.0;
      double diff = helper(mid, squares);

      if (diff > 0)
        lo = mid;
      else
        hi = mid;
    }

    return hi;
  }
};

int main()
{
  Solution solution;

  double result1 = solution.separateSquares(*new vector<vector<int>>{{0, 0, 1}, {2, 2, 1}});
  double result2 = solution.separateSquares(*new vector<vector<int>>{{0, 0, 2}, {1, 1, 1}});
  double result3 = solution.separateSquares(*new vector<vector<int>>{{23, 29, 3}, {28, 29, 4}}); // 30.78571
}