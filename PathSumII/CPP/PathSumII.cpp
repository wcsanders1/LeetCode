// https://leetcode.com/problems/path-sum-ii/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> paths;
    if (root == nullptr)
    {
      return paths;
    }
    getPaths(root, paths, targetSum, root->val);
    vector<vector<int>> answer;
    for (auto &path : paths)
    {
      reverse(path.begin(), path.end());
      answer.push_back(path);
    }
    return answer;
  }

private:
  unordered_set<int> *getPaths(TreeNode *node, vector<vector<int>> &paths, int targetSum, int curSum)
  {
    unordered_set<int> *indexes = new unordered_set<int>();
    if (node->left == nullptr && node->right == nullptr)
    {
      vector<int> path;
      if (targetSum == curSum)
      {
        path.push_back(node->val);
        paths.push_back(path);
        indexes->insert(paths.size() - 1);
      }
      return indexes;
    }

    if (node->left != nullptr)
    {
      auto newIndexes = getPaths(node->left, paths, targetSum, curSum + node->left->val);
      for (int i : *newIndexes)
      {
        indexes->insert(i);
      }
    }

    if (node->right != nullptr)
    {
      auto newIndexes = getPaths(node->right, paths, targetSum, curSum + node->right->val);
      for (int i : *newIndexes)
      {
        indexes->insert(i);
      }
    }

    for (int i : *indexes)
    {
      paths[i].push_back(node->val);
    }

    return indexes;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.pathSum(new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1)))), 22);
  auto result2 = solution.pathSum(new TreeNode(-2, new TreeNode(-3), nullptr), -5);
}