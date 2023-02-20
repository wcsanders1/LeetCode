// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
  {
    vector<vector<int>> answer;

    int p1 = 0;
    int p2 = 0;

    while (p1 < nums1.size() || p2 < nums2.size())
    {
      if (p1 < nums1.size() && p2 < nums2.size())
      {
        if (nums1[p1][0] == nums2[p2][0])
        {
          answer.push_back({nums1[p1][0], nums1[p1][1] + nums2[p2][1]});
          p1++;
          p2++;
        }
        else if (nums1[p1][0] > nums2[p2][0])
        {
          answer.push_back({nums2[p2][0], nums2[p2][1]});
          p2++;
        }
        else
        {
          answer.push_back({nums1[p1][0], nums1[p1][1]});
          p1++;
        }
      }
      else if (p1 < nums1.size())
      {
        answer.push_back({nums1[p1][0], nums1[p1][1]});
        p1++;
      }
      else
      {
        answer.push_back({nums2[p2][0], nums2[p2][1]});
        p2++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.mergeArrays(*new vector<vector<int>>{{1, 2}, {2, 3}, {4, 5}}, *new vector<vector<int>>{{1, 4}, {3, 2}, {4, 1}});
  auto result2 = solution.mergeArrays(*new vector<vector<int>>{{2, 4}, {3, 6}, {5, 5}}, *new vector<vector<int>>{{1, 3}, {4, 3}});
}