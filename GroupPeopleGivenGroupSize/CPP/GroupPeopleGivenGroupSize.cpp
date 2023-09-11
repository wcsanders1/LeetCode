// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/?envType=daily-question&envId=2023-09-11
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes)
  {
    unordered_map<int, vector<vector<int>>> m;
    for (int i = 0; i < groupSizes.size(); i++)
    {
      int g = groupSizes[i];
      if (m.count(g) == 0)
      {
        m[g] = vector<vector<int>>();
        m[g].push_back(vector<int>());
      }

      if (m[g].back().size() == g)
      {
        m[g].push_back(vector<int>());
      }

      m[g].back().push_back(i);
    }

    vector<vector<int>> answer;
    for (auto &[k, v] : m)
    {
      for (auto &groups : v)
      {
        answer.push_back(groups);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.groupThePeople(*new vector<int>{3, 3, 3, 3, 3, 1, 3});
  auto result2 = solution.groupThePeople(*new vector<int>{2, 1, 3, 3, 3, 2});
}