// https://leetcode.com/problems/champagne-tower/description/
// NOT MINE: https://leetcode.com/problems/champagne-tower/solutions/127430/champagne-tower/?orderBy=most_votes
#include <vector>

using namespace std;

class Solution
{
public:
  double champagneTower(int poured, int query_row, int query_glass)
  {
    vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0));
    dp[0][0] = poured;

    for (int r = 0; r <= query_row; r++)
    {
      for (int c = 0; c <= r; c++)
      {
        double amount = (dp[r][c] - 1.0) / 2.0;
        if (amount > 0)
        {
          dp[r + 1][c] += amount;
          dp[r + 1][c + 1] += amount;
        }
      }
    }

    return min(1.0, dp[query_row][query_glass]);
  }
};

int main()
{
  Solution solution;

  double result1 = solution.champagneTower(1, 1, 1);           // 0
  double result2 = solution.champagneTower(2, 1, 1);           // .5
  double result3 = solution.champagneTower(100000009, 33, 17); // 1
  double result4 = solution.champagneTower(4, 1, 0);
  double result5 = solution.champagneTower(4, 1, 1);
  double result6 = solution.champagneTower(4, 2, 0);
  double result7 = solution.champagneTower(4, 2, 1);
  double result8 = solution.champagneTower(4, 2, 2);
  double result9 = solution.champagneTower(5, 2, 0);
  double result10 = solution.champagneTower(5, 2, 1);
  double result11 = solution.champagneTower(5, 2, 2);
  double result12 = solution.champagneTower(0, 0, 0);
  double result13 = solution.champagneTower(25, 6, 1); // .1875
}