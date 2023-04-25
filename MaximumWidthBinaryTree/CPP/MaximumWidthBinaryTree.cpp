// https://leetcode.com/problems/maximum-width-of-binary-tree/
// NOT MINE: https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/1802311/c-bfs-easy-to-understand-full-explanation/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

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
  int widthOfBinaryTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    root->val = 1;
    int answer = 1;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      int start = q.front()->val;
      int end = q.back()->val;

      answer = max(answer, end - start + 1);

      for (int i = 0; i < n; i++)
      {
        auto node = q.front();
        q.pop();

        int idx = node->val - start;

        if (node->left != nullptr)
        {
          node->left->val = 2 * idx + 1;
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          node->right->val = 2 * idx + 2;
          q.push(node->right);
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.widthOfBinaryTree(new TreeNode(1, new TreeNode(3, new TreeNode(5), new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(9))));
  int result2 = solution.widthOfBinaryTree(new TreeNode(1, new TreeNode(3, new TreeNode(5, new TreeNode(6), nullptr), nullptr), new TreeNode(2, nullptr, new TreeNode(9, new TreeNode(7), nullptr))));
}