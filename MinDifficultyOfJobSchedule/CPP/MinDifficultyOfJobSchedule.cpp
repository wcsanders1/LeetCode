// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/?envType=daily-question&envId=2023-12-29
// NOT MINE: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/solutions/490316/java-c-python3-dp-o-nd-solution/?envType=daily-question&envId=2023-12-29
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minDifficulty(vector<int> &jobDifficulty, int d)
  {
    int n = jobDifficulty.size();
    if (d > n)
    {
      return -1;
    }

    vector<vector<int>> dp(d, vector<int>(n, -1));
    dp[0][0] = jobDifficulty[0];
    for (int i = 1; i < n; i++)
    {
      dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);
    }

    for (int day = 1; day < d; day++)
    {
      for (int job = day; job < n; job++)
      {
        dp[day][job] = INT32_MAX;
        int curMax = jobDifficulty[job];
        for (int s = job; s >= day; s--)
        {
          curMax = max(curMax, jobDifficulty[s]);
          dp[day][job] = min(dp[day][job], dp[day - 1][s - 1] + curMax);
        }
      }
    }

    return dp[d - 1][n - 1];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minDifficulty(*new vector<int>{6, 5, 4, 3, 2, 1}, 2);
  int result2 = solution.minDifficulty(*new vector<int>{9, 9, 9}, 4);
  int result3 = solution.minDifficulty(*new vector<int>{1, 1, 1}, 3);
  int result4 = solution.minDifficulty(*new vector<int>{3, 2, 1, 2, 3}, 2);
}