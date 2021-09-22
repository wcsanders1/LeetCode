#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return 0;
    }

    if (nums.size() == 1)
    {
      return nums[0];
    }

    int negative = nums[0];
    int positive = nums[0];
    int highest = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      int n = nums[i];
      if (n == 0)
      {
        highest = max(0, max(highest, max(negative, positive)));
        negative = 0;
        positive = 0;
      }
      else if (n > 0)
      {
        positive = positive == 0 ? n : positive * n;
        negative = negative == 0 ? n : negative * n;
      }
      else
      {
        negative = negative == 0 ? n : negative * n;
        positive = max(positive, negative);
        highest = max(highest, positive);
        positive = 0;
      }
    }

    return max(highest, max(negative, positive));
  }
};

int main()
{
  Solution solution;
  int result1 = solution.maxProduct(*new vector<int>{2, 3, -2, 4});      // 6
  int result2 = solution.maxProduct(*new vector<int>{-2, 0, -1});        // 0
  int result3 = solution.maxProduct(*new vector<int>{7, -2, -4});        // 56
  int result4 = solution.maxProduct(*new vector<int>{6, 3, -10, 0, 2});  // 18
  int result5 = solution.maxProduct(*new vector<int>{2, -5, -2, -4, 3}); //24
}