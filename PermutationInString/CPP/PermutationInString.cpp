// https://leetcode.com/problems/permutation-in-string/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s2.size() < s1.size())
    {
      return false;
    }

    unordered_map<char, int> needed;
    unordered_map<char, int> have;
    for (char &c : s1)
    {
      needed[c]++;
    }

    for (int i = 0; i < s1.size(); i++)
    {
      have[s2[i]]++;
    }

    int start = 0;
    int end = s1.size() - 1;
    while (end < s2.size())
    {
      bool isPermutation = true;
      for (auto &[k, v] : needed)
      {
        if (have[k] != v)
        {
          isPermutation = false;
        }
      }

      if (isPermutation)
      {
        return true;
      }

      have[s2[start++]]--;
      have[s2[++end]]++;
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.checkInclusion("ab", "eidbaooo");
  bool result2 = solution.checkInclusion("ab", "eidboaoo");
  bool result3 = solution.checkInclusion("ab", "eidboaba");
  bool result4 = solution.checkInclusion("ab", "badboaoo");
  bool result5 = solution.checkInclusion("adc", "dcda");
  bool result6 = solution.checkInclusion("hello", "ooolleoooleh");
}