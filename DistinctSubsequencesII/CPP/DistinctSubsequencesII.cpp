// https://leetcode.com/problems/distinct-subsequences-ii/
// NOT MINE: https://leetcode.com/problems/distinct-subsequences-ii/discuss/192017/JavaC%2B%2BPython-DP-4-lines-O(N)-Time-O(1)-Space
#include <numeric>
#include <string>

using namespace std;

class Solution
{
public:
  int distinctSubseqII(string s)
  {
    long endsWith[26] = {}, mod = 1e9 + 7;
    for (char c : s)
      endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % mod;
    return accumulate(begin(endsWith), end(endsWith), 0L) % mod;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.distinctSubseqII("abc");
  int result2 = solution.distinctSubseqII("aba");
  int result3 = solution.distinctSubseqII("aaa");
  int result4 = solution.distinctSubseqII("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn");
}