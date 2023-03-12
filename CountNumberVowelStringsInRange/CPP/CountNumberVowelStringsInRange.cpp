// https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int vowelStrings(vector<string> &words, int left, int right)
  {
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    int answer = 0;
    for (int i = left; i <= right; i++)
    {
      string word = words[i];
      if (vowels.count(word[0]) == 1 && vowels.count(word[word.size() - 1]) == 1)
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.vowelStrings(*new vector<string>{"are", "amy", "u"}, 0, 2);
  int result2 = solution.vowelStrings(*new vector<string>{"hey", "aeo", "mu", "ooo", "artro"}, 1, 4);
}