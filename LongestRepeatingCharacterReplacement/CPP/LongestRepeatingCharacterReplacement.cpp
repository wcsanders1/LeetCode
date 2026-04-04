// https://leetcode.com/problems/longest-repeating-character-replacement/description/
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
  int characterReplacement(string s, int k)
  {
    int n = s.size();
    int start = 0;
    int end = 0;
    int maxlen = 0;
    unordered_map<char, int> chars;

    while (end < n)
    {
      chars[s[end]]++;
      int m = 0;
      int tot = 0;
      for (auto &[_, v] : chars)
      {
        m = max(m, v);
        tot += v;
      }

      int excess = tot - m;
      while (excess > k)
      {
        excess -= chars[s[start]];
        chars[s[start]]--;
        start++;
      }

      maxlen = max(maxlen, (end - start) + 1);
      end++;
    }

    return maxlen;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.characterReplacement("ABAB", 2);
  int result2 = solution.characterReplacement("AABABBA", 1);
  int result3 = solution.characterReplacement("ABBB", 2);
}