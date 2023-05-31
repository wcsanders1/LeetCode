// https://leetcode.com/problems/extra-characters-in-a-string/description/
// NOT MINE: https://leetcode.com/problems/extra-characters-in-a-string/solutions/3568624/top-down-and-bottom-up/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minExtraChar(string s, vector<string> &dictionary)
  {
    vector<int> dp(s.size() + 1, 0);
    dp[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
      dp[i] = dp[i + 1] + 1;
      for (string &word : dictionary)
      {
        if (s.compare(i, word.size(), word) == 0)
        {
          dp[i] = min(dp[i], dp[i + word.size()]);
        }
      }
    }

    return dp[0];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minExtraChar("leetscode", *new vector<string>{"leet", "code", "leetcode"});
  int result2 = solution.minExtraChar("sayhelloworld", *new vector<string>{"world", "hello"});
  int result3 = solution.minExtraChar("dwmodizxvvbosxxw", *new vector<string>{"ox", "lb", "diz", "gu", "v", "ksv", "o", "nuq", "r", "txhe", "e", "wmo", "cehy", "tskz", "ds", "kzbu"});
}