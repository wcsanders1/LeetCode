// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/?envType=daily-question&envId=2024-06-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class UnionFind
{
public:
  UnionFind(int amount)
  {
    for (int i = 0; i <= amount; i++)
    {
      parents.push_back(i);
    }
    ranks = vector<int>(amount + 1, 0);
    groups = amount;
  }
  int find(int i)
  {
    if (parents[i] == i)
    {
      return i;
    }

    int parent = find(parents[i]);
    parents[i] = parent;
    return parent;
  }
  void unite(int a, int b)
  {
    int aParent = find(a);
    int bParent = find(b);
    if (aParent == bParent)
    {
      return;
    }

    if (ranks[aParent] < ranks[bParent])
    {
      parents[aParent] = bParent;
    }
    else if (ranks[aParent] > ranks[bParent])
    {
      parents[bParent] = aParent;
    }
    else
    {
      parents[aParent] = bParent;
      ranks[bParent]++;
    }
    groups--;
  }
  int getGroups()
  {
    return groups;
  }

private:
  vector<int> parents;
  vector<int> ranks;
  int groups;
};

class Solution
{
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
  {
    UnionFind alice(n);
    UnionFind bob(n);
    sort(edges.begin(), edges.end(), greater<vector<int>>());
    int edgesUsed = 0;
    for (auto &edge : edges)
    {
      int used = 0;
      if ((edge[0] == 1 || edge[0] == 3) && alice.find(edge[1]) != alice.find(edge[2]))
      {
        used = 1;
        alice.unite(edge[1], edge[2]);
      }

      if ((edge[0] == 2 || edge[0] == 3) && bob.find(edge[1]) != bob.find(edge[2]))
      {
        used = 1;
        bob.unite(edge[1], edge[2]);
      }

      edgesUsed += used;
    }

    if (alice.getGroups() > 1 || bob.getGroups() > 1)
    {
      return -1;
    }

    return edges.size() - edgesUsed;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxNumEdgesToRemove(4, *new vector<vector<int>>{{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}});
  int result2 = solution.maxNumEdgesToRemove(4, *new vector<vector<int>>{{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}});
  int result3 = solution.maxNumEdgesToRemove(4, *new vector<vector<int>>{{3, 2, 3}, {1, 1, 2}, {2, 3, 4}});
}