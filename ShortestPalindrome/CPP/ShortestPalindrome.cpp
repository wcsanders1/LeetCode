// https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20
// NOT MINE: https://leetcode.com/problems/shortest-palindrome/solutions/60099/ac-in-288-ms-simple-brute-force/?envType=daily-question&envId=2024-09-20
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  string shortestPalindrome(string s)
  {
    int n = s.size();
    string r = s;
    reverse(r.begin(), r.end());

    const string_view svS(s);
    const string_view svR(r);

    for (int i = 0; i < n; i++)
    {
      if (svR.substr(i) == svS.substr(0, n - i))
      {
        return r.substr(0, i) + s;
      }
    }

    return r + s;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.shortestPalindrome("aacecaaa");
  string result2 = solution.shortestPalindrome("abcd");
  string result3 = solution.shortestPalindrome("aabba");
  string result4 = solution.shortestPalindrome("adcba");
}