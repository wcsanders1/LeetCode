// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24
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
  int sumRootToLeaf(TreeNode *root)
  {
    return getTotal(root, root->val);
  }

private:
  int getTotal(TreeNode *node, int sum)
  {
    if (node->left == nullptr && node->right == nullptr)
    {
      return sum;
    }

    int res = 0;
    if (node->left != nullptr)
    {
      res += getTotal(node->left, (sum << 1) + node->left->val);
    }

    if (node->right != nullptr)
    {
      res += getTotal(node->right, (sum << 1) + node->right->val);
    }

    return res;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.sumRootToLeaf(new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)), new TreeNode(1, new TreeNode(0), new TreeNode(1))));
}