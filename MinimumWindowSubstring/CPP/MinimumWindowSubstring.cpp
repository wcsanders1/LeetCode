// https://leetcode.com/problems/minimum-window-substring/description/
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
  string minWindow(string s, string t)
  {
    if (t.size() > s.size())
    {
      return "";
    }

    int needed = t.size();
    unordered_map<char, int> have;
    unordered_map<char, int> need;
    for (char &c : t)
    {
      need[c]++;
    }

    int start = getNextStart(need, have, s, 0);
    if (start == -1)
    {
      return "";
    }

    int end = start;
    needed--;
    have[s[start]]++;
    int maxlen = INT32_MAX;
    string shortest = "";

    while (end < s.size())
    {
      if (needed == 0)
      {
        int nextmaxlen = min(maxlen, (end - start) + 1);
        if (nextmaxlen < maxlen)
        {
          shortest = s.substr(start, (end - start) + 1);
          maxlen = nextmaxlen;
        }

        have[s[start]]--;
        int nextstart = getNextStart(need, have, s, start + 1);
        if (nextstart == -1)
        {
          return shortest;
        }

        if (have[s[start]] < need[s[start]])
        {
          needed++;
        }
        start = nextstart;
      }
      else
      {
        end++;
        if (end >= s.size())
        {
          return shortest;
        }

        if (need.find(s[end]) != need.end())
        {
          if (have[s[end]] < need[s[end]])
          {
            needed--;
          }
          have[s[end]]++;
        }
      }
    }

    return shortest;
  }

private:
  int getNextStart(unordered_map<char, int> &need, unordered_map<char, int> &have, string &s, int curstart)
  {
    while (curstart < s.size())
    {
      if (need.find(s[curstart]) != need.end())
      {
        if (have[s[curstart]] > need[s[curstart]])
        {
          have[s[curstart]]--;
        }
        else
        {
          return curstart;
        }
      }
      curstart++;
    }
    return -1;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.minWindow("ADOBECODEBANC", "ABC");
  string result2 = solution.minWindow("a", "a");
  string result3 = solution.minWindow("a", "aa");
}