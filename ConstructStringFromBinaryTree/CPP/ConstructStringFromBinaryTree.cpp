// https://leetcode.com/problems/construct-string-from-binary-tree/?envType=daily-question&envId=2023-12-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
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
  string tree2str(TreeNode *root)
  {
    string s = "";
    preorder(root, s);
    return s;
  }

private:
  void preorder(TreeNode *root, string &s)
  {
    s += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
      return;
    }

    s += "(";
    if (root->left != nullptr)
    {
      preorder(root->left, s);
    }
    s += ")";

    if (root->right != nullptr)
    {
      s += "(";
      preorder(root->right, s);
      s += ")";
    }
  }
};

int main()
{
  Solution solution;

  string result1 = solution.tree2str(new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3)));
  string result2 = solution.tree2str(new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3)));
}