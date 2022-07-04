// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
// not mine: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/discuss/1674049/Mutual-Favorites
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  int maximumInvitations(vector<int> &favorite)
  {
    vector<vector<int>> reverseGraph(favorite.size());
    for (int i = 0; i < favorite.size(); i++)
    {
      if (favorite[favorite[i]] != i)
      {
        reverseGraph[favorite[i]].push_back(i);
      }
    }

    int result = 0;
    vector<bool> visited(favorite.size(), false);
    for (int i = 0; i < favorite.size(); i++)
    {
      if (favorite[favorite[i]] == i)
      {
        result += dfs(i, reverseGraph, visited);
      }
    }

    for (int i = 0; i < favorite.size(); i++)
    {
      int count = 0;
      int j = i;

      while (!visited[j])
      {
        visited[j] = true;
        j = favorite[j];
        count++;
      }

      for (int k = i; k != j; k = favorite[k])
      {
        count--;
      }

      result = max(result, count);
    }

    return result;
  }

private:
  int dfs(int index, vector<vector<int>> &reverseGraph, vector<bool> &visited)
  {
    visited[index] = true;
    return 1 + accumulate(begin(reverseGraph[index]), end(reverseGraph[index]), 0, [&](int res, int j)
                          { return max(res, dfs(j, reverseGraph, visited)); });
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximumInvitations(*new vector<int>{2, 2, 1, 2});                           // 3
  int result2 = solution.maximumInvitations(*new vector<int>{1, 2, 0});                              // 3
  int result3 = solution.maximumInvitations(*new vector<int>{3, 0, 1, 4, 1});                        // 4
  int result4 = solution.maximumInvitations(*new vector<int>{1, 2, 3, 4, 5, 6, 3, 8, 9, 10, 11, 8}); // 4
}