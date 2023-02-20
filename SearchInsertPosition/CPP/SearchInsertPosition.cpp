// https://leetcode.com/problems/search-insert-position/description/
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] >= target)
      {
        return i;
      }
    }

    return nums.size();
  }
};

int main()
{
  Solution solution;

  int result1 = solution.searchInsert(*new vector<int>{1, 3, 5, 6}, 5);
  int result2 = solution.searchInsert(*new vector<int>{1, 3, 5, 6}, 2);
  int result3 = solution.searchInsert(*new vector<int>{1, 3, 5, 6}, 7);
}