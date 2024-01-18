// https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1)
    {
      return 1;
    }

    if (n == 2)
    {
      return 2;
    }

    int n1 = 1;
    int n2 = 2;
    int answer = 0;

    for (int i = 3; i <= n; i++)
    {
      answer = n1 + n2;
      n1 = n2;
      n2 = answer;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.climbStairs(1);
  int result2 = solution.climbStairs(2);
  int result3 = solution.climbStairs(3);
  int result4 = solution.climbStairs(4);
  int result5 = solution.climbStairs(5);
}