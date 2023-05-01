// https://leetcode.com/problems/make-array-empty/description/
// NOT MINE: https://leetcode.com/problems/make-array-empty/solutions/3466800/java-c-python-easy-sort-solution/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  long long countOperationsToEmptyArray(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      m[nums[i]] = i;
    }

    long long answer = n;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
      if (m[nums[i]] < m[nums[i - 1]])
      {
        answer += n - i;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.countOperationsToEmptyArray(*new vector<int>{3, 4, -1});
  auto result2 = solution.countOperationsToEmptyArray(*new vector<int>{1, 2, 4, 3});
  auto result3 = solution.countOperationsToEmptyArray(*new vector<int>{1, 2, 3});
}