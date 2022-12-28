// https://leetcode.com/problems/partition-equal-subset-sum/
#include <vector>
#include <numeric>
#include <set>

using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0)
    {
      return false;
    }

    int needed = total / 2;

    set<int> subs;
    subs.insert(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
      int n = nums[i];
      if (n == needed)
      {
        return true;
      }

      set<int> newSubs;
      for (int s : subs)
      {
        int nxt = s + n;
        if (nxt == needed || s == needed)
        {
          return true;
        }

        newSubs.insert(nxt);
      }

      subs.insert(n);
      for (int ns : newSubs)
      {
        subs.insert(ns);
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canPartition(*new vector<int>{1, 5, 11, 5});       // true
  bool result2 = solution.canPartition(*new vector<int>{1, 2, 3, 5});        // false
  bool result3 = solution.canPartition(*new vector<int>{14, 9, 8, 4, 3, 2}); // true
  bool result4 = solution.canPartition(*new vector<int>{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 97});
}