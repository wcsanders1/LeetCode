#include <vector>
#include <algorithm>
#include <cmath>

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

    int highest = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];
    int maximum = 0;
    int minimum = 0;

    for (int i = 1; i < nums.size(); i++)
    {
      int n = nums[i];
      maximum = max(max(currentMax * n, currentMin * n), n);
      minimum = min(min(currentMax * n, currentMin * n), n);
      highest = max(maximum, highest);
      currentMax = maximum;
      currentMin = minimum;
    }

    return highest;
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
  int result6 = solution.maxProduct(*new vector<int>{3, -1, 4});         //4
}