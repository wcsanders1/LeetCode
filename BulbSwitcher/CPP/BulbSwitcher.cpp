// https://leetcode.com/problems/bulb-switcher/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int bulbSwitch(int n)
  {
    return sqrt(n);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.bulbSwitch(3);
  int result2 = solution.bulbSwitch(0);
  int result3 = solution.bulbSwitch(1);
  int result4 = solution.bulbSwitch(4);
  int result5 = solution.bulbSwitch(11);
}