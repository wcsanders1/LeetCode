// https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29
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
  bool isEvenOddTree(TreeNode *root)
  {
    bool isEven = true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int cur = isEven ? 0 : INT32_MAX;
      int count = q.size();
      while (count-- > 0)
      {
        auto node = q.front();
        q.pop();

        if (isEven)
        {
          if ((node->val % 2) == 0 || node->val <= cur)
          {
            return false;
          }
        }
        else
        {
          if ((node->val % 2) == 1 || node->val >= cur)
          {
            return false;
          }
        }

        cur = node->val;

        if (node->left != nullptr)
        {
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
      isEven = !isEven;
    }
    return true;
  }
};