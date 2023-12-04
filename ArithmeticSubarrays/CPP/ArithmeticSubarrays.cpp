// https://leetcode.com/problems/arithmetic-subarrays/?envType=daily-question&envId=2023-11-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
  {
    vector<bool> answer;
    for (int i = 0; i < l.size(); i++)
    {
      int start = l[i];
      int end = r[i];
      vector<int> temp;
      for (int t = start; t <= end; t++)
      {
        temp.push_back(nums[t]);
      }

      sort(temp.begin(), temp.end());

      int n = temp[1] - temp[0];
      bool a = true;
      for (int s = 2; s < temp.size(); s++)
      {
        a = (temp[s] - temp[s - 1]) == n;
        if (!a)
        {
          break;
        }
      }

      answer.push_back(a);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  // auto result1 = solution.checkArithmeticSubarrays(*new vector<int>{4, 6, 5, 9, 3, 7}, *new vector<int>{0, 0, 2}, *new vector<int>{2, 3, 5});
  // auto result2 = solution.checkArithmeticSubarrays(*new vector<int>{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10}, *new vector<int>{0, 1, 6, 4, 8, 7}, *new vector<int>{4, 4, 9, 7, 9, 10});
  auto result3 = solution.checkArithmeticSubarrays(*new vector<int>{-3, -6, -8, -4, -2, -8, -6, 0, 0, 0, 0}, *new vector<int>{5, 4, 3, 2, 4, 7, 6, 1, 7}, *new vector<int>{6, 5, 6, 3, 7, 10, 7, 4, 10});
}