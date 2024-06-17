// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool judgeSquareSum(int c)
  {
    if (c <= 2)
    {
      return true;
    }

    long long start = 0;
    long long end = sqrt(c);

    while (start <= end)
    {
      long long t = (start * start) + (end * end);
      if (t == c)
      {
        return true;
      }
      else if (t > c)
      {
        end--;
      }
      else
      {
        start++;
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.judgeSquareSum(5);         // true
  bool result2 = solution.judgeSquareSum(3);         // false
  bool result3 = solution.judgeSquareSum(999999999); // false
  bool result4 = solution.judgeSquareSum(4);         // true
  bool result5 = solution.judgeSquareSum(1);         // true
}