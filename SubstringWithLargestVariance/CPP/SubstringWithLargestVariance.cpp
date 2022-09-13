// https://leetcode.com/problems/substring-with-largest-variance/
// NOT MINE: https://leetcode.com/problems/substring-with-largest-variance/discuss/2039178/Weird-Kadane
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int largestVariance(string s)
  {
    int answer = 0;
    unordered_set<char> unique(s.begin(), s.end());

    for (char a : unique)
    {
      for (char b : unique)
      {
        int variance = 0;
        bool has_b = false;
        bool first_b = false;

        for (char ch : s)
        {
          if (ch == a)
          {
            variance++;
          }

          if (ch == b)
          {
            has_b = true;
            if (first_b && variance >= 0)
            {
              first_b = false;
            }
            else if (--variance < 0)
            {
              first_b = true;
              variance = -1;
            }
          }

          answer = max(answer, has_b ? variance : 0);
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.largestVariance("aababbb");
  int result2 = solution.largestVariance("abcde");
  int result3 = solution.largestVariance("aabbbbaabbbaaaaba");
}