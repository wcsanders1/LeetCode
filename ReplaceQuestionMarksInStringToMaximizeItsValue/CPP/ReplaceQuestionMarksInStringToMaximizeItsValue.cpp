// https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/submissions/1205461939/
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
  string minimizeStringValue(string s)
  {
    int n = s.size();
    vector<int> minCost(n, 0);
    unordered_map<char, int> occurences;

    for (char c = 'a'; c <= 'z'; c++)
    {
      occurences[c] = 0;
    }

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '?')
      {
        continue;
      }

      minCost[i] = occurences[s[i]]++;
    }

    string news = "";
    for (int i = 0; i < n; i++)
    {
      if (s[i] != '?')
      {
        continue;
      }
      int mino = INT32_MAX;
      char minc = '?';
      for (auto [c, n] : occurences)
      {
        if (n < mino)
        {
          minc = c;
          mino = n;
        }
        else if (n == mino)
        {
          minc = min(minc, c);
        }
      }

      news += minc;
      occurences[minc]++;
    }

    sort(news.begin(), news.end());

    int j = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '?')
      {
        s[i] = news[j++];
      }
    }

    return s;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.minimizeStringValue("???");
  string result2 = solution.minimizeStringValue("a?a?");
  string result3 = solution.minimizeStringValue("abcdefghijklmnopqrstuvwxy??");
  string result4 = solution.minimizeStringValue("g?xvgroui??xk?zqb?da?jan?cdhtksme");
}