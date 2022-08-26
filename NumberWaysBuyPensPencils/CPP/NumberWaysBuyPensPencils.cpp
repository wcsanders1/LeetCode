// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
#include <vector>

using namespace std;

class Solution
{
public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2)
  {
    int shortest = min(cost1, cost2);
    int longest = max(cost1, cost2);

    long long answer = 0;

    while (total > 0)
    {
      int ways = total / shortest;
      if (ways > 0)
      {
        answer += ways + 1;
      }
      total -= longest;
    }

    return ++answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.waysToBuyPensPencils(20, 10, 5); // 9
  auto result2 = solution.waysToBuyPensPencils(5, 10, 10); // 1
  auto result3 = solution.waysToBuyPensPencils(10, 9, 99); // 2
}