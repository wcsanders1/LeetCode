// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());
    int answer = 0;
    for (int &n : nums)
    {
      if (n >= k)
      {
        return answer;
      }

      answer++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(*new vector<int>{2, 11, 10, 1, 3}, 10);
  int result2 = solution.minOperations(*new vector<int>{1, 1, 2, 4, 9}, 1);
  int result3 = solution.minOperations(*new vector<int>{1, 1, 2, 4, 9}, 9);
}