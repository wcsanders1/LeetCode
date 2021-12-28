#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
  int minCut(string s)
  {
    return getMinCut(s, *new map<string, int>());
  }

private:
  int getMinCut(string s, map<string, int> &cache)
  {
    if (cache.count(s))
    {
      return cache[s];
    }

    if (isPalindrome(s))
    {
      cache.insert({s, 0});
      return 0;
    }

    int result = INT32_MAX;
    for (int i = 0; i < s.size() - 1; i++)
    {
      int tempResult = getMinCut(s.substr(0, i + 1), cache) + getMinCut(s.substr(i + 1, s.size() - i), cache) + 1;
      if (tempResult < result)
      {
        result = tempResult;
      }
    }

    cache.insert({s, result});
    return result;
  }

  bool isPalindrome(string s)
  {
    int start = 0;
    int end = s.size() - 1;

    while (start <= end)
    {
      if (s[start++] != s[end--])
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

  int result1 = solution.minCut("baab");                                               // 0
  int result2 = solution.minCut("aab");                                                // 1
  int result3 = solution.minCut("a");                                                  // 0
  int result4 = solution.minCut("ab");                                                 // 1
  int result5 = solution.minCut("aabbccdd");                                           // 3
  int result6 = solution.minCut("abcdefgfedcba");                                      // 0
  int result7 = solution.minCut("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj"); // 42
  // int result8 = solution.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
}