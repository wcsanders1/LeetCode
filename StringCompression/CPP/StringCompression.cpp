// https://leetcode.com/problems/string-compression/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    int i = 0;
    while (i < chars.size() - 1)
    {
      int sames = 0;
      int start = i + 1;
      int j = i;
      while (j < chars.size() - 1 && chars[j] == chars[j + 1])
      {
        sames++;
        j++;
      }

      i += sames + 1;
      if (sames > 0)
      {
        for (char s : to_string(sames + 1))
        {
          chars[start++] = s;
          sames--;
        }
        while (sames-- > 0)
        {
          chars[start++] = '\0';
        }
      }
    }

    for (int i = 0; i < chars.size(); i++)
    {
      if (chars[i] == '\0')
      {
        chars.erase(chars.begin() + i);
        i--;
      }
    }

    return chars.size();
  }
};

int main()
{
  Solution solution;

  int result1 = solution.compress(*new vector<char>{'a', 'a', 'b', 'b', 'c', 'c', 'c'});
  int result2 = solution.compress(*new vector<char>{'a'});
  int result3 = solution.compress(*new vector<char>{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
  int result4 = solution.compress(*new vector<char>{'a', 'a'});
  int result5 = solution.compress(*new vector<char>{'%', '%', '2', '2', '2'});
}