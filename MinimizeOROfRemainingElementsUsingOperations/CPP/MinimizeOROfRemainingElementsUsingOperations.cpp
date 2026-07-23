// https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/description/
// NOT MINE: https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/solutions/4637168/simple-c-solution/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minOrAfterOperations(vector<int> &nums, int k)
  {
    const int n = nums.size();
    const int V = (1 << 30) - 1;
    const int m = *max_element(nums.begin(), nums.end());
    int mask = 0;
    for (int t = 29; t >= 0; t--)
    {
      const int p = 1 << t;
      mask |= p;
      if (p > m)
      {
        continue;
      }
      int s = n;
      bool mark = false;
      for (int i = 0; i < n && s > k; s--)
      {
        int num = nums[i++];
        for (; i < n && ((num & mask) > 0); num &= nums[i++])
          ;
        if ((num & mask) > 0)
        {
          break;
        }
        mark = true;
      }
      if (!mark || s > k)
      {
        mask ^= p;
      }
    }

    return V ^ mask;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOrAfterOperations(*new vector<int>{3, 5, 3, 2, 7}, 2);
  int result2 = solution.minOrAfterOperations(*new vector<int>{7, 3, 15, 14, 2, 8}, 4);
  int result3 = solution.minOrAfterOperations(*new vector<int>{10, 7, 10, 3, 9, 14, 9, 4}, 1);
}