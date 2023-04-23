// https://leetcode.com/problems/maximum-width-of-binary-tree/
// NOT MINE: https://leetcode.com/problems/restore-the-array/solutions/585552/java-c-dfs-memoization-clean-code/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int numberOfArrays(string s, int k)
  {
    vector<int> dp(s.size(), -1);
    return numberOfArrays(s, k, dp, 0);
  }

private:
  int mod = 1000000007;
  int numberOfArrays(const string &s, int k, vector<int> &dp, int start)
  {
    if (start == s.size())
    {
      return 1;
    }

    if (s[start] == '0')
    {
      return 0;
    }

    if (dp[start] != -1)
    {
      return dp[start];
    }

    int count = 0;
    long num = 0;
    for (int end = start; end < s.size(); end++)
    {
      num = num * 10 + s[end] - '0';
      if (num > k)
      {
        break;
      }
      count += numberOfArrays(s, k, dp, end + 1);
      count %= mod;
    }

    return dp[start] = count;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numberOfArrays("1000", 10000);
  int result2 = solution.numberOfArrays("1000", 10);
  int result3 = solution.numberOfArrays("1317", 2000);
  int result4 = solution.numberOfArrays("1234567890", 90);
}