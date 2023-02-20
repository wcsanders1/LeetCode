// https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
  int squareFreeSubsets(vector<int> &nums)
  {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int temp = getCount(1, nums, 0);
      answer = (answer + temp) % 100000007;
    }

    return answer;
  }

private:
  int getCount(int mult, vector<int> &nums, int start)
  {
    if (start >= nums.size())
    {
      return 0;
    }

    int count = 0;
    for (int i = start; i < nums.size(); i++)
    {
      double m = (double)mult * (double)nums[i];
      double s = sqrt(m);
      if (trunc(s) == s)
      {
        if (mult * nums[i])
        {
        }
      }
    }

    return count;
  }
};