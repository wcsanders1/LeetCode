// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
#include <vector>
#include <unordered_set>
#include <queue>

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
  int maxLevelSum(TreeNode *root)
  {
    int answer = 0;
    int maxSum = INT32_MIN;
    int curLevel = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      int curSum = 0;
      curLevel++;

      while (n-- > 0)
      {
        auto node = q.front();
        q.pop();

        curSum += node->val;
        if (node->left != nullptr)
        {
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }

      if (curSum > maxSum)
      {
        maxSum = curSum;
        answer = curLevel;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxLevelSum(new TreeNode(1, new TreeNode(7, new TreeNode(7), new TreeNode(-8)), new TreeNode(0)));
}