// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> minBitwiseArray(vector<int> &nums)
  {
    vector<int> answer(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];
      if (n == 2)
      {
        continue;
      }

      int a = 0;
      n = n >> 1;
      int pos = 0;
      bool shift = false;
      while (n > 0)
      {
        int b = n & 1;
        if (b == 0)
        {
          if (!shift)
          {
            pos += 2;
            shift = true;
          }
          else
          {
            pos++;
          }
        }
        else
        {
          int m = 1 << pos;
          a = a | m;
          pos++;
        }
        n = n >> 1;
      }
      answer[i] = a;
    }

    return answer;
  }
};