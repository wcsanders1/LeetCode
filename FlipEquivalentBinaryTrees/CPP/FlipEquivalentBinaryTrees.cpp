// https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
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
  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;

    if (root1 != nullptr)
    {
      q1.push(root1);
    }

    if (root2 != nullptr)
    {
      q2.push(root2);
    }

    while (!q1.empty() || !q2.empty())
    {
      if (q1.size() != q2.size())
      {
        return false;
      }

      unordered_map<int, TreeNode *> m1;
      unordered_map<int, TreeNode *> m2;
      int count = q1.size();
      while (count-- > 0)
      {
        m1[q1.front()->val] = q1.front();
        m2[q2.front()->val] = q2.front();
        if (q1.front()->left != nullptr)
        {
          q1.push(q1.front()->left);
        }
        if (q1.front()->right != nullptr)
        {
          q1.push(q1.front()->right);
        }
        if (q2.front()->left != nullptr)
        {
          q2.push(q2.front()->left);
        }
        if (q2.front()->right != nullptr)
        {
          q2.push(q2.front()->right);
        }
        q1.pop();
        q2.pop();
      }

      if (m1.size() != m2.size())
      {
        return false;
      }

      for (auto &[val, node1] : m1)
      {
        if (m2.count(val) == 0)
        {
          return false;
        }

        auto node2 = m2[val];
        unordered_set<int> s1;
        unordered_set<int> s2;
        if (node1->left != nullptr)
        {
          s1.insert(node1->left->val);
        }
        if (node1->right != nullptr)
        {
          s1.insert(node1->right->val);
        }
        if (node2->left != nullptr)
        {
          s2.insert(node2->left->val);
        }
        if (node2->right != nullptr)
        {
          s2.insert(node2->right->val);
        }

        if (s1.size() != s2.size())
        {
          return false;
        }

        for (int i : s1)
        {
          if (s2.count(i) == 0)
          {
            return false;
          }
          s2.erase(i);
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.flipEquiv(new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(7), new TreeNode(8))), new TreeNode(3, new TreeNode(6), nullptr)),
                                    new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(6)), new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(8), new TreeNode(7)))));
  bool result2 = solution.flipEquiv(nullptr, nullptr);
  bool result3 = solution.flipEquiv(nullptr, new TreeNode(1));
}