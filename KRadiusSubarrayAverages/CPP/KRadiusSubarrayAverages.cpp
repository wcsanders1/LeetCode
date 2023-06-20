// https://leetcode.com/problems/k-radius-subarray-averages/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> getAverages(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> answer(n, -1);

    int start = 0;
    int end = k * 2;
    if (n <= end)
    {
      return answer;
    }

    long long total = 0;
    for (int i = 0; i <= end; i++)
    {
      total += nums[i];
    }

    int size = (k * 2) + 1;
    while (end < n)
    {
      answer[k++] = total / size;
      if (++end < n)
      {
        total -= nums[start++];
        total += nums[end];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.getAverages(*new vector<int>{7, 4, 3, 9, 1, 8, 5, 2, 6}, 3);
  auto result2 = solution.getAverages(*new vector<int>{100000}, 0);
  auto result3 = solution.getAverages(*new vector<int>{8}, 100000);
}