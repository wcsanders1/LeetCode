// https://leetcode.com/problems/champagne-tower/description/
#include <vector>

using namespace std;

struct Glass
{
  double increaseInterval;
  double fullness;
  Glass(double i, double f) : increaseInterval(i), fullness(f) {}
};

class Solution
{
public:
  double champagneTower(int poured, int query_row, int query_glass)
  {
    vector<Glass> glasses;
    glasses.push_back(Glass(1, poured-- > 0 ? 1 : 0));
    int start = 0;
    int end = 0;

    while (--query_row > 0)
    {
      int newRow = (end - start) + 1;
      for (int i = 0; i < newRow; i++)
      {
        double increaseInterval = 0;
        double fullness = 0;
        if (i == 0 || i == newRow - 1)
        {
          increaseInterval = glasses[start].increaseInterval / 2;
          fullness = poured-- > 0 && glasses[start].fullness == 1 ? increaseInterval : 0;
        }
        else
        {
        }
        glasses.push_back(Glass(increaseInterval, fullness));
      }

      start = end + 1;
      end += newRow;
    }
  }
};