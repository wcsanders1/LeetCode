// https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14
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
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    int answer = 0;
    unordered_map<int, int> m;
    int total = 0;
    for (int &n : nums)
    {
      total += n;
      if (total == goal)
      {
        answer++;
      }
      answer += m[total - goal];
      m[total]++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numSubarraysWithSum(*new vector<int>{1, 0, 1, 0, 1}, 2); // 4
  int result2 = solution.numSubarraysWithSum(*new vector<int>{0, 0, 0, 0, 0}, 0); // 15
  int result3 = solution.numSubarraysWithSum(*new vector<int>{0, 0, 0, 0, 1}, 2); // 0
  int result4 = solution.numSubarraysWithSum(*new vector<int>{1, 1, 1, 1, 1}, 5); // 1
}