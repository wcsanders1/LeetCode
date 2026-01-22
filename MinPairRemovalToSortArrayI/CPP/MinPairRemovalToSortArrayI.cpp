// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minimumPairRemoval(vector<int> &nums)
  {
    int count = 0;
    int n = nums.size();
    vector<int> cur = nums;
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < cur.size(); j++)
      {
        if (cur[j] < cur[j - 1])
        {
          count++;
          cur = reorder(cur);
          break;
        }
      }
    }
    return count;
  }

private:
  vector<int> reorder(vector<int> &nums)
  {
    int minIndx = 0;
    int minSum = INT32_MAX;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] + nums[i + 1] < minSum)
      {
        minSum = nums[i] + nums[i + 1];
        minIndx = i;
      }
    }

    vector<int> ordered;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i == minIndx)
      {
        ordered.push_back(minSum);
        i++;
      }
      else
      {
        ordered.push_back(nums[i]);
      }
    }

    return ordered;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumPairRemoval(*new vector<int>{5, 2, 3, 1});
  int result2 = solution.minimumPairRemoval(*new vector<int>{1, 2, 2});
}