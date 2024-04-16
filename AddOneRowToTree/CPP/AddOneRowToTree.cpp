// https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
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
  TreeNode *addOneRow(TreeNode *root, int val, int depth)
  {
    if (depth == 1)
    {
      return new TreeNode(val, root, nullptr);
    }

    queue<TreeNode *> q;
    q.push(root);
    int cur = 2;
    while (!q.empty())
    {
      int count = q.size();
      if (cur++ == depth)
      {
        while (count-- > 0)
        {
          auto node = q.front();
          q.pop();
          auto left = node->left;
          auto right = node->right;
          node->left = new TreeNode(val, left, nullptr);
          node->right = new TreeNode(val, nullptr, right);
        }
        return root;
      }

      while (count-- > 0)
      {
        auto n = q.front();
        q.pop();
        if (n->left != nullptr)
        {
          q.push(n->left);
        }

        if (n->right != nullptr)
        {
          q.push(n->right);
        }
      }
    }

    return root;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.addOneRow(new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(1)), new TreeNode(6, new TreeNode(5), nullptr)), 1, 2);
}