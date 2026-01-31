// https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-13
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int sumFourDivisors(vector<int> &nums)
  {
    int sum = 0;
    for (int num : nums)
    {
      sum += getDivSum(num);
    }

    return sum;
  }

private:
  int getDivSum(int num)
  {
    if (num < 5)
    {
      return 0;
    }

    int divs = 2;
    int sum = 1 + num;
    for (int i = num / 2; i > 1; i--)
    {
      if (num % i == 0)
      {
        divs++;
        sum += i;
      }
      if (divs > 4)
      {
        return 0;
      }
    }

    return divs == 4 ? sum : 0;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.sumFourDivisors(*new vector<int>{21, 4, 7});
  int result2 = solution.sumFourDivisors(*new vector<int>{21, 21});
  int result3 = solution.sumFourDivisors(*new vector<int>{1, 2, 3, 4, 5});
}