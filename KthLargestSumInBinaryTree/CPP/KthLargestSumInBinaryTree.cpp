#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
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
  long long kthLargestLevelSum(TreeNode *root, int k)
  {
    priority_queue<long long> pq;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      long long sum = 0;
      for (int i = 0; i < n; i++)
      {
        auto node = q.front();
        q.pop();

        if (node->left != nullptr)
        {
          q.push(node->left);
        }

        if (node->right != nullptr)
        {
          q.push(node->right);
        }

        sum += node->val;
      }

      pq.push(sum);
    }

    if (pq.size() < k)
    {
      return -1;
    }

    while (k-- > 1)
    {
      pq.pop();
    }

    return pq.top();
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.kthLargestLevelSum(
      new TreeNode(5,
                   new TreeNode(8,
                                new TreeNode(2, new TreeNode(4), new TreeNode(6)),
                                new TreeNode(1)),
                   new TreeNode(9, new TreeNode(3), new TreeNode(7))),
      4);
}