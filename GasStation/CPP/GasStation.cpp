// https://leetcode.com/problems/gas-station/
// not mine
#include <vector>

using namespace std;

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int start = gas.size() - 1;
    int end = 0;
    int sum = gas[start] - cost[start];
    while (start > end)
    {
      if (sum > 0)
      {
        sum += gas[end] - cost[end];
        end++;
      }
      else
      {
        --start;
        sum += gas[start] - cost[start];
      }
    }

    return sum < 0 ? -1 : start;
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