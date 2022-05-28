// https://leetcode.com/problems/minimum-sideway-jumps/
#include <vector>

using namespace std;

class Solution
{
public:
  int minSideJumps(vector<int> &obstacles)
  {
    vector<int> lane1(obstacles.size(), 0);
    vector<int> lane2(obstacles.size(), 0);
    vector<int> lane3(obstacles.size(), 0);

    for (int i = obstacles.size() - 2; i >= 0; i--)
    {
      int obstacle = obstacles[i + 1];
      if (obstacle == 0)
      {
        lane1[i] = lane1[i + 1];
        lane2[i] = lane2[i + 1];
        lane3[i] = lane3[i + 1];
        continue;
      }

      if (obstacle == 1)
      {
        int jumps = INT32_MAX;
        if (obstacles[i] != 2)
        {
          jumps = min(jumps, lane2[i + 1] + 1);
        }

        if (obstacles[i] != 3)
        {
          jumps = min(jumps, lane3[i + 1] + 1);
        }

        lane1[i] = jumps;
        lane2[i] = lane2[i + 1];
        lane3[i] = lane3[i + 1];
      }

      if (obstacle == 2)
      {
        int jumps = INT32_MAX;
        if (obstacles[i] != 1)
        {
          jumps = min(jumps, lane1[i + 1] + 1);
        }

        if (obstacles[i] != 3)
        {
          jumps = min(jumps, lane3[i + 1] + 1);
        }

        lane2[i] = jumps;
        lane1[i] = lane1[i + 1];
        lane3[i] = lane3[i + 1];
      }

      if (obstacle == 3)
      {
        int jumps = INT32_MAX;
        if (obstacles[i] != 2)
        {
          jumps = min(jumps, lane2[i + 1] + 1);
        }

        if (obstacles[i] != 1)
        {
          jumps = min(jumps, lane1[i + 1] + 1);
        }

        lane3[i] = jumps;
        lane2[i] = lane2[i + 1];
        lane1[i] = lane1[i + 1];
      }
    }

    return lane2[0];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSideJumps(*new vector<int>{0, 1, 2, 3, 0});    // 2
  int result2 = solution.minSideJumps(*new vector<int>{0, 1, 1, 3, 3, 0}); // 0
  int result3 = solution.minSideJumps(*new vector<int>{0, 2, 1, 0, 3, 0}); // 2
}