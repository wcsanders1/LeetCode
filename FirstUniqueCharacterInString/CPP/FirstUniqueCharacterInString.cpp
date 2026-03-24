// https://leetcode.com/problems/first-unique-character-in-a-string/description/
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
  int firstUniqChar(string s)
  {
    unordered_map<char, int> m;
    for (char &c : s)
    {
      m[c]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
      if (m[s[i]] == 1)
      {
        return i;
      }
    }

    return -1;
  }
};