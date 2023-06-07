// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// NOT MINE: https://leetcode.com/problems/check-if-it-is-a-straight-line/solutions/620035/c-simple-6-lines-of-code-o-n/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  bool checkStraightLine(vector<vector<int>> &coordinates)
  {
    int dY = coordinates[1][1] - coordinates[0][1];
    int dX = coordinates[1][0] - coordinates[0][0];
    for (int i = 2; i < coordinates.size(); i++)
    {
      auto p = coordinates[i];
      if (dX * (p[1] - coordinates[0][1]) != dY * (p[0] - coordinates[0][0]))
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.checkStraightLine(*new vector<vector<int>>{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}});
  bool result2 = solution.checkStraightLine(*new vector<vector<int>>{{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}});
  bool result3 = solution.checkStraightLine(*new vector<vector<int>>{{0, 0}, {0, 1}, {0, -1}});
  bool result4 = solution.checkStraightLine(*new vector<vector<int>>{{2, 1}, {4, 2}, {6, 3}});
}