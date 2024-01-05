// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    unordered_map<int, int> counts;
    for (int &n : nums)
    {
      if (counts.count(n) == 0)
      {
        counts[n] = 1;
      }
      else
      {
        counts[n]++;
      }
    }

    int answer = 0;
    for (auto &[_, c] : counts)
    {
      if (c < 2)
      {
        return -1;
      }
      if (c == 2)
      {
        answer++;
      }
      else
      {
        int d = c / 3;
        int r = c % 3;
        answer += d + (r > 0 ? 1 : 0);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(*new vector<int>{2, 3, 3, 2, 2, 4, 2, 3, 4});
  int result2 = solution.minOperations(*new vector<int>{2, 1, 2, 2, 3, 3});
  int result3 = solution.minOperations(*new vector<int>{2});
  int result4 = solution.minOperations(*new vector<int>{14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12}); // 7
  int result5 = solution.minOperations(*new vector<int>{19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19});                         // 5
}