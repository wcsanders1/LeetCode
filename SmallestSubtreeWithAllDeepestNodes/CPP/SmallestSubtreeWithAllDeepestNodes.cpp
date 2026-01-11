// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

// Definition for a binary tree node.
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
  TreeNode *subtreeWithAllDeepest(TreeNode *root)
  {
    unordered_map<int, int> greatestDepth;
    findGreatestDepths(root, greatestDepth);

    TreeNode *answer = root;
    int greatest = greatestDepth[root->val];
    for (int i = 1; i <= greatest; i++)
    {
      auto lft = answer->left;
      auto rgt = answer->right;
      if (lft == nullptr && rgt == nullptr)
      {
        return answer;
      }
      else if (lft == nullptr)
      {
        answer = rgt;
      }
      else if (rgt == nullptr)
      {
        answer = lft;
      }
      else if (greatestDepth[lft->val] == greatestDepth[rgt->val])
      {
        return answer;
      }
      else
      {
        answer = greatestDepth[lft->val] > greatestDepth[rgt->val] ? lft : rgt;
      }
    }

    return answer;
  }

private:
  int findGreatestDepths(TreeNode *node, unordered_map<int, int> &greatestDepth, int currentDepth = 1)
  {
    if (node == nullptr)
    {
      return currentDepth - 1;
    }

    int greatest = max(findGreatestDepths(node->left, greatestDepth, currentDepth + 1), findGreatestDepths(node->right, greatestDepth, currentDepth + 1));
    greatestDepth[node->val] = greatest;
    return greatest;
  }
};

int main()
{
  Solution solution;
  TreeNode *result1 = solution.subtreeWithAllDeepest(new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))), new TreeNode(1, new TreeNode(0), new TreeNode(8))));
  TreeNode *result2 = solution.subtreeWithAllDeepest(new TreeNode(1));
}