#include <vector>

using namespace std;

class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    if (nums.size() == 0)
    {
      return 0;
    }

    int start = 0;
    int end = 0;
    int currentProduct = 1;
    int result = 0;

    while (start < nums.size() && end < nums.size())
    {
      currentProduct *= nums[end];
      if (currentProduct < k)
      {
        result += (end + 1) - start;
        end++;
      }
      else
      {
        while (end < nums.size())
        {
          currentProduct /= nums[start++];
          if (currentProduct < k)
          {
            result += (end + 1) - start;
            end++;
            break;
          }
          if (start >= end)
          {
            end++;
            if (end < nums.size())
            {
              currentProduct *= nums[end];
            }
          }
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numSubarrayProductLessThanK(*new vector<int>{10, 5, 2, 6}, 100);
  int result2 = solution.numSubarrayProductLessThanK(*new vector<int>{1, 2, 3}, 0);
  int result3 = solution.numSubarrayProductLessThanK(*new vector<int>{57, 44, 92, 28, 66, 60, 37, 33, 52, 38, 29, 76, 8, 75, 22}, 18);
}