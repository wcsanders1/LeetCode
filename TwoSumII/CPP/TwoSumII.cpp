// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
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
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int n = numbers.size();
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
      int sum = numbers[start] + numbers[end];
      if (sum == target)
      {
        return {start + 1, end + 1};
      }

      if (sum > target)
      {
        end--;
      }
      else
      {
        start++;
      }
    }

    return {};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.twoSum(*new vector<int>{2, 7, 11, 15}, 9);
  auto result2 = solution.twoSum(*new vector<int>{2, 3, 4}, 6);
  auto result3 = solution.twoSum(*new vector<int>{-1, 0}, -1);
}