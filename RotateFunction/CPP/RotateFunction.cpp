// https://leetcode.com/problems/rotate-function/
// NOT MINE: https://leetcode.com/problems/rotate-function/solutions/87842/java-solution-o-n-with-non-mathametical-explaination/?orderBy=most_votes
#include <vector>

using namespace std;

class Solution
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int answer = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      answer += nums[i] * i;
    }

    int t = answer;
    for (int i = nums.size() - 1; i > 0; i--)
    {
      t = t + sum - nums[i] * nums.size();
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