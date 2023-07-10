// https://leetcode.com/problems/minimum-depth-of-binary-tree/
#include <vector>
#include <unordered_set>
#include <queue>

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
  int minDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    int answer = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      answer++;
      int count = q.size();
      while (count-- > 0)
      {
        auto node = q.front();
        q.pop();

        if (node->left == nullptr && node->right == nullptr)
        {
          return answer;
        }

        if (node->left != nullptr)
        {
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
    }

    return answer;
  }
};