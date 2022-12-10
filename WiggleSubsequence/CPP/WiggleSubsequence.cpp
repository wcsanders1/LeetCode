// https://leetcode.com/problems/wiggle-subsequence/description/
#include <vector>

using namespace std;

enum Diff
{
  Equal = 0,
  Lesser = 1,
  Greater = 2,
};

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    Diff curDiff = Equal;
    int answer = 1;
    for (int i = 1; i < nums.size(); i++)
    {
      Diff nextDiff = getDiff(nums[i - 1], nums[i]);
      if (nextDiff != Equal && nextDiff != curDiff)
      {
        curDiff = nextDiff;
        answer++;
      }
    }

    return answer;
  }

private:
  Diff getDiff(int num1, int num2)
  {
    int d = num1 - num2;
    if (d == 0)
    {
      return Equal;
    }

    if (d < 0)
    {
      return Greater;
    }

    return Lesser;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.wiggleMaxLength(*new vector<int>{1, 7, 4, 9, 2, 5});
  int result2 = solution.wiggleMaxLength(*new vector<int>{1, 17, 5, 10, 13, 15, 10, 5, 16, 8});
  int result3 = solution.wiggleMaxLength(*new vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
  int result4 = solution.wiggleMaxLength(*new vector<int>{1});
}