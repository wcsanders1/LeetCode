// https://leetcode.com/problems/rotate-function/
#include <vector>

using namespace std;

class Solution
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int answer = INT32_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
      int t = 0;
      for (int j = 0; j < nums.size(); j++)
      {
        int n = j + i >= nums.size() ? j + i - nums.size() : j + i;
        t += nums[n] * j;
      }

      answer = max(answer, t);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxRotateFunction(*new vector<int>{4, 3, 2, 6});
  int result2 = solution.maxRotateFunction(*new vector<int>{100});
}