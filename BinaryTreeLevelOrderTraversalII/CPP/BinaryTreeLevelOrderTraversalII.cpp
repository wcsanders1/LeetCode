// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
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
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> answer;
    queue<TreeNode *> q;
    if (root != nullptr)
    {
      q.push(root);
    }

    while (!q.empty())
    {
      int n = q.size();
      vector<int> nodes;
      while (n-- > 0)
      {
        auto next = q.front();
        q.pop();
        nodes.push_back(next->val);
        if (next->left != nullptr)
        {
          q.push(next->left);
        }
        if (next->right != nullptr)
        {
          q.push(next->right);
        }
      }
      answer.push_back(nodes);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.levelOrderBottom(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
}