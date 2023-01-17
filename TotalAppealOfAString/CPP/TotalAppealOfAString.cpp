// https://leetcode.com/problems/total-appeal-of-a-string/
// NOT MINE: https://leetcode.com/problems/total-appeal-of-a-string/solutions/1996203/dp/?orderBy=most_votes
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long appealSum(string s)
  {
    unordered_map<char, int> lastSeen;
    lastSeen[s[0]] = 0;

    vector<long long> dp(s.size(), 0);
    dp[0] = 1;
    long long answer = 1;

    for (int i = 1; i < s.size(); i++)
    {
      char c = s[i];
      if (lastSeen.count(c) == 0)
      {
        dp[i] = i + 1 + dp[i - 1];
      }
      else
      {
        dp[i] = dp[i - 1] + (i - lastSeen[c]);
      }
      lastSeen[c] = i;
      answer += dp[i];
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.appealSum("abbca");
  long long result2 = solution.appealSum("code");
  long long result3 = solution.appealSum("abcab");
}