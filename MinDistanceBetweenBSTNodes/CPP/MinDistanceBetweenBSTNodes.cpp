// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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
  int minDiffInBST(TreeNode *root)
  {
    answer = INT32_MAX;
    pre = -1;
    traverseInOrder(root);

    return answer;
  }

private:
  int answer = INT32_MAX;
  int pre = -1;
  void traverseInOrder(TreeNode *node)
  {
    if (node->left != nullptr)
    {
      traverseInOrder(node->left);
    }

    if (pre != -1)
    {
      answer = min(answer, abs(pre - node->val));
    }

    pre = node->val;

    if (node->right != nullptr)
    {
      traverseInOrder(node->right);
    }
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minDiffInBST(
      new TreeNode(4,
                   new TreeNode(2,
                                new TreeNode(1), new TreeNode(3)),
                   new TreeNode(6)));

  int result2 = solution.minDiffInBST(
      new TreeNode(90,
                   new TreeNode(69,
                                new TreeNode(49, nullptr, new TreeNode(52)),
                                new TreeNode(89)),
                   nullptr));

  int result3 = solution.minDiffInBST(
      new TreeNode(96,
                   new TreeNode(12, nullptr,
                                new TreeNode(13, nullptr,
                                             new TreeNode(52, new TreeNode(29), nullptr))),
                   nullptr));
}