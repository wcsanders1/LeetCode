// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minSteps(string s, string t)
  {
    int n = s.size();
    unordered_map<char, int> s_m;
    unordered_map<char, int> t_m;
    unordered_set<char> chars;
    for (int i = 0; i < n; i++)
    {
      s_m[s[i]]++;
      t_m[t[i]]++;
      chars.insert(s[i]);
      chars.insert(t[i]);
    }

    int diff = 0;
    for (char c : chars)
    {
      int s_d = s_m.count(c) == 0 ? 0 : s_m[c];
      int t_d = t_m.count(c) == 0 ? 0 : t_m[c];
      diff += abs(s_d - t_d);
    }

    return diff / 2;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSteps("bab", "aba");
  int result2 = solution.minSteps("leetcode", "practice");
  int result3 = solution.minSteps("anagram", "mangaar");
}