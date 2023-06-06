// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool canMakeArithmeticProgression(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];

    for (int i = 2; i < arr.size(); i++)
    {
      if (arr[i] - arr[i - 1] != diff)
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canMakeArithmeticProgression(*new vector<int>{3, 5, 1});
  bool result2 = solution.canMakeArithmeticProgression(*new vector<int>{1, 2, 5});
}