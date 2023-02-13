// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
// NOT MINE: https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/3174181/two-pointers-2/?orderBy=most_votes
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper)
  {

    sort(nums.begin(), nums.end());

    int start = 0;
    int end = nums.size() - 1;

    long long lessThanUpper = 0;
    while (start < end)
    {
      while (start < end && nums[start] + nums[end] > upper)
      {
        end--;
      }
      lessThanUpper += end - start;
      start++;
    }

    start = 0;
    end = nums.size() - 1;

    long long lessThanLower = 0;
    while (start < end)
    {
      while (start < end && nums[start] + nums[end] > (lower - 1))
      {
        end--;
      }
      lessThanLower += end - start;
      start++;
    }

    return lessThanUpper - lessThanLower;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.countFairPairs(*new vector<int>{0, 1, 7, 4, 4, 5}, 3, 6);
  auto result2 = solution.countFairPairs(*new vector<int>{1, 7, 9, 2, 5}, 11, 11);
  auto result3 = solution.countFairPairs(*new vector<int>{0, 0, 0, 0, 0, 0}, 0, 0);
}