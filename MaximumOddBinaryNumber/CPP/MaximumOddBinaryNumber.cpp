// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
  string maximumOddBinaryNumber(string s)
  {
    int n = s.size();
    int ones = 0;
    for (char &c : s)
    {
      if (c == '1')
      {
        ones++;
      }
    }

    int changes = 0;
    if (s[n - 1] == '0')
    {
      s[n - 1] = '1';
      ones--;
      changes++;
    }

    for (int i = 0; i <= n; i++)
    {
      if (s[i] == '0' && ones > 0)
      {
        s[i] = '1';
        ones--;
        changes++;
      }
    }

    for (int i = n - 2; i >= 0, changes > 0; i--)
    {
      if (s[i] == '1')
      {
        s[i] = '0';
        changes--;
      }
    }

    return s;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.maximumOddBinaryNumber("010");
  string result2 = solution.maximumOddBinaryNumber("0101");
  string result3 = solution.maximumOddBinaryNumber("1100");
  string result4 = solution.maximumOddBinaryNumber("110100");
}