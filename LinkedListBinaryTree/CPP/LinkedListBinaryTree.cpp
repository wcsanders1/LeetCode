// https://leetcode.com/problems/linked-list-in-binary-tree/
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  bool isSubPath(ListNode *head, TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();

      if (dfs(head, node))
      {
        return true;
      }
      if (node->left != nullptr)
      {
        q.emplace(node->left);
      }
      if (node->right != nullptr)
      {
        q.emplace(node->right);
      }
    }

    return false;
  }

private:
  bool dfs(ListNode *head, TreeNode *root)
  {
    if (head == nullptr)
    {
      return true;
    }

    if (root == nullptr || root->val != head->val)
    {
      return false;
    }

    return dfs(head->next, root->left) || dfs(head->next, root->right);
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isSubPath(new ListNode(4, new ListNode(2, new ListNode(8))),
                                    new TreeNode(1,
                                                 new TreeNode(4,
                                                              nullptr, new TreeNode(2, new TreeNode(1), nullptr)),
                                                 new TreeNode(4,
                                                              new TreeNode(2,
                                                                           new TreeNode(6),
                                                                           new TreeNode(8,
                                                                                        new TreeNode(1), new TreeNode(3))),
                                                              nullptr)));

  bool result2 = solution.isSubPath(new ListNode(1, new ListNode(10)),
                                    new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(10, new TreeNode(9), nullptr), new TreeNode(1))));

  bool result3 = solution.isSubPath(new ListNode(2, new ListNode(2, new ListNode(1))),
                                    new TreeNode(2, nullptr, new TreeNode(2, nullptr, new TreeNode(2, nullptr, new TreeNode(1)))));
}