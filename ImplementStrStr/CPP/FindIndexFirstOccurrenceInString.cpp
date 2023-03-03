// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    vector<vector<int>> dp(haystack.size() + 1, vector<int>(1, -1));
    for (int i = 1; i <= haystack.size(); i++)
    {
      char c = haystack[i - 1];
      for (int sub : dp[i - 1])
      {
        int next = sub + 1;
        if (c == needle[next])
        {
          if (next == needle.size() - 1)
          {
            return i - needle.size();
          }
          dp[i].push_back(next);
        }
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.strStr("sadbutsad", "sad");
  int result2 = solution.strStr("leetcode", "leeto");
  int result3 = solution.strStr("sadbutsad", "but");
  int result4 = solution.strStr("ssssssasssssa", "ssa");
}