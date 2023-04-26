// https://leetcode.com/problems/add-digits/
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
  int addDigits(int num)
  {
    while (num >= 10)
    {
      int t = num;
      int sum = 0;
      while (t > 0)
      {
        sum += t % 10;
        t /= 10;
      }

      num = sum;
    }

    return num;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.addDigits(38);
  int result2 = solution.addDigits(0);
  int result3 = solution.addDigits(10);
}