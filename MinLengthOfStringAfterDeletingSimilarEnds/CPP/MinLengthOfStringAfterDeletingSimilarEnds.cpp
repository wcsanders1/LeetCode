// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
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
  int minimumLength(string s)
  {
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
      if (s[start] != s[end])
      {
        return (end - start) + 1;
      }

      int diff = end - start;

      char c = s[start];
      while (s[start] == c)
      {
        start++;
      }

      if (start >= end)
      {
        return 0;
      }

      while (s[end] == c)
      {
        end--;
      }
    }

    return start > end ? 0 : 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumLength("ca");                    // 2
  int result2 = solution.minimumLength("cabaabac");              // 0
  int result3 = solution.minimumLength("aabccabba");             // 3
  int result4 = solution.minimumLength("aba");                   // 1
  int result5 = solution.minimumLength("abbbbbbbaabbbbbbbaa");   // 0
  int result6 = solution.minimumLength("bbbbbbbbbbbbbbbbbbb");   // 0
  int result7 = solution.minimumLength("abbbbbbbbbbbbbbbbbbba"); // 0
}