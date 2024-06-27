// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25
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
  TreeNode *bstToGst(TreeNode *root)
  {
    summarize(root);
    return root;
  }

private:
  int summarize(TreeNode *node, int sum = 0)
  {
    if (node == nullptr)
    {
      return sum;
    }

    node->val += summarize(node->right, sum);
    return summarize(node->left, node->val);
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.bstToGst(new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))), new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8)))));
}