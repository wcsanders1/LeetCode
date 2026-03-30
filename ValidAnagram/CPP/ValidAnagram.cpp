// https://leetcode.com/problems/valid-anagram/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
    {
      return false;
    }

    unordered_map<char, int> m;
    for (char &c : s)
    {
      m[c]++;
    }

    for (char &c : t)
    {
      m[c]--;
    }

    for (auto &[k, v] : m)
    {
      if (v != 0)
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

  bool result1 = solution.isAnagram("anagram", "nagaram");
  bool result2 = solution.isAnagram("rat", "car");
}