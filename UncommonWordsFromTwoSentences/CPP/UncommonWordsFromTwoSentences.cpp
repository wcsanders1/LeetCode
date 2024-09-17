// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<string> uncommonFromSentences(string s1, string s2)
  {
    vector<string> words1 = getWords(s1);
    vector<string> words2 = getWords(s2);

    unordered_map<string, int> count;
    for (string &word : words1)
    {
      count[word]++;
    }

    for (string &word : words2)
    {
      count[word]++;
    }

    vector<string> answer;
    for (auto &[w, c] : count)
    {
      if (c == 1)
      {
        answer.push_back(w);
      }
    }

    return answer;
  }

private:
  vector<string> getWords(string &s)
  {
    int start = 0;
    vector<string> words;
    for (int i = 1; i < s.size(); i++)
    {
      if (s[i] == ' ')
      {
        words.push_back(s.substr(start, i - start));
        start = i + 1;
      }
    }

    words.push_back(s.substr(start, s.size() - start));
    return words;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.uncommonFromSentences("this apple is sweet", "this apple is sour");
  auto result2 = solution.uncommonFromSentences("apple apple", "banana");
}