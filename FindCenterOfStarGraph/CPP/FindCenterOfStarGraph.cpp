// https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int findCenter(vector<vector<int>> &edges)
  {
    unordered_map<int, int> count;
    int answer = 0;
    int greatest = 0;
    for (auto &edge : edges)
    {
      count[edge[0]]++;
      count[edge[1]]++;
      if (count[edge[0]] > greatest)
      {
        greatest = count[edge[0]];
        answer = edge[0];
      }

      if (count[edge[1]] > greatest)
      {
        greatest = count[edge[1]];
        answer = edge[1];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findCenter(*new vector<vector<int>>{{1, 2}, {2, 3}, {4, 2}});
  int result2 = solution.findCenter(*new vector<vector<int>>{{1, 2}, {5, 1}, {1, 3}, {1, 4}});
}