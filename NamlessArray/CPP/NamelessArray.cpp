// https://leetcode.com/problems/patching-array/description/
// NOT MINE: https://leetcode.com/problems/patching-array/solutions/78488/solution-explanation-by-stefanpochmann-89bf/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minPatches(vector<int> &nums, int n)
  {
    int answer = 0;
    long long total = 1;
    int index = 0;

    while (total <= n)
    {
      if (index < nums.size() && nums[index] <= total)
      {
        total += nums[index++];
      }
      else
      {
        total += total;
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  int result1 = solution.minPatches(*new vector<int>{1, 3}, 6);                                    // 1
  int result2 = solution.minPatches(*new vector<int>{1, 5, 10}, 20);                               // 2
  int result3 = solution.minPatches(*new vector<int>{1, 2, 2}, 5);                                 // 0
  int result4 = solution.minPatches(*new vector<int>{1, 2, 31, 33}, 2147483647);                   // 28
  int result5 = solution.minPatches(*new vector<int>{10, 30, 36, 42, 50, 76, 87, 88, 91, 92}, 54); // 5
  int result6 = solution.minPatches(*new vector<int>{1, 12, 15}, 43);                              // 4
}