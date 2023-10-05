// https://leetcode.com/problems/132-pattern/?envType=daily-question&envId=2023-09-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool find132pattern(vector<int> &nums)
  {
    stack<int> s;
    int s2 = INT32_MIN;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (s2 > nums[i])
      {
        return true;
      }

      while (!s.empty() && s.top() < nums[i])
      {
        s2 = s.top();
        s.pop();
      }

      s.push(nums[i]);
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.find132pattern(*new vector<int>{1, 2, 3, 4});    // false
  bool result2 = solution.find132pattern(*new vector<int>{3, 1, 4, 2});    // true
  bool result3 = solution.find132pattern(*new vector<int>{-1, 3, 2, 0});   // true
  bool result4 = solution.find132pattern(*new vector<int>{3, 5, 0, 3, 4}); // true
}