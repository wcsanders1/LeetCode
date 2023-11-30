// https://leetcode.com/problems/number-of-1-bits/?envType=daily-question&envId=2023-11-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int answer = 0;
    while (n > 0)
    {
      answer += n & 1;
      n >>= 1;
    }

    return answer;
  }
};