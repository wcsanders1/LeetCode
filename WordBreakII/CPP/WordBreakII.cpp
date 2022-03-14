#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    vector<string> combinations;
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    for (int i = 0; i < s.size(); i++)
    {
      string words = getWords(set, s, i);
      if (words.size() > 0)
      {
        combinations.push_back(words);
      }
    }

    return combinations;
  }

private:
  string getWords(unordered_set<string> &set, string s, int position)
  {
  }
};