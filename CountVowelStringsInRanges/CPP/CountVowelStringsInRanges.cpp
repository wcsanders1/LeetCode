#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
  vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
  {
    vector<int> dp(words.size() + 1, 0);
    for (int i = 0; i < words.size(); i++)
    {
      int t = isEntry(words[i]) ? 1 : 0;
      dp[i + 1] = dp[i] + t;
    }

    vector<int> answer;
    for (vector<int> q : queries)
    {
      int end = dp[q[1] + 1];
      int start = dp[q[0]];
      answer.push_back(end - start);
    }

    return answer;
  }

private:
  bool isEntry(string w)
  {
    if ((w[0] != 'a' && w[0] != 'e' && w[0] != 'i' && w[0] != 'o' && w[0] != 'u') ||
        (w[w.size() - 1] != 'a' && w[w.size() - 1] != 'e' && w[w.size() - 1] != 'i' && w[w.size() - 1] != 'o' && w[w.size() - 1] != 'u'))
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.vowelStrings(*new vector<string>{"aba", "bcb", "ece", "aa", "e"}, *new vector<vector<int>>{{0, 2}, {1, 4}, {1, 1}, {1, 2}});
  auto result2 = solution.vowelStrings(*new vector<string>{"a", "e", "i"}, *new vector<vector<int>>{{0, 2}, {0, 1}, {2, 2}});
}