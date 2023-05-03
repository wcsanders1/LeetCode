// https://leetcode.com/problems/find-the-difference-of-two-arrays/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    vector<int> a1;
    for (const int &n : s1)
    {
      if (s2.count(n) == 0)
      {
        a1.push_back(n);
      }
    }

    vector<int> a2;
    for (const int &n : s2)
    {
      if (s1.count(n) == 0)
      {
        a2.push_back(n);
      }
    }

    return vector<vector<int>>{a1, a2};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findDifference(*new vector<int>{1, 2, 3}, *new vector<int>{2, 4, 6});
  auto result2 = solution.findDifference(*new vector<int>{1, 2, 3, 3}, *new vector<int>{1, 1, 2, 2});
}