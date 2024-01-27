// https://leetcode.com/problems/collecting-chocolates/description/
// NOT MINE: https://leetcode.com/problems/collecting-chocolates/solutions/3623841/java-c-python-rotate/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  long long minCost(vector<int> &nums, int x)
  {
    int n = nums.size();
    vector<long long> rotations(n, 0);

    for (long long i = 0; i < n; i++)
    {
      rotations[i] += i * (long long)x;
      int cur = nums[i];
      for (int j = 0; j < n; j++)
      {
        cur = min(cur, nums[(j + i) % n]);
        rotations[j] += cur;
      }
    }

    return *min_element(rotations.begin(), rotations.end());
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.minCost(*new vector<int>{20, 1, 15}, 5);                  // 13
  long long result2 = solution.minCost(*new vector<int>{1, 2, 3}, 4);                    // 6
  long long result3 = solution.minCost(*new vector<int>{15, 150, 56, 69, 214, 203}, 42); // 298
}