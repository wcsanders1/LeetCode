// https://leetcode.com/problems/edit-distance/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    if (word1.size() == 0)
    {
      return word2.size();
    }

    if (word2.size() == 0)
    {
      return word1.size();
    }

    if (word1 == word2)
    {
      return 0;
    }

    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i <= word1.size(); i++)
    {
      dp[i][0] = i;
    }

    for (int i = 1; i <= word2.size(); i++)
    {
      dp[0][i] = i;
    }

    for (int w1 = 0; w1 < word1.size(); w1++)
    {
      for (int w2 = 0; w2 < word2.size(); w2++)
      {
        if (word1[w1] == word2[w2])
        {
          dp[w1 + 1][w2 + 1] = dp[w1][w2];
        }
        else
        {
          int least = min(dp[w1][w2], min(dp[w1 + 1][w2], dp[w1][w2 + 1]));
          dp[w1 + 1][w2 + 1] = least + 1;
        }
      }
    }

    return dp[word1.size()][word2.size()];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minDistance("horse", "ros");
  int result2 = solution.minDistance("intention", "execution");
  int result3 = solution.minDistance("r", "rrr");
  int result4 = solution.minDistance("william", "bill");
}