// https://leetcode.com/problems/single-number-iii/
// not mine
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    long diff = 0;
    for (int num : nums)
    {
      diff ^= num;
    }

    diff &= -diff;

    vector<int> result(2, 0);
    for (int num : nums)
    {
      if ((num & diff) == 0)
      {
        result[0] ^= num;
      }
      else
      {
        result[1] ^= num;
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.singleNumber(*new vector<int>{1, 2, 1, 3, 2, 5});
  vector<int> result2 = solution.singleNumber(*new vector<int>{-1, 0});
  vector<int> result3 = solution.singleNumber(*new vector<int>{4, 5, 6, 4, 5, 7});
}