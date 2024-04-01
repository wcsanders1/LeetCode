// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29
// NOT MINE: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4384405/java-c-python-sliding-window/?envType=daily-question&envId=2024-03-29
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int k)
  {
    int m = *max_element(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    int start = 0;
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == m)
      {
        count++;
      }

      while (count >= k)
      {
        count = nums[start++] == m ? count - 1 : count;
      }

      answer += start;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.countSubarrays(*new vector<int>{1, 3, 2, 3, 3}, 2);                                                                                       // 6
  long long result2 = solution.countSubarrays(*new vector<int>{1, 4, 2, 1}, 3);                                                                                          // 0
  long long result3 = solution.countSubarrays(*new vector<int>{61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8, 69, 8, 7, 19, 14, 58, 42, 82, 10, 82, 78, 15, 82}, 2); // 224
}