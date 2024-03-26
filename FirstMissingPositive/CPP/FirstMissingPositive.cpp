// https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      if (num <= 0 || num >= n || num == nums[num - 1])
      {
        continue;
      }

      int t = nums[num - 1];
      nums[num - 1] = num;
      nums[i] = t;
      i--;
    }

    for (int i = 0; i < n; i++)
    {
      if (nums[i] != i + 1)
      {
        return i + 1;
      }
    }

    return n + 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.firstMissingPositive(*new vector<int>{1, 2, 0});
  int result2 = solution.firstMissingPositive(*new vector<int>{3, 4, -1, 1});
  int result3 = solution.firstMissingPositive(*new vector<int>{7, 8, 9, 11, 12});
}