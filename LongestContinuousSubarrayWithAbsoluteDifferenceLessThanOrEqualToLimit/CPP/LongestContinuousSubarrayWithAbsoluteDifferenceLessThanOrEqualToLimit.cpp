// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums, int limit)
  {
    int n = nums.size();
    unordered_map<int, int> count;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int answer = 1;
    int start = 0;
    int end = 0;
    maxheap.push(nums[0]);
    minheap.push(nums[0]);
    count[nums[0]]++;

    while (start < n)
    {
      while (count[maxheap.top()] == 0)
      {
        maxheap.pop();
      }

      while (count[minheap.top()] == 0)
      {
        minheap.pop();
      }

      int diff = abs(maxheap.top() - minheap.top());
      if (diff > limit)
      {
        count[nums[start]]--;
        start++;
      }
      else if (end == n - 1)
      {
        return max(answer, (end - start) + 1);
      }
      else
      {
        answer = max(answer, (end - start) + 1);
        end++;
        count[nums[end]]++;
        minheap.push(nums[end]);
        maxheap.push(nums[end]);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestSubarray(*new vector<int>{8, 2, 4, 7}, 4);
  int result2 = solution.longestSubarray(*new vector<int>{10, 1, 2, 4, 7, 2}, 5);
  int result3 = solution.longestSubarray(*new vector<int>{4, 2, 2, 2, 4, 4, 2, 2}, 0);
}