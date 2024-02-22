// https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    if (n == 1 && trust.size() == 0)
    {
      return 1;
    }

    unordered_map<int, unordered_set<int>> trusted_to_trustors;
    unordered_map<int, unordered_set<int>> trustor_to_trusted;
    for (auto &t : trust)
    {
      trusted_to_trustors[t[1]].insert(t[0]);
      trustor_to_trusted[t[0]].insert(t[1]);
    }

    for (auto &[trusted, trustors] : trusted_to_trustors)
    {
      if (trustors.size() == n - 1 && trustors.count(trusted) == 0 && trustor_to_trusted[trusted].size() == 0)
      {
        return trusted;
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findJudge(2, *new vector<vector<int>>{{1, 2}});
  int result2 = solution.findJudge(3, *new vector<vector<int>>{{1, 3}, {2, 3}});
  int result3 = solution.findJudge(3, *new vector<vector<int>>{{1, 3}, {2, 3}, {3, 1}});
}