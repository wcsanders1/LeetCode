// https://leetcode.com/problems/verifying-an-alien-dictionary/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isAlienSorted(vector<string> &words, string order)
  {
    unordered_map<char, int> dict;
    for (int i = 0; i < order.size(); i++)
    {
      dict[order[i]] = i + 1;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
      int s = min(words[i].size(), words[i + 1].size());
      bool checkSize = true;
      for (int j = 0; j < s; j++)
      {
        if (dict[words[i][j]] > dict[words[i + 1][j]])
        {
          return false;
        }
        else if (dict[words[i][j]] < dict[words[i + 1][j]])
        {
          checkSize = false;
          break;
        }
      }

      if (checkSize && words[i].size() > words[i + 1].size())
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isAlienSorted(*new vector<string>{"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz");
  bool result2 = solution.isAlienSorted(*new vector<string>{"word", "world", "fun"}, "worldabcefghijkmnpqstuvxyz");
  bool result3 = solution.isAlienSorted(*new vector<string>{"apple", "app"}, "abcdefghijklmnopqrstuvwxyz");
  bool result4 = solution.isAlienSorted(*new vector<string>{"kuvp", "q"}, "ngxlkthsjuoqcpavbfdermiywz");
}