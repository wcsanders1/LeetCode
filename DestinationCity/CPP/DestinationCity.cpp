// https://leetcode.com/problems/destination-city/?envType=daily-question&envId=2023-12-15
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  string destCity(vector<vector<string>> &paths)
  {
    set<string> starts;
    for (auto &p : paths)
    {
      starts.insert(p[0]);
    }

    for (auto &p : paths)
    {
      if (starts.count(p[1]) == 0)
      {
        return p[1];
      }
    }

    return "";
  }
};