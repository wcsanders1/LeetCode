// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2)
  {
    int s1 = 0;
    int s2 = 0;

    while (s1 < nums1.size() || s2 < nums2.size())
    {
      if (nums1[s1] == nums2[s2])
      {
        return nums1[s1];
      }

      if (nums1[s1] < nums2[s2])
      {
        if (++s1 == nums1.size())
        {
          return -1;
        }
      }
      else
      {
        if (++s2 == nums2.size())
        {
          return -1;
        }
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.getCommon(*new vector<int>{1, 2, 3}, *new vector<int>{2, 4});
  int result2 = solution.getCommon(*new vector<int>{1, 2, 3, 6}, *new vector<int>{2, 3, 4, 5});
  int result3 = solution.getCommon(*new vector<int>{1, 2, 3, 6}, *new vector<int>{4, 6});
}