// https://leetcode.com/problems/assign-cookies/?envType=daily-question&envId=2024-01-01
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int answer = 0;
    int gp = 0;
    int sp = 0;

    while (gp < g.size() && sp < s.size())
    {
      if (g[gp] <= s[sp])
      {
        answer++;
        gp++;
      }
      sp++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findContentChildren(*new vector<int>{1, 2, 3}, *new vector<int>{1, 1});
  int result2 = solution.findContentChildren(*new vector<int>{1, 2}, *new vector<int>{1, 2, 3});
}