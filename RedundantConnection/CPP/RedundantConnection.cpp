// https://leetcode.com/problems/redundant-connection/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    vector<int> roots(edges.size());
    for (int i = 0; i < roots.size(); i++)
    {
      roots[i] = i + 1;
    }

    vector<int> answer;

    for (vector<int> edge : edges)
    {
      int root1 = find(roots, edge[0]);
      int root2 = find(roots, edge[1]);

      if (root1 == root2)
      {
        answer = edge;
      }
      else
      {
        unify(roots, edge);
      }
    }

    return answer;
  }

private:
  void unify(vector<int> &roots, vector<int> &edge)
  {
    int root1 = find(roots, edge[0]);
    int root2 = find(roots, edge[1]);
    roots[root2 - 1] = roots[root1 - 1];
  }

  int find(vector<int> &roots, int node)
  {
    int i = node;
    while (roots[i - 1] != i)
    {
      i = roots[i - 1];
    }

    return i;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.findRedundantConnection(*new vector<vector<int>>{vector<int>{1, 2}, vector<int>{1, 3}, vector<int>{2, 3}});
  vector<int> result2 = solution.findRedundantConnection(*new vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}, vector<int>{1, 4}, vector<int>{1, 5}});
  vector<int> result3 = solution.findRedundantConnection(*new vector<vector<int>>{
      vector<int>{9, 10},
      vector<int>{5, 8},
      vector<int>{2, 6},
      vector<int>{1, 5},
      vector<int>{3, 8},
      vector<int>{4, 9},
      vector<int>{8, 10},
      vector<int>{4, 10},
      vector<int>{6, 8},
      vector<int>{7, 9}});
}