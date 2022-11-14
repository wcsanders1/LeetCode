// https://leetcode.com/problems/next-greater-element-i/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> nexts;
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(nums2[0]);
    for (int i = 1; i < nums2.size(); i++)
    {
      while (!q.empty() && q.top() < nums2[i])
      {
        nexts[q.top()] = nums2[i];
        q.pop();
      }
      q.push(nums2[i]);
    }

    vector<int> answer = vector<int>(nums1.size(), -1);
    for (int i = 0; i < answer.size(); i++)
    {
      if (nexts.count(nums1[i]) > 0)
      {
        answer[i] = nexts[nums1[i]];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.nextGreaterElement(*new vector<int>{4, 1, 2}, *new vector<int>{1, 3, 4, 2});
  auto result2 = solution.nextGreaterElement(*new vector<int>{2, 4}, *new vector<int>{1, 2, 3, 4});
}