#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    return wordBreak(s, set, 0);
  }

private:
  bool wordBreak(string &s, unordered_set<string> &wordDict, int start)
  {
    if (wordDict.size() == 0)
    {
      return false;
    }

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (dp[j])
        {
          string word = s.substr(j, i - j);
          if (wordDict.find(word) != wordDict.end())
          {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[s.size()];
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.wordBreak("leetcode", vector<string>{"leet", "code"});                                // true
  bool result2 = solution.wordBreak("applepenapple", vector<string>{"apple", "pen"});                           // true
  bool result3 = solution.wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"});          // false
  bool result4 = solution.wordBreak("a", vector<string>{"b"});                                                  // false
  bool result5 = solution.wordBreak("catsandogcat", vector<string>{"cats", "dog", "sand", "and", "cat", "an"}); // true
}