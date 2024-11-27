// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/?envType=daily-question&envId=2024-11-27
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
  {
    unordered_map<int, vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
      edges[i].push_back(i + 1);
    }

    int end = n - 1;
    vector<int> answer;
    for (auto &query : queries)
    {
      edges[query[0]].push_back(query[1]);

      getDistace(answer, edges, n);
    }

    return answer;
  }

private:
  void getDistace(vector<int> &distances, unordered_map<int, vector<int>> &edges, int n)
  {
    queue<int> q;
    vector<bool> visited(n, false);
    for (int edge : edges[0])
    {
      q.push(edge);
      visited[edge] = true;
    }

    int depth = 1;
    int end = n - 1;
    while (!q.empty())
    {
      int count = q.size();
      while (count-- > 0)
      {
        int next = q.front();
        q.pop();
        if (next == end)
        {
          distances.push_back(depth);
          return;
        }

        for (int edge : edges[next])
        {
          if (!visited[edge])
          {
            q.push(edge);
            visited[edge] = true;
          }
        }
      }
      depth++;
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.shortestDistanceAfterQueries(5, *new vector<vector<int>>{{2, 4}, {0, 2}, {0, 4}}); // [3, 2, 1]
  auto result2 = solution.shortestDistanceAfterQueries(4, *new vector<vector<int>>{{0, 3}, {0, 2}});         // [1, 1]
  auto result3 = solution.shortestDistanceAfterQueries(6, *new vector<vector<int>>{{1, 3}, {3, 5}});         // [4, 3]
}