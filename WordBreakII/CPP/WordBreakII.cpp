#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> dp;
    vector<string> combinations = getWords(set, s, 0, dp);

    return combinations;
  }

private:
  vector<string> getWords(unordered_set<string> &set, string s, int position, unordered_map<int, vector<string>> &dp)
  {
    vector<string> words;
    for (int i = position + 1; i <= s.size(); i++)
    {
      string word = s.substr(position, i - position);
      if (set.find(word) == set.end())
      {
        if (i == s.size())
        {
          return words;
        }

        continue;
      }

      if (i == s.size())
      {
        words.push_back(word);
        return words;
      }

      if (dp.count(i) > 0)
      {
        for (string w : dp[i])
        {
          words.push_back(word + " " + w);
        }

        continue;
      }

      vector<string> newWords = getWords(set, s, i, dp);
      if (newWords.size() > 0)
      {
        dp[i] = newWords;
        for (string w : dp[i])
        {
          words.push_back(word + " " + w);
        }
      }
    }

    return words;
  }
};

int main()
{
  Solution solution;

  vector<string> result1 = solution.wordBreak("catsanddog", vector<string>{"cat", "cats", "and", "sand", "dog"});
  vector<string> result2 = solution.wordBreak("pineapplepenapple", vector<string>{"apple", "pen", "applepen", "pine", "pineapple"});
  vector<string> result3 = solution.wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"});
}