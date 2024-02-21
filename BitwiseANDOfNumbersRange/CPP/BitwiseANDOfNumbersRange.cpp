// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int rangeBitwiseAnd(int left, int right)
  {
    int mask1 = INT32_MAX;
    int mask2 = 1;
    int answer = left;
    for (int i = 1; i <= 32; i++)
    {
      int mask = mask1 ^ mask2;
      int n = right & mask;
      if (n >= left)
      {
        answer &= n;
      }
      mask2 <<= 1;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.rangeBitwiseAnd(5, 7);
  int result2 = solution.rangeBitwiseAnd(0, 0);
  int result3 = solution.rangeBitwiseAnd(1, 2147483647);
  int result4 = solution.rangeBitwiseAnd(30000, 2147483643);
  int result5 = solution.rangeBitwiseAnd(1, 2);
}