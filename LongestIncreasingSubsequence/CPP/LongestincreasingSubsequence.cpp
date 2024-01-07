// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> len(n, 1);
    int answer = 1;

    for (int i = 1; i < n; i++)
    {
      int num = nums[i];
      for (int j = i - 1; j >= 0; j--)
      {
        if (nums[j] < num)
        {
          len[i] = max(len[i], len[j] + 1);
        }
      }

      answer = max(answer, len[i]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.lengthOfLIS(*new vector<int>{10, 9, 2, 5, 3, 7, 101, 18}); // 4
  int result2 = solution.lengthOfLIS(*new vector<int>{0, 1, 0, 3, 2, 3});           // 4
  int result3 = solution.lengthOfLIS(*new vector<int>{7, 7, 7, 7, 7, 7, 7});        // 1
}