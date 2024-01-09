// https://leetcode.com/problems/leaf-similar-trees/?envType=daily-question&envId=2024-01-09
#include <vector>
#include <unordered_set>
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
  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {
    vector<int> l1;
    vector<int> l2;
    getLeaves(root1, l1);
    getLeaves(root2, l2);

    if (l1.size() != l2.size())
    {
      return false;
    }

    for (int i = 0; i < l1.size(); i++)
    {
      if (l1[i] != l2[i])
      {
        return false;
      }
    }

    return true;
  }

private:
  void getLeaves(TreeNode *node, vector<int> &leaves)
  {
    if (node == nullptr)
    {
      return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
      leaves.push_back(node->val);
      return;
    }

    getLeaves(node->left, leaves);
    getLeaves(node->right, leaves);
  }
};