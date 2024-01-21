// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/?envType=daily-question&envId=2024-01-07
// NOT MINE: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solutions/849944/c-with-picture-base-optimizations/?envType=daily-question&envId=2024-01-07
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int numberOfArithmeticSlices(vector<int> &nums)
  {
    int n = nums.size();
    int answer = 0;
    vector<unordered_map<long, int>> m(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        long diff = (long)nums[i] - nums[j];
        auto it = m[j].find(diff);
        int count = it == m[j].end() ? 0 : it->second;
        m[i][diff] += count + 1;
        answer += count;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.numberOfArithmeticSlices(*new vector<int>{2, 4, 6, 8, 10});  // 7
  // int result2 = solution.numberOfArithmeticSlices(*new vector<int>{7, 7, 7, 7, 7});   // 16
  int result3 = solution.numberOfArithmeticSlices(*new vector<int>{7, 8, 9});         // 1
  int result4 = solution.numberOfArithmeticSlices(*new vector<int>{7, 8, 9, 10});     // 3
  int result5 = solution.numberOfArithmeticSlices(*new vector<int>{7, 8, 9, 10, 11}); // 7
}