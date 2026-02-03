// https://leetcode.com/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  bool isTrionic(vector<int> &nums)
  {
    vector<string> changes;
    string cur = "";
    for (int i = 1; i < nums.size(); i++)
    {
      string dir = nums[i - 1] > nums[i] ? "D" : nums[i - 1] == nums[i] ? ""
                                                                        : "I";
      if (dir == "")
      {
        return false;
      }
      if (dir == cur)
      {
        continue;
      }
      cur = dir;
      changes.push_back(cur);
    }

    if (changes.size() != 3)
    {
      return false;
    }

    return changes[0] == "I" && changes[1] == "D" && changes[2] == "I";
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isTrionic(*new vector<int>{1, 3, 5, 4, 2, 6});
  bool result2 = solution.isTrionic(*new vector<int>{2, 1, 3});
}