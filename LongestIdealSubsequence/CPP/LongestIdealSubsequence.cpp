// https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestIdealString(string s, int k)
  {
    int n = s.size();
    unordered_map<char, int> counts;

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
      char c = s[i];
      int temp = 0;
      for (auto &[prev, count] : counts)
      {
        if (abs(c - prev) <= k)
        {
          temp = max(temp, count);
        }
      }
      temp++;
      answer = max(answer, temp);
      counts[c] = temp;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestIdealString("acfgbd", 2);                     // 4
  int result2 = solution.longestIdealString("abcd", 3);                       // 4
  int result3 = solution.longestIdealString("lkpkxcigcs", 6);                 // 7
  int result4 = solution.longestIdealString("abcdefghijklmnopqrstuvwxyz", 1); // 26
}