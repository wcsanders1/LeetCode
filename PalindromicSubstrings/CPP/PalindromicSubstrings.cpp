// https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int countSubstrings(string s)
  {
    int answer = 0;
    for (int start = 0; start < s.size(); start++)
    {
      for (int end = start; end < s.size(); end++)
      {
        if (isPalindrome(s, start, end))
        {
          answer++;
        }
      }
    }

    return answer;
  }

private:
  bool isPalindrome(string &s, int start, int end)
  {
    while (start <= end)
    {
      if (start == end)
      {
        return true;
      }
      if (s[start++] != s[end--])
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

  int result1 = solution.countSubstrings("abc");
  int result2 = solution.countSubstrings("aaa");
  int result3 = solution.countSubstrings("abcba");
}