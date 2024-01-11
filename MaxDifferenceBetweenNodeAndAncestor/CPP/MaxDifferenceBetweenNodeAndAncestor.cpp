// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
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
  int maxAncestorDiff(TreeNode *root)
  {
    return getMax(root, root->val, root->val);
  }

private:
  int getMax(TreeNode *node, int maxVal, int minVal)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int newMax = max(maxVal, node->val);
    int newMin = min(minVal, node->val);

    int current = max(abs(node->val - newMax), abs(node->val - newMin));
    int left = getMax(node->left, newMax, newMin);
    int right = getMax(node->right, newMax, newMin);

    return max(left, max(right, current));
  }
};