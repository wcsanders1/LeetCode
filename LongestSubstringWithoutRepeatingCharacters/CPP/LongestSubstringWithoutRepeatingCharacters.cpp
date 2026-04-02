// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
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
  int lengthOfLongestSubstring(string s)
  {
    int n = s.size();
    int longest = 0;
    int start = 0;
    int end = 0;

    unordered_map<char, int> chars;
    while (end < n)
    {
      char c = s[end];
      if (chars.find(c) == chars.end())
      {
        chars[c] = end;
      }
      else
      {
        while (start < chars[c])
        {
          chars.erase(s[start++]);
        }
        start = chars[c] + 1;
        chars[c] = end;
      }
      longest = max(longest, (end - start) + 1);
      end++;
    }

    return longest;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.lengthOfLongestSubstring("abcabcbb");
  int result2 = solution.lengthOfLongestSubstring("bbbbb");
  int result3 = solution.lengthOfLongestSubstring("pwwkew");
  int result4 = solution.lengthOfLongestSubstring("");
  int result5 = solution.lengthOfLongestSubstring("abba");
}