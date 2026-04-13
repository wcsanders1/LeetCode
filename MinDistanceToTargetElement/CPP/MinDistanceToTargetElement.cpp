// https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13
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
  int getMinDistance(vector<int> &nums, int target, int start)
  {
    int mn = INT32_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == target)
      {
        mn = min(mn, abs(i - start));
      }
    }

    return mn;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.getMinDistance(*new vector<int>{1, 2, 3, 4, 5}, 5, 3);
  int result2 = solution.getMinDistance(*new vector<int>{1}, 1, 0);
  int result3 = solution.getMinDistance(*new vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1}, 1, 0);
}