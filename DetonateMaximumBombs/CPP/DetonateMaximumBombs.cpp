// https://leetcode.com/problems/detonate-the-maximum-bombs/
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maximumDetonation(vector<vector<int>> &bombs)
  {
    int n = bombs.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
      m[i] = vector<int>();
      auto &bomb1 = bombs[i];
      for (int j = 0; j < n; j++)
      {
        if (i == j)
        {
          continue;
        }
        auto &bomb2 = bombs[j];

        if (isInside(bomb1[0], bomb1[1], bomb1[2], bomb2[0], bomb2[1]))
        {
          m[i].push_back(j);
        }
      }
    }

    int answer = 0;
    for (int b = 0; b < n; b++)
    {
      vector<bool> visited(n, false);
      answer = max(answer, getBlastCount(visited, m, b));
    }

    return answer;
  }

private:
  int getBlastCount(vector<bool> &visited, unordered_map<int, vector<int>> &m, int bomb)
  {
    if (visited[bomb])
    {
      return 0;
    }

    visited[bomb] = true;

    int count = 1;
    for (int b : m[bomb])
    {
      count += getBlastCount(visited, m, b);
    }

    return count;
  }

  bool isInside(long long cx, long long cy, long long radius, long long x, long long y)
  {
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= radius * radius;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximumDetonation(*new vector<vector<int>>{{2, 1, 3}, {6, 1, 4}});
  int result2 = solution.maximumDetonation(*new vector<vector<int>>{{1, 1, 5}, {10, 10, 5}});
  int result3 = solution.maximumDetonation(*new vector<vector<int>>{{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}});
}