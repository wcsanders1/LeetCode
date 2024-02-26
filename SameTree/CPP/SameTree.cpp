// https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if ((p != nullptr && q != nullptr) && p->val == q->val)
    {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    if (p == nullptr && q == nullptr)
    {
      return true;
    }

    return false;
  }
};