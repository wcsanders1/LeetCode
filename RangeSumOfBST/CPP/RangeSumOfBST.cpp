// https://leetcode.com/problems/range-sum-of-bst/?envType=daily-question&envId=2024-01-08
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
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (root == nullptr)
    {
      return 0;
    }

    int left = (root->val >= low) ? rangeSumBST(root->left, low, high) : 0;
    int right = (root->val <= high) ? rangeSumBST(root->right, low, high) : 0;
    int current = (root->val >= low && root->val <= high) ? root->val : 0;

    return left + right + current;
  }
};