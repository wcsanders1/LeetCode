// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2026-09-10
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

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
  int averageOfSubtree(TreeNode *root)
  {
    return getAnswer(root)[2];
  }

private:
  vector<int> getAnswer(TreeNode *node)
  {
    vector<int> res{node->val, 1, 0};
    if (node->left == nullptr && node->right == nullptr)
    {
      res[2] = 1;
      return res;
    }

    if (node->left != nullptr)
    {
      auto left = getAnswer(node->left);
      res[0] += left[0];
      res[1] += left[1];
      res[2] += left[2];
    }

    if (node->right != nullptr)
    {
      auto right = getAnswer(node->right);
      res[0] += right[0];
      res[1] += right[1];
      res[2] += right[2];
    }

    if (res[0] / res[1] == node->val)
    {
      res[2]++;
    }

    return res;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.averageOfSubtree(new TreeNode(4, new TreeNode(8, new TreeNode(0), new TreeNode(1)), new TreeNode(5, nullptr, new TreeNode(6))));
  int result2 = solution.averageOfSubtree(new TreeNode(1));
  int result3 = solution.averageOfSubtree(new TreeNode(1, nullptr, new TreeNode(3, nullptr, new TreeNode(1, nullptr, new TreeNode(3)))));
}