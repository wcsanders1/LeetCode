// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int maxLength = 1;
    int currentCount = 0;
    int groups = nums.size();
    int prev = 0;

    for (int &n : nums)
    {
      if (n == prev)
      {
        currentCount++;
        if (currentCount == maxLength)
        {
          groups++;
        }
        else if (currentCount > maxLength)
        {
          maxLength = currentCount;
          groups = 1;
        }
      }
      else
      {
        currentCount = 1;
        prev = n;
      }
    }

    return groups * maxLength;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxFrequencyElements(*new vector<int>{1, 2, 2, 3, 1, 4});
  int result2 = solution.maxFrequencyElements(*new vector<int>{1, 2, 3, 4, 5});
  int result3 = solution.maxFrequencyElements(*new vector<int>{2, 1, 1, 2, 2});
}