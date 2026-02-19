// https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int countBinarySubstrings(string s)
  {
    unordered_map<char, int> counts;
    counts['0'] = 0;
    counts['1'] = 0;
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (i > 0 && s[i] != s[i - 1] && counts[s[i]] > 0)
      {
        answer += min(counts['0'], counts['1']);
        counts[s[i]] = 1;
      }
      else
      {
        counts[s[i]]++;
      }

      if (i == s.size() - 1)
      {
        answer += min(counts['0'], counts['1']);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countBinarySubstrings("00110011");
  int result2 = solution.countBinarySubstrings("10101");
  int result3 = solution.countBinarySubstrings("00000");
  int result4 = solution.countBinarySubstrings("00001");
  int result5 = solution.countBinarySubstrings("10001");
}