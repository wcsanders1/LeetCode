// https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

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
  bool isBalanced(TreeNode *root)
  {
    return getDepth(root) != -1;
  }

private:
  int getDepth(TreeNode *node, int depth = 1)
  {
    if (node == nullptr)
    {
      return depth - 1;
    }

    int leftDepth = getDepth(node->left, depth + 1);
    int rightDepth = getDepth(node->right, depth + 1);
    if (leftDepth == -1 || rightDepth == -1)
    {
      return -1;
    }

    if (abs(leftDepth - rightDepth) > 1)
    {
      return -1;
    }

    return max(leftDepth, rightDepth);
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isBalanced(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  bool result2 = solution.isBalanced(new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)), new TreeNode(2)));
}