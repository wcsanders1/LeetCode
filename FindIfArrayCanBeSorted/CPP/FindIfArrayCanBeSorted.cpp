// https://leetcode.com/problems/find-if-array-can-be-sorted/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool canSortArray(vector<int> &nums)
  {
    int n = nums.size();
    bool isSorted = false;
    bool shifted = true;
    while (!isSorted && shifted)
    {
      isSorted = true;
      shifted = false;
      for (int i = 0; i < n - 1; i++)
      {
        if (nums[i] > nums[i + 1])
        {
          isSorted = false;
          bool canShift = getBits(nums[i]) == getBits(nums[i + 1]);
          if (canShift)
          {
            shifted = true;
            int t = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = t;
          }
        }
      }
    }

    return isSorted;
  }

private:
  int getBits(int n)
  {
    int bits = 0;
    while (n > 0)
    {
      if (n & 1)
      {
        bits++;
      }
      n = n >> 1;
    }
    return bits;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canSortArray(*new vector<int>{8, 4, 2, 30, 15});
  bool result2 = solution.canSortArray(*new vector<int>{1, 2, 3, 4, 5});
  bool result3 = solution.canSortArray(*new vector<int>{3, 16, 8, 4, 2});
}