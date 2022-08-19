// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches)
  {
    vector<int> losses = vector<int>(100001, -1);

    for (vector<int> match : matches)
    {
      int winner = match[0];
      int loser = match[1];

      if (losses[winner] == -1)
      {
        losses[winner] = 0;
      }

      if (losses[loser] == -1)
      {
        losses[loser] = 1;
      }
      else
      {
        losses[loser]++;
      }
    }

    vector<int> noLosses;
    vector<int> oneLoss;

    for (int i = 1; i < losses.size(); i++)
    {
      if (losses[i] == 0)
      {
        noLosses.push_back(i);
      }

      if (losses[i] == 1)
      {
        oneLoss.push_back(i);
      }
    }

    return vector<vector<int>>{noLosses, oneLoss};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findWinners(*new vector<vector<int>>{
      vector<int>{1, 3},
      vector<int>{2, 3},
      vector<int>{3, 6},
      vector<int>{5, 6},
      vector<int>{5, 7},
      vector<int>{4, 5},
      vector<int>{4, 8},
      vector<int>{4, 9},
      vector<int>{10, 4},
      vector<int>{10, 9}});

  auto result2 = solution.findWinners(*new vector<vector<int>>{
      vector<int>{2, 3},
      vector<int>{1, 3},
      vector<int>{5, 4},
      vector<int>{6, 4}});
}