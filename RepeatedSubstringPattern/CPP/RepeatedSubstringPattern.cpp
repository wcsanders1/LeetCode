// https://leetcode.com/problems/repeated-substring-pattern/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    int n = s.size();
    int end = n;
    string original = s;
    s += s;
    for (int i = 1; end < s.size() - 1; i++, end++)
    {
      if (s.substr(i, n) == original)
      {
        return true;
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.repeatedSubstringPattern("abab");         // true
  bool result2 = solution.repeatedSubstringPattern("aba");          // false
  bool result3 = solution.repeatedSubstringPattern("abcabcabcabc"); // true
  bool result4 = solution.repeatedSubstringPattern("ababab");       // true
  bool result5 = solution.repeatedSubstringPattern("abac");         // false
  bool result6 = solution.repeatedSubstringPattern("aaaa");         // true
}