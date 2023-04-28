// https://leetcode.com/problems/similar-string-groups/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int numSimilarGroups(vector<string> &strs)
  {
    int n = strs.size();
    vector<pair<int, string>> groups;
    for (int i = 1; i <= n; i++)
    {
      groups.push_back({i, strs[i - 1]});
    }

    for (int i = 0; i < n; i++)
    {
      auto &[g1, s1] = groups[i];
      for (int j = i + 1; j < n; j++)
      {
        auto &[g2, s2] = groups[j];
        if (g1 == g2)
        {
          continue;
        }

        if (areSimilar(s1, s2))
        {
          int low = min(g1, g2);
          int high = max(g1, g2);
          for (auto &g : groups)
          {
            if (g.first == high)
            {
              g.first = low;
            }
          }
        }
      }
    }

    unordered_set<int> s;
    for (auto g : groups)
    {
      s.insert(g.first);
    }

    return s.size();
  }

private:
  bool areSimilar(string s1, string s2)
  {
    int diffs = 0;
    for (int i = 0; i < s1.size(); i++)
    {
      if (s1[i] != s2[i])
      {
        diffs++;
      }
      if (diffs > 2)
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numSimilarGroups(*new vector<string>{"tars", "rats", "arts", "star"});
  int result2 = solution.numSimilarGroups(*new vector<string>{"omv", "ovm"});
}