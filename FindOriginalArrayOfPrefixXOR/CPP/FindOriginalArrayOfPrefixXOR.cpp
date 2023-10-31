// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/?envType=daily-question&envId=2023-10-31
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> findArray(vector<int> &pref)
  {
    for (int i = pref.size() - 1; i > 0; i--)
    {
      pref[i] ^= pref[i - 1];
    }

    return pref;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findArray(*new vector<int>{5, 2, 0, 3, 1});
  auto result2 = solution.findArray(*new vector<int>{13});
}