// https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maxDistance(vector<vector<int>> &arrays)
  {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ;
    priority_queue<vector<int>> maxQ;
    for (int i = 0; i < arrays.size(); i++)
    {
      minQ.push({arrays[i][0], i});
      maxQ.push({arrays[i][arrays[i].size() - 1], i});
    }

    while (!minQ.empty() && !maxQ.empty())
    {
      auto mn = minQ.top();
      auto mx = maxQ.top();
      if (mn[1] != mx[1])
      {
        return abs(mx[0] - mn[0]);
      }

      minQ.pop();
      maxQ.pop();
      if (mn[0] - minQ.top()[0] > maxQ.top()[0] - mx[0])
      {
        maxQ.push(mx);
      }
      else
      {
        minQ.push(mn);
      }
    }

    return 0;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxDistance(*new vector<vector<int>>{{1, 2, 3}, {4, 5}, {1, 2, 3}});
  int result2 = solution.maxDistance(*new vector<vector<int>>{{1}, {1}});
  int result3 = solution.maxDistance(*new vector<vector<int>>{{1, 4}, {0, 5}}); // 4
}