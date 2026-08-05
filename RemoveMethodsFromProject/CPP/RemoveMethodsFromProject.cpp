// https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05
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
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
  {
    unordered_map<int, vector<int>> invoked;
    for (auto &i : invocations)
    {
      invoked[i[0]].push_back(i[1]);
    }

    unordered_set<int> suspicious;
    getSuspicious(invoked, k, suspicious);

    vector<int> remaining;
    bool canRemove = true;
    for (int i = 0; i < n; i++)
    {
      if (suspicious.find(i) == suspicious.end())
      {
        remaining.push_back(i);
        for (int &n : invoked[i])
        {
          if (suspicious.find(n) != suspicious.end())
          {
            canRemove = false;
          }
        }
      }
    }

    if (!canRemove)
    {
      for (const auto &i : suspicious)
      {
        remaining.push_back(i);
      }
    }

    return remaining;
  }

private:
  void getSuspicious(unordered_map<int, vector<int>> &invoked, int k, unordered_set<int> &suspicious)
  {
    if (suspicious.find(k) != suspicious.end())
    {
      return;
    }

    suspicious.insert(k);

    for (int &next : invoked[k])
    {
      getSuspicious(invoked, next, suspicious);
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.remainingMethods(4, 1, *new vector<vector<int>>{{1, 2}, {0, 1}, {3, 2}});
  auto result2 = solution.remainingMethods(5, 0, *new vector<vector<int>>{{1, 2}, {0, 2}, {0, 1}, {3, 4}});
  auto result3 = solution.remainingMethods(3, 2, *new vector<vector<int>>{{1, 2}, {0, 1}, {2, 0}});
}