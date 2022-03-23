// https://leetcode.com/problems/linked-list-in-binary-tree/
#include <vector>
#include <string>

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
    return isSubPath(head, root, head);
  }

private:
  bool isSubPath(ListNode *head, TreeNode *root, ListNode *listRoot)
  {
    if (head == nullptr)
    {
      return true;
    }

    if (root == nullptr)
    {
      return false;
    }

    ListNode *next;
    if (root->val == head->val)
    {
      next = head->next;
    }
    else if (root->val == listRoot->val)
    {
      next = listRoot->next;
    }
    else
    {
      next = listRoot;
    }

    return isSubPath(next, root->left, listRoot) || isSubPath(next, root->right, listRoot);
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
}