// https://leetcode.com/problems/binary-search-tree-iterator/description/
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

class BSTIterator
{
public:
  BSTIterator(TreeNode *root)
  {
    collect(root);
  }

  int next()
  {
    int val = nodes.front()->val;
    nodes.pop();
    return val;
  }

  bool hasNext()
  {
    return !nodes.empty();
  }

private:
  queue<TreeNode *> nodes;
  void collect(TreeNode *node)
  {
    if (node == nullptr)
    {
      return;
    }

    collect(node->left);
    nodes.push(node);
    collect(node->right);
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
  auto tree1 = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
  auto bstIterator1 = new BSTIterator(tree1);

  auto result1 = bstIterator1->next();
  auto result2 = bstIterator1->next();
  auto result3 = bstIterator1->hasNext();
  auto result4 = bstIterator1->next();
  auto result5 = bstIterator1->hasNext();
  auto result6 = bstIterator1->next();
  auto result7 = bstIterator1->hasNext();
  auto result8 = bstIterator1->next();
  auto result9 = bstIterator1->hasNext();
}