// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
  {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    int mh = hBars.size() == 0 ? 1 : 2;
    int mv = vBars.size() == 0 ? 1 : 2;

    int cur = 2;
    for (int i = 1; i < hBars.size(); i++)
    {
      if (hBars[i] == hBars[i - 1] + 1)
      {
        cur++;
      }
      else
      {
        cur = 2;
      }
      mh = max(mh, cur);
    }

    cur = 2;
    for (int i = 1; i < vBars.size(); i++)
    {
      if (vBars[i] == vBars[i - 1] + 1)
      {
        cur++;
      }
      else
      {
        cur = 2;
      }
      mv = max(mv, cur);
    }

    int mn = min(mh, mv);

    return mn * mn;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximizeSquareHoleArea(2, 1, *new vector<int>{2, 3}, *new vector<int>{2});
  int result2 = solution.maximizeSquareHoleArea(1, 1, *new vector<int>{2}, *new vector<int>{2});
  int result3 = solution.maximizeSquareHoleArea(2, 3, *new vector<int>{2, 3}, *new vector<int>{2, 4});
  int result4 = solution.maximizeSquareHoleArea(14, 4, *new vector<int>{13}, *new vector<int>{3, 4, 5, 2});
  int result5 = solution.maximizeSquareHoleArea(1, 1000000000, *new vector<int>{2}, *new vector<int>{1000000001});
  int result6 = solution.maximizeSquareHoleArea(3, 3, *new vector<int>{2, 3}, *new vector<int>{2, 3});
  int result7 = solution.maximizeSquareHoleArea(4, 4, *new vector<int>{2, 3, 4, 5}, *new vector<int>{2, 3, 4, 5});
}