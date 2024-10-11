// https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10
// NOT MINE: https://leetcode.com/problems/maximum-width-ramp/editorial/?envType=daily-question&envId=2024-10-10
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maxWidthRamp(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> maxRight(n, 0);
    maxRight[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      maxRight[i] = max(maxRight[i + 1], nums[i]);
    }

    int answer = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
      while (left < right && nums[left] > maxRight[right])
      {
        left++;
      }

      answer = max(answer, right - left);
      right++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxWidthRamp(*new vector<int>{6, 0, 8, 2, 1, 5});
  int result2 = solution.maxWidthRamp(*new vector<int>{9, 8, 1, 0, 1, 9, 4, 0, 4, 1});
}