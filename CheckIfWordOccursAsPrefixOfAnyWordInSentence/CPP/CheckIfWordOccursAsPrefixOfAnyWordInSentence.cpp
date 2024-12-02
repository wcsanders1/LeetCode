// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int isPrefixOfWord(string sentence, string searchWord)
  {
    vector<string> words;
    string word = "";
    for (char c : sentence)
    {
      if (c == ' ')
      {
        words.push_back(word);
        word = "";
      }
      else
      {
        word += c;
      }
    }

    if (word.size() > 0)
    {
      words.push_back(word);
    }

    int index = 1;
    for (string &word : words)
    {
      if (searchWord.size() > word.size())
      {
        index++;
        continue;
      }

      if (word.compare(0, searchWord.size(), searchWord) == 0)
      {
        return index;
      }

      index++;
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.isPrefixOfWord("i love eating burger", "burg");
  int result2 = solution.isPrefixOfWord("this problem is an easy problem", "pro");
  int result3 = solution.isPrefixOfWord("i am tired", "you");
}