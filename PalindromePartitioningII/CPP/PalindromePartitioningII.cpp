#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
  int minCut(string s)
  {
    int size = s.size();
    vector<int> cut(size + 1, 0);
    for (int i = 0; i <= size; i++)
    {
      cut[i] = i - 1;
    }

    for (int i = 0; i < size; i++)
    {
      for (int j = 0; i - j >= 0 && i + j < size && s[i - j] == s[i + j]; j++)
      {
        cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
      }

      for (int j = 1; i - j + 1 >= 0 && i + j < size && s[i - j + 1] == s[i + j]; j++)
      {
        cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
      }
    }

    return cut[size];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCut("baab");                                               // 0
  int result2 = solution.minCut("aab");                                                // 1
  int result3 = solution.minCut("a");                                                  // 0
  int result4 = solution.minCut("ab");                                                 // 1
  int result5 = solution.minCut("aabbaaccdd");                                         // 2
  int result6 = solution.minCut("abcdefgfedcba");                                      // 0
  int result7 = solution.minCut("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj"); // 42
  int result8 = solution.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
}