// https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestPalindrome(string s)
  {
    unordered_map<char, int> m;
    for (char &c : s)
    {
      m[c]++;
    }

    int answer = 0;
    bool oddTaken = false;
    for (auto &[_, i] : m)
    {
      if (!oddTaken && i % 2 == 1)
      {
        oddTaken = true;
        answer++;
      }

      i = (i % 2 == 1) ? i - 1 : i;
      answer += i;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestPalindrome("abccccdd");
  int result2 = solution.longestPalindrome("a");
}