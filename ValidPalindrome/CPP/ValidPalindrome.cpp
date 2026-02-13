// https://leetcode.com/problems/valid-palindrome/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
      if (!isalnum(s[start]))
      {
        start++;
        continue;
      }

      if (!isalnum(s[end]))
      {
        end--;
        continue;
      }

      if (tolower(s[start]) != tolower(s[end]))
      {
        return false;
      }

      start++;
      end--;
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isPalindrome("A man, a plan, a canal: Panama");
  bool result2 = solution.isPalindrome("race a car");
  bool result3 = solution.isPalindrome(" ");
}