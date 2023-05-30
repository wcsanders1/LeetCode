// https://leetcode.com/problems/maximum-strength-of-a-group/description/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long maxStrength(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return nums[0];
    }
    sort(nums.begin(), nums.end());
    int negs = 0;
    int lastNeg = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] < 0)
      {
        negs++;
        lastNeg = i;
      }
    }

    vector<int> useful;
    for (int i = 0; i < nums.size(); i++)
    {
      if (negs % 2 == 1 && i == lastNeg)
      {
        continue;
      }

      if (nums[i] == 0)
      {
        continue;
      }

      useful.push_back(nums[i]);
    }

    long long answer = useful.size() > 0 ? useful[0] : 0;
    for (int i = 1; i < useful.size(); i++)
    {
      answer *= useful[i];
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maxStrength(*new vector<int>{3, -1, -5, 2, 5, -9});
  auto result2 = solution.maxStrength(*new vector<int>{-4, -5, -4});
  auto result3 = solution.maxStrength(*new vector<int>{2, 2, 7, 0, -4, 9, 4});
}