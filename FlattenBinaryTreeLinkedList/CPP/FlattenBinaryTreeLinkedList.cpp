// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
  void flatten(TreeNode *root)
  {
    if (root == nullptr)
    {
      return;
    }

    TreeNode preorder = TreeNode(root->val);
    makePreorder(root, &preorder);

    *root = preorder;
  }

private:
  void makePreorder(TreeNode *root, TreeNode *preOrder)
  {
    if (root == nullptr)
    {
      return;
    }

    TreeNode *temp = preOrder;
    if (root->left != nullptr)
    {
      temp->right = new TreeNode(root->left->val);
      makePreorder(root->left, temp->right);
    }

    while (temp->right != nullptr)
    {
      temp = temp->right;
    }

    if (root->right != nullptr)
    {
      temp->right = new TreeNode(root->right->val);
      makePreorder(root->right, temp->right);
    }
  }
};

int main()
{
  Solution solution;

  TreeNode *node1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
  solution.flatten(node1);
}