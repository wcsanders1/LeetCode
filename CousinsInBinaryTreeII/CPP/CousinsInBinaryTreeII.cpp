// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>

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
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    queue<TreeNode *> q;
    root->val = 0;
    q.push(root);
    while (!q.empty())
    {
      int n = q.size();
      if (n == 1)
      {
        auto node = q.front();
        q.pop();
        if (node->left != nullptr)
        {
          node->left->val = 0;
          q.push(node->left);
        }
        if (node->right != nullptr)
        {
          node->right->val = 0;
          q.push(node->right);
        }
      }
      else
      {
        unordered_map<TreeNode *, int> m;
        int total = 0;
        while (n-- > 0)
        {
          auto node = q.front();
          q.pop();
          int nodeTotal = 0;
          if (node->left != nullptr)
          {
            total += node->left->val;
            nodeTotal += node->left->val;
            q.push(node->left);
          }
          if (node->right != nullptr)
          {
            total += node->right->val;
            nodeTotal += node->right->val;
            q.push(node->right);
          }
          m[node] = nodeTotal;
        }
        for (const auto &[node, t] : m)
        {
          int cousinTotal = total - t;
          if (node->left != nullptr)
          {
            node->left->val = cousinTotal;
          }
          if (node->right != nullptr)
          {
            node->right->val = cousinTotal;
          }
        }
      }
    }

    return root;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.replaceValueInTree(new TreeNode(5, new TreeNode(4, new TreeNode(1), new TreeNode(10)), new TreeNode(9, nullptr, new TreeNode(7))));
  auto result2 = solution.replaceValueInTree(new TreeNode(3, new TreeNode(1), new TreeNode(2)));
}