// https://leetcode.com/problems/dota2-senate/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  string predictPartyVictory(string senate)
  {
    int n = senate.size();
    vector<bool> hasRights(n, true);
    queue<int> rq;
    queue<int> dq;
    for (int i = 0; i < n; i++)
    {
      if (senate[i] == 'R')
      {
        rq.push(i);
      }
      else
      {
        dq.push(i);
      }
    }

    int index = 0;
    while (!rq.empty() && !dq.empty())
    {
      if (!hasRights[index])
      {
        index = getNextIndex(index, n);
        continue;
      }

      int nextR = rq.front();
      rq.pop();

      int nextD = dq.front();
      dq.pop();

      if (senate[index] == 'R')
      {
        hasRights[nextD] = false;
        rq.push(nextR);
      }
      else
      {
        hasRights[nextR] = false;
        dq.push(nextD);
      }

      index = getNextIndex(index, n);
    }

    return rq.empty() ? "Dire" : "Radiant";
  }

private:
  int getNextIndex(int index, int n)
  {
    if (++index < n)
    {
      return index;
    }

    return 0;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.predictPartyVictory("RD");
  string result2 = solution.predictPartyVictory("RDD");
  string result3 = solution.predictPartyVictory("DRRDRDRDRDDRDRDR"); // Radiant
}