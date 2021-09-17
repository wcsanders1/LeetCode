#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    return wordBreak(s, wordDict, 0);
  }

private:
  bool wordBreak(string &s, vector<string> &wordDict, int start)
  {
    if (start == s.size())
    {
      return true;
    }

    for (string word : wordDict)
    {
      for (int i = 0; i < word.size(); i++)
      {
        if (i + start >= s.size())
        {
          return false;
        }
        if (word[i] != s[i + start])
        {
          break;
        }
        if (i == word.size() - 1 && wordBreak(s, wordDict, word.size() + start))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.wordBreak("leetcode", vector<string>{"leet", "code"});
  bool result2 = solution.wordBreak("applepenapple", vector<string>{"apple", "pen"});
  bool result3 = solution.wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"});
  bool result4 = solution.wordBreak("a", vector<string>{"b"});
  bool result5 = solution.wordBreak("catsandogcat", vector<string>{"cats", "dog", "sand", "and", "cat", "an"});
}