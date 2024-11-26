// https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int findChampion(int n, vector<vector<int>> &edges)
  {
    vector<bool> weaker(n, false);
    for (auto &edge : edges)
    {
      weaker[edge[1]] = true;
    }

    int answer = -1;
    for (int i = 0; i < n; i++)
    {
      bool w = weaker[i];
      if (w == false)
      {
        if (answer != -1)
        {
          return -1;
        }
        answer = i;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findChampion(3, *new vector<vector<int>>{{0, 1}, {1, 2}});
  int result2 = solution.findChampion(4, *new vector<vector<int>>{{0, 2}, {1, 3}, {1, 2}});
}