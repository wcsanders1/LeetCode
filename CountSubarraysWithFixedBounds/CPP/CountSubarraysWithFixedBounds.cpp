// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
// NOT MINE: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/2708099/java-c-python-sliding-window-with-explanation/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    int iMin = -1;
    int iMax = -1;
    int iBad = -1;
    long long total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];
      if (num < minK || num > maxK)
      {
        iBad = i;
      }

      if (num == minK)
      {
        iMin = i;
      }

      if (num == maxK)
      {
        iMax = i;
      }

      total += max(0, min(iMax, iMin) - iBad);
    }

    return total;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.countSubarrays(*new vector<int>{1, 3, 5, 2, 7, 5}, 1, 5);
  auto result2 = solution.countSubarrays(*new vector<int>{1, 1, 1, 1}, 1, 1);
}