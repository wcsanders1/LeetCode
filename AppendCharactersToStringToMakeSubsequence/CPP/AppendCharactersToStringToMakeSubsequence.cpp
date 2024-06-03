// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  int appendCharacters(string s, string t)
  {
    int si = 0;
    int ti = 0;

    while (ti < t.size() && si < s.size())
    {
      if (t[ti] == s[si])
      {
        ti++;
      }
      si++;
    }

    return t.size() - ti;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.appendCharacters("coaching", "coding");
  int result2 = solution.appendCharacters("abcde", "a");
  int result3 = solution.appendCharacters("z", "abcde");
}