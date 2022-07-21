// https://leetcode.com/problems/valid-mountain-array/
#include <vector>

using namespace std;

class Solution
{
public:
  bool validMountainArray(vector<int> &arr)
  {
    if (arr.size() < 3 || arr[0] >= arr[1])
    {
      return false;
    }

    bool isDecreasing = false;
    int priorNum = arr[1];
    for (int i = 2; i < arr.size(); i++)
    {
      int nextNum = arr[i];

      if (priorNum == nextNum)
      {
        return false;
      }

      if (priorNum < nextNum && isDecreasing)
      {
        return false;
      }

      if (priorNum > nextNum)
      {
        isDecreasing = true;
      }

      priorNum = nextNum;
    }

    return isDecreasing;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.validMountainArray(*new vector<int>{0, 2, 3, 4, 5, 2, 1, 0});
  bool result2 = solution.validMountainArray(*new vector<int>{0, 2, 3, 3, 5, 2, 1, 0});
  bool result3 = solution.validMountainArray(*new vector<int>{2, 1});
  bool result4 = solution.validMountainArray(*new vector<int>{3, 5, 5});
  bool result5 = solution.validMountainArray(*new vector<int>{0, 3, 2, 1});
  bool result6 = solution.validMountainArray(*new vector<int>{3, 5, 6});
}