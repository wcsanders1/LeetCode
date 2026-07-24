// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minimizeMax(vector<int> &nums, int p)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int start = 0;
    int end = nums[n - 1] - nums[0];

    return getMax(nums, p, start, end);
  }

private:
  int getMax(vector<int> &nums, int p, int start, int end)
  {
    if (start > end)
    {
      return start;
    }

    int mid = (end + start) / 2;
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i + 1] - nums[i] <= mid)
      {
        count++;
        i++;
      }
    }

    return count >= p ? getMax(nums, p, start, mid - 1) : getMax(nums, p, mid + 1, end);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimizeMax(*new vector<int>{10, 1, 2, 7, 1, 3}, 2);            // 1
  int result2 = solution.minimizeMax(*new vector<int>{4, 2, 1, 2}, 1);                   // 0
  int result3 = solution.minimizeMax(*new vector<int>{8, 9, 1, 5, 4, 3, 6, 4, 3, 7}, 4); // 1
  int result4 = solution.minimizeMax(*new vector<int>{3, 4, 2, 3, 2, 1, 2}, 3);          // 1
}