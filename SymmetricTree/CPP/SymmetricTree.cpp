// https://leetcode.com/problems/symmetric-tree/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isSymmetric(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      vector<TreeNode *> nodes;
      for (int i = 0; i < n; i++)
      {
        auto node = q.front();
        q.pop();
        nodes.push_back(node);

        if (node->left != nullptr)
        {
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }

      int start = 0;
      int end = nodes.size() - 1;

      while (start <= end)
      {
        if (!areEqual(nodes[start]->left, nodes[end]->right) || !areEqual(nodes[start]->right, nodes[end]->left))
        {
          return false;
        }

        start++;
        end--;
      }
    }

    return true;
  }

private:
  bool areEqual(TreeNode *node1, TreeNode *node2)
  {
    if (node1 == nullptr && node2 == nullptr)
    {
      return true;
    }

    if (node1 == nullptr || node2 == nullptr)
    {
      return false;
    }

    return node1->val == node2->val;
  }
};