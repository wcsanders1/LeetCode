// https://leetcode.com/problems/house-robber-iv/
// NOT MINE: https://leetcode.com/problems/house-robber-iv/solutions/3143697/java-c-python-binary-search-o-1-space/?orderBy=most_votes
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
  int minCapability(vector<int> &nums, int k)
  {
    int left = 1;
    int right = 1e9;

    while (left < right)
    {
      int mid = (left + right) / 2;
      int take = 0;

      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] <= mid)
        {
          take++;
          i++;
        }
      }

      if (take >= k)
      {
        right = mid;
      }
      else
      {
        left = mid + 1;
      }
    }

    return left;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCapability(*new vector<int>{2, 3, 5, 9}, 2);
  int result2 = solution.minCapability(*new vector<int>{2, 7, 9, 3, 1}, 2);
}