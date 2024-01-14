// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool closeStrings(string word1, string word2)
  {
    if (word1.size() != word2.size())
    {
      return false;
    }

    int n = word1.size();

    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for (int i = 0; i < n; i++)
    {
      m1[word1[i]]++;
      m2[word2[i]]++;
    }

    unordered_map<int, int> g1;
    unordered_map<int, int> g2;

    for (auto &[c, n] : m1)
    {
      if (m2.count(c) == 0)
      {
        return false;
      }

      g1[n]++;
    }

    for (auto &[c, n] : m2)
    {
      if (m1.count(c) == 0)
      {
        return false;
      }

      g2[n]++;
    }

    for (auto &[g, n] : g1)
    {
      if (g2.count(g) == 0 || g2[g] != n)
      {
        return false;
      }
    }

    for (auto &[g, n] : g2)
    {
      if (g1.count(g) == 0 || g1[g] != n)
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

  bool result1 = solution.closeStrings("abc", "bca");
  bool result2 = solution.closeStrings("a", "aa");
  bool result3 = solution.closeStrings("cabbba", "abbccc");
  bool result4 = solution.closeStrings("cabbba", "abbccd");
  bool result5 = solution.closeStrings("cabbbba", "abccccc");
}