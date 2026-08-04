// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool canArrange(vector<int> &arr, int k)
  {
    unordered_map<int, int> counts;
    for (int &n : arr)
    {
      counts[((n % k) + k) % k]++;
    }

    for (int &n : arr)
    {
      int have = ((n % k) + k) % k;
      if (counts[have] <= 0)
      {
        continue;
      }
      counts[have]--;
      int need = have == 0 ? 0 : k - have;
      if (counts[need] <= 0)
      {
        return false;
      }
      counts[need]--;
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canArrange(*new vector<int>{1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, 5); // true
  bool result2 = solution.canArrange(*new vector<int>{1, 2, 3, 4, 5, 6}, 7);              // true
  bool result3 = solution.canArrange(*new vector<int>{1, 2, 3, 4, 5, 6}, 10);             // false
  bool result4 = solution.canArrange(*new vector<int>{-10, 10}, 2);                       // true
  bool result5 = solution.canArrange(*new vector<int>{-1, 1, -2, 2, -3, 3, -4, 4}, 3);    // true
}