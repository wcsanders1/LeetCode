// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
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
  int removeDuplicates(vector<int> &nums)
  {
    int start = 0;
    int end = 0;
    int uniques = 1;
    while (end < nums.size())
    {
      while (end < nums.size() && nums[start] == nums[end])
      {
        end++;
      }

      if (end < nums.size() && nums[start] != nums[end])
      {
        uniques++;
        start++;
        nums[start] = nums[end];
      }

      end++;
    }

    return uniques;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.removeDuplicates(*new vector<int>{1, 1, 2});
  int result2 = solution.removeDuplicates(*new vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
}