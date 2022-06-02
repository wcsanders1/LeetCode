// https://leetcode.com/problems/single-number-ii/
// not mine
// good explanation: https://leetcode.com/problems/single-number-ii/discuss/43368/constant-space-solution
#include <vector>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int one = 0, two = 0, three = 0;
    for (int i : nums)
    {
      two |= one & i;
      one ^= i;
      three = one & two;
      one ^= three;
      two ^= three;
    }
    return one;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.singleNumber(*new vector<int>{2, 2, 3, 2});
  int result2 = solution.singleNumber(*new vector<int>{0, 1, 0, 1, 0, 1, 99});
  int result3 = solution.singleNumber(*new vector<int>{1, 2, 3, 1, 2, 5, 3, 1, 2, 3});
  int result4 = solution.singleNumber(*new vector<int>{1, 2, 1, 2, 4, 1, 2});
  int result5 = solution.singleNumber(*new vector<int>{1, 2, 1, 2, 0, 1, 2});
}