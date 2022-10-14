// https://leetcode.com/problems/escape-the-ghosts/
#include <vector>

using namespace std;

class Solution
{
public:
  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
  {
    int myDistance = abs(target[0]) + abs(target[1]);
    int minGhostDistance = INT32_MAX;

    for (vector<int> g : ghosts)
    {
      minGhostDistance = min(minGhostDistance, abs(g[0] - target[0]) + abs(g[1] - target[1]));
    }

    return myDistance < minGhostDistance;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.escapeGhosts(*new vector<vector<int>>{{1, 0}, {0, 3}}, *new vector<int>{0, 1});
  bool result2 = solution.escapeGhosts(*new vector<vector<int>>{{1, 0}}, *new vector<int>{2, 0});
  bool result3 = solution.escapeGhosts(*new vector<vector<int>>{{2, 0}}, *new vector<int>{1, 0});
}