// https://leetcode.com/problems/sliding-window-maximum/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

struct El
{
  int index;
  int val;
  El(int i, int v) : index(i), val(v) {}
};

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    deque<El> q;
    int start = 0;
    int end = 0;
    while (end < k)
    {
      while (!q.empty() && nums[end] > q.back().val)
      {
        q.pop_back();
      }
      q.push_back(El(end, nums[end]));
      end++;
    }

    int n = nums.size();
    vector<int> answer;
    start++;
    answer.push_back(q.front().val);
    while (end < n)
    {
      if (q.front().index < start)
      {
        q.pop_front();
      }

      while (!q.empty() && nums[end] > q.back().val)
      {
        q.pop_back();
      }
      q.push_back(El(end, nums[end]));
      answer.push_back(q.front().val);
      start++;
      end++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maxSlidingWindow(*new vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 3);
  auto result2 = solution.maxSlidingWindow(*new vector<int>{1}, 1);
  auto result3 = solution.maxSlidingWindow(*new vector<int>{1, 3, 1, 2, 0, 5}, 3); // [3, 3, 2, 5]
}