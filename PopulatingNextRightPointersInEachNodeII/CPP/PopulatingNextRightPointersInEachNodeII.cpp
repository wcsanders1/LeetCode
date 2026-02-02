// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (root == nullptr)
    {
      return root;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      int n = q.size();
      Node *prev = nullptr;
      while (n-- > 0)
      {
        auto cur = q.front();
        q.pop();
        if (prev != nullptr)
        {
          prev->next = cur;
        }
        prev = cur;
        if (cur->left != nullptr)
        {
          q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
          q.push(cur->right);
        }
      }
    }
    return root;
  }
};