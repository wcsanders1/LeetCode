// https://leetcode.com/problems/sign-of-the-product-of-an-array/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  int arraySign(vector<int> &nums)
  {
    bool isPositive = true;
    for (int &n : nums)
    {
      if (n == 0)
      {
        return 0;
      }

      if (n < 0)
      {
        isPositive = !isPositive;
      }
    }

    return isPositive ? 1 : -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.arraySign(*new vector<int>{-1, -2, -3, -4, 3, 2, 1});
  int result2 = solution.arraySign(*new vector<int>{1, 5, 0, 2, -3});
  int result3 = solution.arraySign(*new vector<int>{-1, 1, -1, 1, -1});
}