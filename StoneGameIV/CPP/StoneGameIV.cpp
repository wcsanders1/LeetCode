// https://leetcode.com/problems/stone-game-iv/description/?envType=daily-question&envId=2026-08-10
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool winnerSquareGame(int n)
  {
    vector<bool> canWin(n + 1, false);
    vector<int> squares;
    canWin[1] = true;
    squares.push_back(1);
    int s1 = 2;
    int s2 = 4;
    for (int i = 2; i <= n; i++)
    {
      if (i < s2)
      {
        for (int &s : squares)
        {
          if (!canWin[i - s])
          {
            canWin[i] = true;
            break;
          }
        }
      }
      else
      {
        canWin[i] = true;
        squares.push_back(s2);
        s1++;
        s2 = s1 * s1;
      }
    }

    return canWin[n];
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.winnerSquareGame(1);
  bool result2 = solution.winnerSquareGame(2);
  bool result3 = solution.winnerSquareGame(4);
  bool result4 = solution.winnerSquareGame(7);
  bool result5 = solution.winnerSquareGame(8);
  bool result6 = solution.winnerSquareGame(44);
}