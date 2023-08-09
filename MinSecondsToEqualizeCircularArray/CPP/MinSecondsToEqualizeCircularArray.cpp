// https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/
// NOT MINE: https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/solutions/3867950/maximum-gap/
#include <vector>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minimumSeconds(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, vector<int>> distances;
    for (int i = 0; i < n; i++)
    {
      distances[nums[i]].push_back(i);
    }

    int answer = INT32_MAX;

    for (auto &[_, d] : distances)
    {
      d.push_back(d[0] + n);
      int t = 0;
      for (int i = 1; i < d.size(); i++)
      {
        t = max(t, (d[i] - d[i - 1]) / 2);
      }
      answer = min(answer, t);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumSeconds(*new vector<int>{1, 2, 1, 2});            // 1
  int result2 = solution.minimumSeconds(*new vector<int>{2, 1, 3, 3, 2});         // 2
  int result3 = solution.minimumSeconds(*new vector<int>{5, 5, 5, 5});            // 0
  int result4 = solution.minimumSeconds(*new vector<int>{19, 20, 7, 7, 20});      // 1
  int result5 = solution.minimumSeconds(*new vector<int>{5, 14, 5, 9, 9, 2, 12}); // 2
  int result6 = solution.minimumSeconds(*new vector<int>{8, 13, 3, 3});           // 1
  int result7 = solution.minimumSeconds(*new vector<int>{11, 15, 15, 4, 12, 18}); // 2
}