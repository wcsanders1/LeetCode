// https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
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
  int diameterOfBinaryTree(TreeNode *root)
  {
    unordered_map<TreeNode *, int> deepest;
    getMaxDepth(root, deepest);

    int answer = 0;
    for (auto const &[node, _] : deepest)
    {
      int left = node->left == nullptr ? 0 : (deepest[node->left] + 1);
      int right = node->right == nullptr ? 0 : (deepest[node->right] + 1);
      answer = max(answer, left + right);
    }

    return answer;
  }

private:
  int getMaxDepth(TreeNode *node, unordered_map<TreeNode *, int> &deepest)
  {
    if (node == nullptr)
    {
      return -1;
    }

    deepest[node] = max(getMaxDepth(node->left, deepest) + 1, getMaxDepth(node->right, deepest) + 1);
    return deepest[node];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.diameterOfBinaryTree(new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3)));
  int result2 = solution.diameterOfBinaryTree(new TreeNode(1, new TreeNode(2), nullptr));
}