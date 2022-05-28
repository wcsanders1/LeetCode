// https://leetcode.com/problems/minimum-sideway-jumps/
#include <vector>

using namespace std;

class Solution
{
public:
  int minSideJumps(vector<int> &obstacles)
  {
    return getMinJumps(obstacles, 0, 2);
  }

private:
  int getMinJumps(vector<int> &obstacles, int index, int lane, int jumps = 0)
  {
    if (index == obstacles.size() - 1)
    {
      return jumps;
    }

    if (obstacles[index + 1] != lane)
    {
      return getMinJumps(obstacles, index + 1, lane, jumps);
    }

    int m = INT32_MAX;
    for (int i = 1; i <= 3; i++)
    {
      if (i == lane)
      {
        continue;
      }

      if (obstacles[index] != i)
      {
        m = min(m, getMinJumps(obstacles, index + 1, i, jumps + 1));
      }
    }

    return m;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSideJumps(*new vector<int>{0, 1, 2, 3, 0});    // 2
  int result2 = solution.minSideJumps(*new vector<int>{0, 1, 1, 3, 3, 0}); // 0
  int result3 = solution.minSideJumps(*new vector<int>{0, 2, 1, 0, 3, 0}); // 2
}