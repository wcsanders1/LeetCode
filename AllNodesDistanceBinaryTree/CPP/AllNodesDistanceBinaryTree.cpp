// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    vector<int> nodes;
    unordered_map<int, vector<TreeNode *>> graph;
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (graph.count(node->val) == 0)
      {
        graph[node->val] = vector<TreeNode *>();
      }

      if (node->left != nullptr)
      {
        graph[node->val].push_back(node->left);
        if (graph.count(node->left->val) == 0)
        {
          graph[node->left->val] = vector<TreeNode *>();
        }
        graph[node->left->val].push_back(node);
        q.emplace(node->left);
      }

      if (node->right != nullptr)
      {
        graph[node->val].push_back(node->right);
        if (graph.count(node->right->val) == 0)
        {
          graph[node->right->val] = vector<TreeNode *>();
        }
        graph[node->right->val].push_back(node);
        q.emplace(node->right);
      }
    }

    vector<bool> visited(graph.size(), false);
    for (auto it : graph)
    {
      if (it.first == target->val)
      {
        visited[it.first] = true;
        getNodes(graph, nodes, it.first, k, visited);
        visited[it.first] = false;
      }
    }

    return nodes;
  }

private:
  void getNodes(unordered_map<int, vector<TreeNode *>> &graph, vector<int> &nodes, int currentVal, int distance, vector<bool> &visited)
  {
    if (distance == 0)
    {
      nodes.push_back(currentVal);
      return;
    }

    for (TreeNode *node : graph[currentVal])
    {
      if (visited[node->val])
      {
        continue;
      }

      visited[node->val] = true;
      getNodes(graph, nodes, node->val, distance - 1, visited);
      visited[node->val] = false;
    }
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.distanceK(
      new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
                   new TreeNode(1, new TreeNode(0), new TreeNode(8))),
      new TreeNode(5), 2);

  vector<int> result2 = solution.distanceK(new TreeNode(1), new TreeNode(1), 3);
}