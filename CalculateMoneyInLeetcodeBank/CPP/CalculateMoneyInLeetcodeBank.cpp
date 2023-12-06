// https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int totalMoney(int n)
  {
    int day = 1;
    int week = 0;
    int answer = 0;

    while (n-- > 0)
    {
      answer += day++ + week;
      if (day > 7)
      {
        day = 1;
        week++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.totalMoney(4);
  int result2 = solution.totalMoney(10);
  int result3 = solution.totalMoney(20);
  int result4 = solution.totalMoney(1);
}