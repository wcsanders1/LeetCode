// https://leetcode.com/problems/ugly-number-ii/description/
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
  int nthUglyNumber(int n)
  {
    vector<int> nums{1};
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    for (int i = 0; i < n; i++)
    {
      int res2 = nums[p2] * 2;
      int res3 = nums[p3] * 3;
      int res5 = nums[p5] * 5;
      while (res2 <= nums[i])
      {
        res2 = nums[++p2] * 2;
      }

      while (res3 <= nums[i])
      {
        res3 = nums[++p3] * 3;
      }

      while (res5 <= nums[i])
      {
        res5 = nums[++p5] * 5;
      }

      if (res2 <= res3 && res2 <= res5)
      {
        nums.push_back(res2);
        p2++;
      }
      else if (res3 <= res2 && res3 <= res5)
      {
        nums.push_back(res3);
        p3++;
      }
      else
      {
        nums.push_back(res5);
        p5++;
      }
    }

    return nums[n - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.nthUglyNumber(10);
  int result2 = solution.nthUglyNumber(1);
}