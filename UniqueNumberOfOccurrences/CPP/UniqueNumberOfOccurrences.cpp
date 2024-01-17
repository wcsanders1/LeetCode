// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool uniqueOccurrences(vector<int> &arr)
  {
    unordered_map<int, int> m;
    for (int n : arr)
    {
      m[n]++;
    }

    unordered_set<int> s;
    for (auto &[_, c] : m)
    {
      if (s.count(c) > 0)
      {
        return false;
      }
      s.insert(c);
    }

    return true;
  }
};