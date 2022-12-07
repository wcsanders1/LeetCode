// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool areAlmostEqual(string s1, string s2)
  {
    int n = s1.size();
    int start = (int)'a';
    vector<int> chars1(26, 0);
    vector<int> chars2(26, 0);
    int diffs = 0;

    for (int i = 0; i < n; i++)
    {
      if (s1[i] != s2[i])
      {
        diffs++;
      }

      if (diffs > 2)
      {
        return false;
      }

      chars1[(int)s1[i] - start]++;
      chars2[(int)s2[i] - start]++;
    }

    diffs = 0;
    for (int i = 0; i < 26; i++)
    {
      if (chars1[i] != chars2[i])
      {
        diffs++;
      }

      if (diffs > 1)
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

  bool result1 = solution.areAlmostEqual("bank", "kanb");
  bool result2 = solution.areAlmostEqual("attack", "defend");
  bool result3 = solution.areAlmostEqual("kelb", "kelb");
  bool result4 = solution.areAlmostEqual("abcd", "dcba");
  bool result5 = solution.areAlmostEqual("siyolsdcjthwsiplccjbuceoxmpjgrauocx", "siyolsdcjthwsiplccpbuceoxmjjgrauocx");
}