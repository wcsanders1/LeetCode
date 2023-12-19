// https://leetcode.com/problems/find-mode-in-binary-search-tree/?envType=daily-question&envId=2023-11-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

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
  vector<int> findMode(TreeNode *root)
  {
    set<int> s;
    dfs(s, root);
    vector<int> answer;
    for (int i : s)
    {
      answer.push_back(i);
    }

    return answer;
  }

private:
  int dfs(set<int> &answer, TreeNode *node, int curMax = 0)
  {
    if (node == nullptr)
    {
      return curMax;
    }

    int sameCount = getValueCount(node, node->val);
    if (sameCount > curMax)
    {
      answer.clear();
      answer.insert(node->val);
    }
    else if (sameCount == curMax)
    {
      answer.insert(node->val);
    }

    int newMax = max(curMax, sameCount);
    newMax = max(dfs(answer, node->left, newMax), newMax);
    newMax = max(dfs(answer, node->right, newMax), newMax);

    return newMax;
  }

  int getValueCount(TreeNode *node, int value)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int count = node->val == value ? 1 : 0;

    if (node->left != nullptr && node->val >= value)
    {
      count += getValueCount(node->left, value);
    }

    if (node->right != nullptr && node->val <= value)
    {
      count += getValueCount(node->right, value);
    }

    return count;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findMode(new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(2), nullptr)));
  auto result2 = solution.findMode(new TreeNode(0));
  auto result3 = solution.findMode(new TreeNode(1, nullptr, new TreeNode(2)));
}