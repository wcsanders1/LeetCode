// https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  int tribonacci(int n)
  {
    if (n == 0)
    {
      return 0;
    }

    if (n == 1 || n == 2)
    {
      return 1;
    }

    int t1 = 0;
    int t2 = 1;
    int t3 = 1;

    for (int i = 3; i <= n; i++)
    {
      int t4 = t1 + t2 + t3;
      t1 = t2;
      t2 = t3;
      t3 = t4;
    }

    return t3;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.tribonacci(4);
  int result2 = solution.tribonacci(25);
}