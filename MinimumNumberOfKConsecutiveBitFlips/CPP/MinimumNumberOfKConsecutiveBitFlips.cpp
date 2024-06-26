// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24
// NOT MINE: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/editorial/?envType=daily-question&envId=2024-06-24
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int minKBitFlips(vector<int> &nums, int k)
  {
    int n = nums.size();
    int flipsInRange = 0;
    vector<bool> flipped(n, false);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
      if (i >= k && flipped[i - k])
      {
        flipsInRange--;
      }

      if ((flipsInRange % 2) == nums[i])
      {
        if (i + k > n)
        {
          return -1;
        }

        answer++;
        flipped[i] = true;
        flipsInRange++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minKBitFlips(*new vector<int>{0, 1, 0}, 1);                // 2
  int result2 = solution.minKBitFlips(*new vector<int>{1, 1, 0}, 2);                //-1
  int result3 = solution.minKBitFlips(*new vector<int>{0, 0, 0, 1, 0, 1, 1, 0}, 3); // 3
}