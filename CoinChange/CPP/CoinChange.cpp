#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    sort(coins.begin(), coins.end());
    int answer = 0;
    while (amount > 0)
    {
      for (int i = coins.size() - 1; i >= 0; i--)
      {
            }
    }

    return answer;
  }
};