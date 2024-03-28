// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxSubarrayLength(vector<int> &nums, int k)
  {
    unordered_map<int, int> occurrences;
    unordered_map<int, queue<int>> places;
    int start = -1;
    int maxLength = 0;
    for (int end = 0; end < nums.size(); end++)
    {
      int num = nums[end];
      places[num].push(end);

      while (!places[num].empty() && places[num].front() < start)
      {
        places[num].pop();
        occurrences[num]--;
      }

      if (occurrences[num] + 1 > k)
      {
        start = places[num].front();
        places[num].pop();
      }
      else
      {
        occurrences[num]++;
      }

      maxLength = max(maxLength, end - start);
    }

    return maxLength;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSubarrayLength(*new vector<int>{1, 2, 3, 1, 2, 3, 1, 2}, 2); // 6
  int result2 = solution.maxSubarrayLength(*new vector<int>{1, 2, 1, 2, 1, 2, 1, 2}, 1); // 2
  int result3 = solution.maxSubarrayLength(*new vector<int>{5, 5, 5, 5, 5, 5, 5}, 4);    // 4
  int result4 = solution.maxSubarrayLength(*new vector<int>{1}, 1);                      // 1
  int result5 = solution.maxSubarrayLength(*new vector<int>{1, 2, 2, 1, 3}, 1);          // 3
  int result6 = solution.maxSubarrayLength(*new vector<int>{2, 1, 2, 3}, 1);             // 3
}