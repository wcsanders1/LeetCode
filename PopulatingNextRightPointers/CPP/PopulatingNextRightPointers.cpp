// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <vector>
#include <queue>

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
    if (root == NULL)
    {
      return root;
    }

    queue<Node *> q;
    Node *current = nullptr;
    q.emplace(root);

    while (!q.empty())
    {
      current = q.front();
      q.pop();

      int count = q.size();
      if (current->left != NULL)
      {
        q.emplace(current->left);
      }

      if (current->right != NULL)
      {
        q.emplace(current->right);
      }

      for (int i = 0; i < count; i++)
      {
        Node *n = q.front();
        q.pop();

        current->next = n;
        current = n;

        if (current->left != NULL)
        {
          q.emplace(current->left);
        }

        if (current->right != NULL)
        {
          q.emplace(current->right);
        }
      }
    }

    return root;
  }
};

// above is a bad solution because it takes O(N) memory; this takes N(1):
// void connect(TreeLinkNode *root) {
//     if(!root)
//         return;
//     while(root -> left)
//     {
//         TreeLinkNode *p = root;
//         while(p)
//         {
//             p -> left -> next = p -> right;
//             if(p -> next)
//                 p -> right -> next = p -> next -> left;
//             p = p -> next;
//         }
//         root = root -> left;
//     }
// }