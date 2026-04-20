// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    return getCommon(root, p, q);
  }

private:
  TreeNode *getCommon(TreeNode *node, TreeNode *p, TreeNode *q)
  {
    if (node == nullptr)
    {
      return nullptr;
    }

    if (node->val == p->val || node->val == q->val)
    {
      return node;
    }

    auto left = getCommon(node->left, p, q);
    auto right = getCommon(node->right, p, q);

    if (left != nullptr && right != nullptr)
    {
      return node;
    }

    if (left != nullptr)
    {
      return left;
    }

    return right;
  }
};