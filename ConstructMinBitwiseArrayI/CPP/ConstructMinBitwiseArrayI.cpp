// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20
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

int main()
{
  Solution solution;

  vector<int> result1 = solution.minBitwiseArray(*new vector<int>{2, 3, 5, 7});
  vector<int> result2 = solution.minBitwiseArray(*new vector<int>{11, 13, 31});
  vector<int> result3 = solution.minBitwiseArray(*new vector<int>{41});
}