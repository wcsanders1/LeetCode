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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int rob(TreeNode *root)
  {
    calculate(root);
    return root->val;
  }

private:
  void calculate(TreeNode *node)
  {
    if (node == nullptr)
    {
      return;
    }

    calculate(node->left);
    calculate(node->right);

    int childTotal =
        (node->left == nullptr
             ? 0
             : node->left->val) +
        (node->right ==
                 nullptr
             ? 0
             : node->right->val);

    int grandChildTotal = grandChildValue(node) + node->val;

    node->val = max(childTotal, grandChildTotal);
  }

  int grandChildValue(TreeNode *node)
  {
    int ll = node->left == nullptr ? 0 : node->left->left == nullptr ? 0
                                                                     : node->left->left->val;
    int lr = node->left == nullptr ? 0 : node->left->right == nullptr ? 0
                                                                      : node->left->right->val;
    int rl = node->right == nullptr ? 0 : node->right->left == nullptr ? 0
                                                                       : node->right->left->val;
    int rr = node->right == nullptr ? 0 : node->right->right == nullptr ? 0
                                                                        : node->right->right->val;

    return ll + lr + rl + rr;
  }
};