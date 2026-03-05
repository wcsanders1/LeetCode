// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
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
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> vals;
    pot(root, vals);
    return vals;
  }

private:
  void pot(TreeNode *node, vector<int> &vals)
  {
    if (node == nullptr)
    {
      return;
    }

    pot(node->left, vals);
    pot(node->right, vals);
    vals.push_back(node->val);
  }
};