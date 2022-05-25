// https://leetcode.com/problems/gas-station/
#include <vector>

using namespace std;

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int totalCost = 0;
    int totalGas = 0;
    vector<int> possibleStarts;

    for (int i = 0; i < gas.size(); i++)
    {
      totalGas += gas[i];
      totalCost += cost[i];
      if (gas[i] >= cost[i])
      {
        possibleStarts.push_back(i);
      }
    }

    if (totalCost > totalGas)
    {
      return -1;
    }

    for (int start : possibleStarts)
    {
      int steps = 0;
      int index = start;
      int currentGas = 0;
      while (steps++ < gas.size())
      {
        if (index == gas.size())
        {
          index = 0;
        }

        currentGas += gas[index] - cost[index];
        if (currentGas < 0)
        {
          break;
        }

        index++;

        if (steps == gas.size())
        {
          return start;
        }
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.canCompleteCircuit(*new vector<int>{1, 2, 3, 4, 5}, *new vector<int>{3, 4, 5, 1, 2}); // 3
  int result2 = solution.canCompleteCircuit(*new vector<int>{2, 3, 4}, *new vector<int>{3, 4, 3});             // -1
  int result3 = solution.canCompleteCircuit(*new vector<int>{5, 1, 2, 3, 4}, *new vector<int>{4, 4, 1, 5, 1}); // 4
  int result4 = solution.canCompleteCircuit(*new vector<int>{5, 8, 2, 8}, *new vector<int>{6, 5, 6, 6});       // 3
}