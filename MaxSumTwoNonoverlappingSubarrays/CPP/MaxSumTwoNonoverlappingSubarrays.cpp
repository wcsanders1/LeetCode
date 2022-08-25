// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
#include <vector>

using namespace std;

class Solution
{
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
  {
    vector<int> pre(nums.size(), 0);
    pre[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      pre[i] = nums[i] + pre[i - 1];
    }

    vector<int> front_to_back(nums.size(), 0);
    vector<int> back_to_front(nums.size(), 0);

    front_to_back[secondLen - 1] = pre[secondLen - 1];
    back_to_front[nums.size() - secondLen] = pre[nums.size() - 1] - pre[nums.size() - 1 - secondLen];

    for (int f = secondLen, b = nums.size() - 1 - secondLen; f < nums.size(); f++, b--)
    {
      int front_len = pre[f] - pre[f - secondLen];
      int back_len = 0;
      if (b > 0)
      {
        back_len = pre[b + secondLen - 1] - pre[b - 1];
      }

      front_to_back[f] = max(front_len, front_to_back[f - 1]);
      back_to_front[b] = max(back_len, back_to_front[b + 1]);
    }

    int answer = pre[firstLen - 1] + back_to_front[firstLen];
    for (int i = firstLen; i < nums.size(); i++)
    {
      int len = pre[i] - pre[i - firstLen];
      int plus_front = len;
      if (i < nums.size() - 1)
      {
        plus_front = len + back_to_front[i + 1];
      }

      int plus_back = len + front_to_back[i - firstLen];
      answer = max(answer, max(plus_back, plus_front));
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSumTwoNoOverlap(*new vector<int>{0, 6, 5, 2, 2, 5, 1, 9, 4}, 1, 2);
  int result2 = solution.maxSumTwoNoOverlap(*new vector<int>{3, 8, 1, 3, 2, 1, 8, 9, 0}, 3, 2);
  int result3 = solution.maxSumTwoNoOverlap(*new vector<int>{2, 1, 5, 6, 0, 9, 5, 0, 3, 8}, 4, 3);
}