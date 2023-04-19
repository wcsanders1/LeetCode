// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

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

enum class Direction
{
  right,
  left,
};

class Solution
{
public:
  int longestZigZag(TreeNode *root)
  {
    return max(getLongest(root->left, Direction::left, 0), getLongest(root->right, Direction::right, 0));
  }

private:
  int getLongest(TreeNode *node, Direction direction, int currentTotal)
  {
    if (node == nullptr)
    {
      return currentTotal;
    }

    int leftMax = getLongest(node->left, Direction::left, direction == Direction::right ? currentTotal + 1 : 0);
    int rightMax = getLongest(node->right, Direction::right, direction == Direction::left ? currentTotal + 1 : 0);

    return max(leftMax, rightMax);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestZigZag(new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(1), new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1, nullptr, new TreeNode(1))), new TreeNode(1)))));
  int result2 = solution.longestZigZag(new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1)), new TreeNode(1))), new TreeNode(1)));
}