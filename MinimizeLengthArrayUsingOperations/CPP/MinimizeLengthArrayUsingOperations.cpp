// https://leetcode.com/problems/minimize-length-of-array-using-operations/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
  int minimumArrayLength(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int _min = nums[0];
    int numMins = 1;
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] != _min)
      {
        break;
      }
      numMins++;
    }

    if (numMins == 1)
    {
      return 1;
    }

    for (int i = numMins; i < nums.size(); i++)
    {
      if (nums[i] % nums[0] > 0)
      {
        return 1;
      }
    }

    return (numMins / 2) + (numMins % 2);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumArrayLength(*new vector<int>{1, 4, 3, 1});       // 1
  int result2 = solution.minimumArrayLength(*new vector<int>{5, 5, 5, 10, 5});   // 2
  int result3 = solution.minimumArrayLength(*new vector<int>{2, 3, 4});          // 1
  int result4 = solution.minimumArrayLength(*new vector<int>{3, 3, 1});          // 1
  int result5 = solution.minimumArrayLength(*new vector<int>{2, 2, 4, 4, 2, 1}); // 1
  int result6 = solution.minimumArrayLength(*new vector<int>{4, 4, 4});          // 2
}