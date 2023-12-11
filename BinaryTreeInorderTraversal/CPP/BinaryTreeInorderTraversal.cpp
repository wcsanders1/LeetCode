// https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=daily-question&envId=2023-12-09
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

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
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> answer;
    inorder(answer, root);
    return answer;
  }

private:
  void inorder(vector<int> &answer, TreeNode *node)
  {
    if (node == nullptr)
    {
      return;
    }

    inorder(answer, node->left);
    answer.push_back(node->val);
    inorder(answer, node->right);
  }
};