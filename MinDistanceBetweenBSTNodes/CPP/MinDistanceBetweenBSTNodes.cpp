// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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
  int minDiffInBST(TreeNode *root)
  {
    queue<TreeNode *> q;
    priority_queue<int> pq;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      while (n-- > 0)
      {
        auto node = q.front();
        q.pop();
        pq.push(node->val);

        if (node->left != nullptr)
        {
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
    }

    int answer = INT32_MAX;
    int last = pq.top();
    pq.pop();
    while (!pq.empty())
    {
      auto next = pq.top();
      pq.pop();
      answer = min(answer, abs(last - next));
      last = next;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minDiffInBST(
      new TreeNode(4,
                   new TreeNode(2,
                                new TreeNode(1), new TreeNode(3)),
                   new TreeNode(6)));
}