// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
#include <vector>
#include <unordered_set>
#include <queue>
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
  int amountOfTime(TreeNode *root, int start)
  {
    unordered_map<int, vector<int>> m;
    if (root->left != nullptr)
    {
      m[root->val].push_back(root->left->val);
    }
    if (root->right != nullptr)
    {
      m[root->val].push_back(root->right->val);
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      auto n = q.front();
      q.pop();
      if (n->left != nullptr)
      {
        q.push(n->left);
        m[n->left->val].push_back(n->val);
        if (n->left->left != nullptr)
        {
          m[n->left->val].push_back(n->left->left->val);
        }
        if (n->left->right != nullptr)
        {
          m[n->left->val].push_back(n->left->right->val);
        }
      }

      if (n->right != nullptr)
      {
        q.push(n->right);
        m[n->right->val].push_back(n->val);
        if (n->right->left != nullptr)
        {
          m[n->right->val].push_back(n->right->left->val);
        }
        if (n->right->right != nullptr)
        {
          m[n->right->val].push_back(n->right->right->val);
        }
      }
    }

    unordered_set<int> visited;
    queue<int> q2;
    q2.push(start);
    visited.insert(start);
    int answer = 0;
    while (!q2.empty())
    {
      answer++;
      int cnt = q2.size();
      while (cnt-- > 0)
      {
        int nxt = q2.front();
        q2.pop();
        for (int child : m[nxt])
        {
          if (visited.count(child) == 0)
          {
            visited.insert(child);
            q2.push(child);
          }
        }
      }
    }

    return answer - 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.amountOfTime(
      new TreeNode(1,
                   new TreeNode(5, nullptr,
                                new TreeNode(4, new TreeNode(9), new TreeNode(2))),
                   new TreeNode(3, new TreeNode(10), new TreeNode(6))),
      3);
}