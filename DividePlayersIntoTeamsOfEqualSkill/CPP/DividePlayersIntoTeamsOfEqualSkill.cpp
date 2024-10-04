// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  long long dividePlayers(vector<int> &skill)
  {
    int n = skill.size();
    sort(skill.begin(), skill.end());
    int curSkill = skill[0] + skill[n - 1];
    long long answer = skill[0] * skill[n - 1];

    for (int s = 1, e = n - 2; s < e; s++, e--)
    {
      if (skill[s] + skill[e] != curSkill)
      {
        return -1;
      }

      answer += skill[s] * skill[e];
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.dividePlayers(*new vector<int>{3, 2, 5, 1, 3, 4});
  long long result2 = solution.dividePlayers(*new vector<int>{3, 4});
  long long result3 = solution.dividePlayers(*new vector<int>{1, 1, 2, 3});
}