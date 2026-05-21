// https://leetcode.com/problems/house-robber-v/description/
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
  long long rob(vector<int> &nums, vector<int> &colors)
  {
    int n = nums.size();
    long long answer = 0;
    int start = 0;
    int end = 0;

    while (end < n)
    {
      while (end < n && colors[start] == colors[end])
      {
        end++;
      }

      answer += rob(nums, start, end - 1);
      start = end;
    }

    return answer;
  }

private:
  long long rob(vector<int> &nums, int start, int end)
  {
    int n = (end - start) + 1;
    if (n == 1)
    {
      return nums[start];
    }

    if (n == 2)
    {
      return max(nums[start], nums[end]);
    }

    vector<long long> t(nums.begin() + start, nums.begin() + (end + 1));

    t[1] = max(t[0], t[1]);
    for (int i = 2; i < n; i++)
    {
      t[i] = max(t[i - 2] + t[i], t[i - 1]);
    }

    return t[n - 1];
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.rob(*new vector<int>{1, 4, 3, 5}, *new vector<int>{1, 1, 2, 2});
  auto result2 = solution.rob(*new vector<int>{3, 1, 2, 4}, *new vector<int>{2, 3, 2, 2});
  auto result3 = solution.rob(*new vector<int>{10, 1, 3, 9}, *new vector<int>{1, 1, 1, 2});
}