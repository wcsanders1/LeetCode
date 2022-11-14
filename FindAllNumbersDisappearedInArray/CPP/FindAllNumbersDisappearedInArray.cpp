// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    unordered_set<int> set;
    for (int i = 1; i <= nums.size(); i++)
    {
      set.insert(i);
    }

    for (int n : nums)
    {
      if (set.count(n) != 0)
      {
        set.erase(n);
      }
    }

    return vector<int>(set.begin(), set.end());
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findDisappearedNumbers(*new vector<int>{4, 3, 2, 7, 8, 2, 3, 1});
  auto result2 = solution.findDisappearedNumbers(*new vector<int>{1, 1});
}