// https://leetcode.com/problems/can-i-win/description/
// NOT MINE: https://leetcode.com/problems/can-i-win/solutions/95320/clean-c-beat-98-4-dfs-with-early-termination-check-detailed-explanation/?orderBy=most_votes
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal)
  {
    if (desiredTotal < 2)
    {
      return true;
    }

    int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (sum < desiredTotal)
    {
      return false;
    }

    if (sum == desiredTotal)
    {
      return maxChoosableInteger % 2 == 1;
    }

    unordered_map<int, bool> stateMap;
    return dfs(maxChoosableInteger, desiredTotal, 0, stateMap);
  }

private:
  bool dfs(int maxChooseableInteger, int desiredTotal, int state, unordered_map<int, bool> &stateMap)
  {
    if (stateMap.count(state) != 0)
    {
      return stateMap[state];
    }

    if (desiredTotal <= 0)
    {
      return false;
    }

    for (int i = 0; i < maxChooseableInteger; i++)
    {
      int num = 1 << i;
      if (!(state & num) && !dfs(maxChooseableInteger, desiredTotal - i - 1, state | num, stateMap))
      {
        stateMap[state] = true;
        return true;
      }
    }

    stateMap[state] = false;
    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canIWin(10, 11);
  bool result2 = solution.canIWin(10, 0);
  bool result3 = solution.canIWin(10, 1);
  bool result4 = solution.canIWin(4, 6);
}