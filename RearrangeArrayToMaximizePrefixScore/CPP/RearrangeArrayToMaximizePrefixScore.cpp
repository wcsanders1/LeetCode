// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxScore(vector<int> &nums)
  {
    sort(nums.begin(), nums.end(), greater<int>());
    vector<long long> pre(nums.size(), 0);
    pre[0] = nums[0];
    int answer = pre[0] > 0 ? 1 : 0;
    for (int i = 1; i < nums.size(); i++)
    {
      pre[i] = pre[i - 1] + nums[i];
      if (pre[i] > 0)
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxScore(*new vector<int>{2, -1, 0, 1, -3, 3, -3});
  int result2 = solution.maxScore(*new vector<int>{-2, -3, 0});
}