// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> values;
    queue<TreeNode *> q;
    if (root != nullptr)
    {
      q.push(root);
    }

    while (!q.empty())
    {
      int count = q.size();
      vector<int> vals;
      while (count-- > 0)
      {
        auto next = q.front();
        q.pop();
        vals.push_back(next->val);
        if (next->left != nullptr)
        {
          q.push(next->left);
        }
        if (next->right != nullptr)
        {
          q.push(next->right);
        }
      }
      values.push_back(vals);
    }

    return values;
  }
};