// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int answer = 0;
    int cur = 0;
    int start = 0;

    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    for (int end = 0; end < s.size(); end++)
    {
      if (end - start >= k)
      {
        if (vowels.count(s[start]) == 1)
        {
          cur--;
        }

        start++;
      }

      if (vowels.count(s[end]) == 1)
      {
        cur++;
      }

      answer = max(answer, cur);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxVowels("abciiidef", 3);
  int result2 = solution.maxVowels("aeiou", 2);
  int result3 = solution.maxVowels("leetcode", 3);
}