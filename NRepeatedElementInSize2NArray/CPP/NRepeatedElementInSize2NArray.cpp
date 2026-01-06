// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int repeatedNTimes(vector<int> &nums)
  {
    int n = nums.size() / 2;
    unordered_map<int, int> counts;
    for (int num : nums)
    {
      counts[num]++;
      if (counts[num] == n)
      {
        return num;
      }
    }
    return 0;
  }
};

int main()
{
  Solution solution;
  int result1 = solution.repeatedNTimes(*new vector<int>{1, 2, 3, 3});
  int result2 = solution.repeatedNTimes(*new vector<int>{2, 1, 2, 5, 3, 2});
  int result3 = solution.repeatedNTimes(*new vector<int>{5, 1, 5, 2, 5, 3, 5, 4});
}