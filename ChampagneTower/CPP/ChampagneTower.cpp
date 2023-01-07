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
    vector<int> rowStart;
    glasses.push_back(Glass(1, 0));
    int start = 0;
    int rowSize = 1;
    int rows = query_row;

    while (rows-- >= 0)
    {
      rowStart.push_back(start);
      for (int i = 0; i <= rowSize; i++)
      {
        double increaseInterval = (i == 0 || i == rowSize)
                                      ? glasses[start].increaseInterval / 2
                                      : glasses[start].increaseInterval;

        glasses.push_back(Glass(increaseInterval, 0));
      }
      start += ++rowSize;
    }

    while (poured-- > 0)
    {
      double glass = 1;
      while (glass > 0)
      {
      }
    }

    int index = rowStart[query_row] + (query_glass - 1);

    return glasses[index].fullness;
  }
};

int main()
{
  Solution solution;

  // double result1 = solution.champagneTower(1, 1, 1);
  // double result2 = solution.champagneTower(2, 1, 1);
  double result3 = solution.champagneTower(100000009, 33, 17);
}