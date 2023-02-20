// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  int minOperations(int n)
  {
    int answer = 0;

    while (n > 0)
    {
      answer++;
      int a = 1;
      int b = 2;

      while (b <= n)
      {
        a = b;
        b *= 2;
      }

      if (n - a < b - n)
      {
        n = n - a;
      }
      else
      {
        n = b - n;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(39);
  int result2 = solution.minOperations(54);
  int result3 = solution.minOperations(7);
}