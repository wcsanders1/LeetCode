// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    const int MOD = 1e9 + 7;
    queue<int> current;
    priority_queue<int, vector<int>, greater<int>> all;
    current.push(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
      int count = current.size();
      while (count-- > 0)
      {
        int num = current.front();
        current.pop();
        all.push(num);
        current.push(num + nums[i]);
      }

      current.push(nums[i]);
    }

    while (!current.empty())
    {
      all.push(current.front());
      current.pop();
    }

    int range = (right - left) + 1;
    while (left-- > 1)
    {
      all.pop();
    }

    int answer = 0;
    while (range-- > 0)
    {
      answer = (answer + all.top()) % MOD;
      all.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.rangeSum(*new vector<int>{1, 2, 3, 4}, 4, 1, 5);  // 13
  int result2 = solution.rangeSum(*new vector<int>{1, 2, 3, 4}, 4, 3, 4);  // 6
  int result3 = solution.rangeSum(*new vector<int>{1, 2, 3, 4}, 4, 1, 10); // 50
}