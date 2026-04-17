// https://leetcode.com/problems/validate-binary-search-tree/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

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
  bool isValidBST(TreeNode *root)
  {
    if (root == nullptr)
    {
      return true;
    }

    return isValidBST(root, INT64_MIN, INT64_MAX);
  }

private:
  bool isValidBST(TreeNode *node, long long mn, long long mx)
  {
    if (node == nullptr)
    {
      return true;
    }

    if (node->left != nullptr && (node->left->val >= node->val || node->left->val <= mn))
    {
      return false;
    }

    if (node->right != nullptr && (node->right->val <= node->val || node->right->val >= mx))
    {
      return false;
    }

    return isValidBST(node->left, mn, min(mx, (long long)node->val)) && isValidBST(node->right, max(mn, (long long)node->val), mx);
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isValidBST(new TreeNode(2, new TreeNode(1), new TreeNode(3)));                                   // true
  bool result2 = solution.isValidBST(new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)))); // false
  bool result3 = solution.isValidBST(new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)))); // false
  bool result4 = solution.isValidBST(new TreeNode(-2147483648, nullptr, new TreeNode(2147483647)));                        // true
}