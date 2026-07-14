// https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09
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
  TreeNode *balanceBST(TreeNode *root)
  {
    vector<TreeNode *> nodes;
    inOrder(root, nodes);
    return build(nodes, 0, nodes.size() - 1);
  }

private:
  void inOrder(TreeNode *node, vector<TreeNode *> &nodes)
  {
    if (node == nullptr)
    {
      return;
    }

    inOrder(node->left, nodes);
    nodes.push_back(node);
    inOrder(node->right, nodes);
  }

  TreeNode *build(vector<TreeNode *> &nodes, int start, int end)
  {
    if (start > end)
    {
      return nullptr;
    }

    int mid = (end + start) / 2;
    auto node = nodes[mid];
    node->left = build(nodes, start, mid - 1);
    node->right = build(nodes, mid + 1, end);
    return node;
  }
};

int main()
{
  Solution solution;

  auto root1 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));
  auto result1 = solution.balanceBST(root1);

  auto root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  auto result2 = solution.balanceBST(root2);
}