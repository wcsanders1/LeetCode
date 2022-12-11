// https://leetcode.com/problems/recover-binary-search-tree/description/
#include <queue>
#include <vector>

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
  void recoverTree(TreeNode *root)
  {
    vector<TreeNode *> mismatches;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int count = q.size();

      while (count-- > 0)
      {
        TreeNode *current = q.front();
        q.pop();

        TreeNode *left = checkMax(current->left, current->val);
        TreeNode *right = checkMin(current->right, current->val);

        if (left != nullptr)
        {
          mismatches.push_back(left);
          mismatches.push_back(current);
        }
        else if (current->left != nullptr)
        {
          q.emplace(current->left);
        }

        if (right != nullptr)
        {
          mismatches.push_back(current);
          mismatches.push_back(right);
        }
        else if (current->right != nullptr)
        {
          q.emplace(current->right);
        }
      }
    }

    int t = mismatches[0]->val;
    mismatches[0]->val = mismatches[mismatches.size() - 1]->val;
    mismatches[mismatches.size() - 1]->val = t;
  }

private:
  TreeNode *checkMax(TreeNode *node, int max, TreeNode *target = nullptr)
  {
    if (node == nullptr)
    {
      return target;
    }

    if (node->val > max)
    {
      target = node;
    }

    TreeNode *left = checkMax(node->left, max, target);
    if (left != nullptr)
    {
      target = left;
    }

    return checkMax(node->right, max, target);
  }

  TreeNode *checkMin(TreeNode *node, int min, TreeNode *target = nullptr)
  {
    if (node == nullptr)
    {
      return target;
    }

    if (node->val < min)
    {
      target = node;
    }

    TreeNode *left = checkMin(node->left, min, target);
    if (left != nullptr)
    {
      target = left;
    }

    return checkMin(node->right, min, target);
  }
};

int main()
{
  Solution solution;

  TreeNode *tree1 = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
  solution.recoverTree(tree1);

  TreeNode *tree2 = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), nullptr));
  solution.recoverTree(tree2);

  TreeNode *tree3 = new TreeNode(2, new TreeNode(3), new TreeNode(1));
  solution.recoverTree(tree3);
}