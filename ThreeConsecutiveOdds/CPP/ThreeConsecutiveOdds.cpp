// https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int consec = 0;
    for (int &n : arr)
    {
      if (n % 2 == 0)
      {
        consec = 0;
      }
      else
      {
        consec++;
      }

      if (consec == 3)
      {
        return true;
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.threeConsecutiveOdds(*new vector<int>{2, 6, 4, 1});
  bool result2 = solution.threeConsecutiveOdds(*new vector<int>{1, 2, 34, 3, 4, 5, 7, 23, 12});
  bool result3 = solution.threeConsecutiveOdds(*new vector<int>{1, 1, 1});
}