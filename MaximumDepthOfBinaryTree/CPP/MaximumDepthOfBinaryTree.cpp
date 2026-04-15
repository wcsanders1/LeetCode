// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
  int maxDepth(TreeNode *root)
  {
    int levels = 0;
    queue<TreeNode *> q;
    if (root != nullptr)
    {
      q.push(root);
    }

    while (!q.empty())
    {
      levels++;
      int num = q.size();
      while (num-- > 0)
      {
        auto next = q.front();
        q.pop();
        if (next->left != nullptr)
        {
          q.push(next->left);
        }
        if (next->right != nullptr)
        {
          q.push(next->right);
        }
      }
    }

    return levels;
  }
};