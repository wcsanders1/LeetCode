// https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int equalSubstring(string s, string t, int maxCost)
  {
    int start = 0;
    int end = 0;
    int answer = 0;
    int current = 0;
    int n = s.size();

    while (end < n)
    {
      current += abs(s[end] - t[end]);
      while (current > maxCost)
      {
        current -= abs(s[start] - t[start]);
        start++;
      }
      answer = max(answer, (end - start) + 1);
      end++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.equalSubstring("abcd", "bcdf", 3);
  int result2 = solution.equalSubstring("abcd", "cdef", 3);
  int result3 = solution.equalSubstring("abcd", "acde", 0);
}