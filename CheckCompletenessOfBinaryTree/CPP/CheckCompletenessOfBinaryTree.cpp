// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

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
  bool isCompleteTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return true;
    }

    queue<TreeNode *> q;
    q.push(root);

    bool mustBeNull = false;
    while (!q.empty())
    {
      int n = q.size();
      while (n-- > 0)
      {
        auto next = q.front();
        q.pop();

        if (next->left != nullptr)
        {
          if (mustBeNull)
          {
            return false;
          }
          q.push(next->left);
        }
        else
        {
          mustBeNull = true;
        }

        if (next->right != nullptr)
        {
          if (mustBeNull)
          {
            return false;
          }
          q.push(next->right);
        }
        else
        {
          mustBeNull = true;
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isCompleteTree(new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr)));
  bool result2 = solution.isCompleteTree(new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(7))));
}